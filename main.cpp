#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

using namespace std;
int ruch=1;
void sterowanie(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void wyswietl(string tab[3][3])
{
    cout << "\n\t\t\t\t\t\t  Kolko i krzyzyk\n";
    cout << "\t\t\t\t\t\t-------------------\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t|  " << tab[0][0] << "  |  " << tab[0][1] << "  |  " << tab[0][2] << "  |\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t-------------------\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t|  " << tab[1][0] << "  |  " << tab[1][1] << "  |  " << tab[1][2] << "  |\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t-------------------\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t|  " << tab[2][0] << "  |  " << tab[2][1] << "  |  " << tab[2][2] << "  |\n";
	cout << "\t\t\t\t\t\t|     |     |     |\n";
	cout << "\t\t\t\t\t\t-------------------";
}
void zamiana(int a, int b,string tab[3][3], string znak)
{int c; string figura;
if(a==51 && b==4) c=1;
if(a==57 && b==4) c=2;
if(a==63 && b==4) c=3;
if(a==51 && b==8) c=4;
if(a==51 && b==12) c=5;
if(a==57 && b==8) c=6;
if(a==57 && b==12) c=7;
if(a==63 && b==8) c=8;
if(a==63 && b==12) c=9;
    switch (c)
    {

                case 1:  if(tab[0][0]==" ")tab[0][0]=znak;else ruch--;figura=tab[0][0];cout<<figura;break;
                case 2:  if(tab[0][1]==" ")tab[0][1]=znak;else ruch--;figura=tab[0][1];cout<<figura;break;
                case 3:  if(tab[0][2]==" ")tab[0][2]=znak;else ruch--;figura=tab[0][2];cout<<figura;break;
                case 4:  if(tab[1][0]==" ")tab[1][0]=znak;else ruch--;figura=tab[1][0];cout<<figura;break;
                case 5:  if(tab[2][0]==" ")tab[2][0]=znak;else ruch--;figura=tab[2][0];cout<<figura;break;
                case 6:  if(tab[1][1]==" ")tab[1][1]=znak;else ruch--;figura=tab[1][1];cout<<figura;break;
                case 7:  if(tab[2][1]==" ")tab[2][1]=znak;else ruch--;figura=tab[2][1];cout<<figura;break;
                case 8:  if(tab[1][2]==" ")tab[1][2]=znak;else ruch--;figura=tab[1][2];cout<<figura;break;
                case 9:  if(tab[2][2]==" ")tab[2][2]=znak;else ruch--;figura=tab[2][2];cout<<figura;break;

    }

}

int sprawdzenie(string b[3][3],string zPc,string zGr)
{
    for (int i = 0; i<3; i++)
    {
        if (b[i][0]==b[i][1] && b[i][1]==b[i][2])
        {
            if (b[i][0]==zPc)
               return +10;
            else if (b[i][0]==zGr)
               return -10;
        }
    }
    for (int i = 0; i<3; i++)
    {
        if (b[0][i]==b[1][i] && b[1][i]==b[2][i])
        {
            if (b[0][i]==zPc)
                return +10;
            else if (b[0][i]==zGr)
                return -10;
        }
    }

    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==zPc)
            return +10;
        else if (b[0][0]==zGr)
            return -10;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==zPc)
            return +10;
        else if (b[0][2]==zGr)
            return -10;
    }
    return 0;
}

bool koniecRuchow(string tab[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (tab[i][j]==" ")
                return true;
    return false;
}

struct Ruch
{
    int wiersz, kolumna;
};

int minimax(string tab[3][3], int ruch, bool komp,string zPc,string zGr)
{
    int wynik = sprawdzenie(tab,zPc,zGr);
    if (wynik == 10)
        return wynik;
    if (wynik == -10)
        return wynik;
    if (koniecRuchow(tab)==false)
        return 0;
    if (komp)
    {
        int naj = -11111;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (tab[i][j]==" ")
                {
                    tab[i][j] = zPc;
                    naj = max( naj,
                        minimax(tab, ruch+1, !komp, zPc, zGr)-ruch );
                    tab[i][j] = " ";
                }
            }
        }
        return naj;
    }
    else
    {
        int naj = 99999;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (tab[i][j]==" ")
                {
                    tab[i][j] = zGr;
                    naj = min(naj,
                           minimax(tab, ruch+1, !komp, zPc,zGr)+ruch);
                    tab[i][j] = " ";
                }
            }
        }
        return naj;
    }
}

Ruch znajdzNaj(string tab[3][3], string zPc, string zGr)
{
    int najlWart = -99999;
    Ruch najlRuch;
    najlRuch.wiersz = -1;
    najlRuch.kolumna = -1;


    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (tab[i][j]==" ")
            {
                tab[i][j] = zPc;
                int aktuWart = minimax(tab, 0, false, zPc , zGr);
                tab[i][j] = " ";
                if (aktuWart > najlWart)
                {
                    najlRuch.wiersz = i;
                    najlRuch.kolumna = j;
                    najlWart = aktuWart;
                }
            }
        }
    }
    return najlRuch;
}

int main()

{
    start:;
    ruch=1;
	string tablica[3][3];
	string zpi, zdr,zakt,zgr;
    char odNowa;
    int zmSprZnak=1;

	for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        tablica[i][j]=" ";
    }
	int x = 0;
	int y = 1;
	int klaw;

system( "cls" );
sterowanie(42,2);
	cout<<"W jaka wersje gry chcesz zagrac?\n\t\t\t\t\t1.PVP\n\t\t\t\t\t2.PVE";

x=40;y=3;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 3)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 4)) y=y+1;
		if (klaw==13)
		{
		    if(y==3)goto pvp;
		    else goto pve;
		}

		sterowanie(x, y);

	}




pvp:
system( "cls" );
sterowanie(45,2);
cout << "Jaki znak ma zaczynac?\n\t\t\t\t\t1.X\n\t\t\t\t\t2.O" << endl;
	x=40;y=3;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 3)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 4)) y=y+1;
		if (klaw==13)
		{
		    if(y==3){zpi="X";zdr="O";break;}
		    else {zpi="O";zdr="X";break;}
		}
		sterowanie(x, y);
	}

system ("cls");

x=51;
y=4;
wyswietl(tablica);

	sterowanie(x, y);
	for (;;)
{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 4) || (klaw == 72 &&  y > 4)) y=y-4;
        if ((klaw == 115 && y < 12) || (klaw == 80 && y<12)) y=y+4;
        if ((klaw == 97 && x > 52) || (klaw == 75 && x > 52)) x=x-6;
        if ((klaw == 100 && x < 63) || (klaw == 77 && x < 63)) x=x+6;
		if (klaw==13)
		{if((ruch%2)==1)
                { zakt= zpi;
                zamiana(x,y,tablica,zpi);
                ruch++;
                }
        else {zakt=zdr;
              zamiana(x,y,tablica,zdr);
              ruch++;
             }
		}

		sterowanie(x, y);
 if ((tablica[0][0]!=" " && tablica[0][0]==tablica[1][1] && tablica[0][0]==tablica[2][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[1][1] && tablica[2][0]==tablica[0][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[0][1] && tablica[0][0]==tablica[0][2]) ||
     (tablica[1][0]!=" " && tablica[1][0]==tablica[1][1] && tablica[1][0]==tablica[1][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[2][1] && tablica[2][0]==tablica[2][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[1][0] && tablica[0][0]==tablica[2][0]) ||
     (tablica[0][1]!=" " && tablica[0][1]==tablica[1][1] && tablica[0][1]==tablica[2][1]) ||
     (tablica[0][2]!=" " && tablica[0][2]==tablica[1][2] && tablica[0][2]==tablica[2][2])
     )
     {
        sterowanie(52,16);
        cout << "Wygral/o: "<<zakt<<endl;
        sterowanie(44,17);
        cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
        x=40;y=18;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
    }
     }
   else if(ruch==10)
   {
sterowanie(44,16);
cout << "Remis!!!"<<endl;
sterowanie(44,17);
cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
x=40;y=18;
sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
    }
   }
}

pve:;
system( "cls" );
string zpc;
sterowanie(45,2);
cout << "Jaki znak ma zaczynac?\n\t\t\t\t\t1.X\n\t\t\t\t\t2.O" << endl;
	x=40;y=3;
    sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 3)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 4)) y=y+1;
		if (klaw==13)
		{
		    if(y==3){zpi="X";zdr="O";break;}
		    else {zpi="O";zdr="X";break;}
		}
		sterowanie(x, y);
	}

    system ("cls");

	cout<<"\n\n\t\t\t\t\t\tKto zaczyna?\n\t\t\t\t\t\t1.Komputer\n\t\t\t\t\t\t2.Gracz";


		x=48;y=3;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 3)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 4)) y=y+1;
		if (klaw==13)
		{
		    if(y==3)
           {
               zpc=zpi;
               zgr=zdr;

        system ("cls");
	   x=51;
        y=4;
        wyswietl(tablica);
        sterowanie(x,y);
        ruchk:;
        Ruch najlRuch=znajdzNaj(tablica,zpc,zgr);
            if((ruch%2)==1 && najlRuch.wiersz==0 && najlRuch.kolumna==0){x=51;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==1 && najlRuch.kolumna==0){x=51;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==2 && najlRuch.kolumna==0){x=51;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==0 && najlRuch.kolumna==1){x=57;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==1 && najlRuch.kolumna==1){x=57;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==2 && najlRuch.kolumna==1){x=57;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==0 && najlRuch.kolumna==2){x=63;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==1 && najlRuch.kolumna==2){x=63;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}
            if((ruch%2)==1 && najlRuch.wiersz==2 && najlRuch.kolumna==2){x=63;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie;}

		sterowanie(x, y);
	for (;;)
	{
        klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 4) || (klaw == 72 &&  y > 4)) y=y-4;
        if ((klaw == 115 && y < 12) || (klaw == 80 && y<12)) y=y+4;
        if ((klaw == 97 && x > 52) || (klaw == 75 && x > 52)) x=x-6;
        if ((klaw == 100 && x < 63) || (klaw == 77 && x < 63)) x=x+6;
		if (klaw==13)
		{
		    if((ruch%2)==0)
                {zakt=zgr;
                    zamiana(x,y,tablica,zgr);
                    ruch++;
                    goto sprawdzenie;
                }
		}
		sterowanie(x, y);


sprawdzenie:;

 if ((tablica[0][0]!=" " && tablica[0][0]==tablica[1][1] && tablica[0][0]==tablica[2][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[1][1] && tablica[2][0]==tablica[0][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[0][1] && tablica[0][0]==tablica[0][2]) ||
     (tablica[1][0]!=" " && tablica[1][0]==tablica[1][1] && tablica[1][0]==tablica[1][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[2][1] && tablica[2][0]==tablica[2][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[1][0] && tablica[0][0]==tablica[2][0]) ||
     (tablica[0][1]!=" " && tablica[0][1]==tablica[1][1] && tablica[0][1]==tablica[2][1]) ||
     (tablica[0][2]!=" " && tablica[0][2]==tablica[1][2] && tablica[0][2]==tablica[2][2])
     )
     {

          sterowanie(25,16);
if(zakt==zpc)
cout << "Wygral komputer :/ (Ze znakiem: "<<zakt<<" ) Moze nastepnym razem sie uda? "<<endl;
else cout<< "Wygrales!!!";
sterowanie(44,17);
cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
	x=40;y=18;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
     }
     }



   else if(ruch==10)
   {
sterowanie(44,16);
cout << "Remis!!!"<<endl;
sterowanie(44,17);
cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
x=40;y=18;
sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
    }
   }
    else goto ruchk;
    }
}
    else
        {
        zpc=zdr;
        zgr=zpi;
        system ("cls");
	    x=51;
        y=4;

        wyswietl(tablica);
        sterowanie(x,y);

        klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 4) || (klaw == 72 &&  y > 4)) y=y-4;
        if ((klaw == 115 && y < 12) || (klaw == 80 && y<12)) y=y+4;
        if ((klaw == 97 && x > 52) || (klaw == 75 && x > 52)) x=x-6;
        if ((klaw == 100 && x < 63) || (klaw == 77 && x < 63)) x=x+6;
		if (klaw==13)
		{
		    if((ruch%2)==1)
                {zakt=zgr;
                    zamiana(x,y,tablica,zgr);
                    ruch++;

                }
		}
		ruchkomp:
		    sterowanie(x, y);
            Ruch najlRuch=znajdzNaj(tablica,zpc,zgr);
            if((ruch%2)==0 && najlRuch.wiersz==0 && najlRuch.kolumna==0){x=51;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==1 && najlRuch.kolumna==0){x=51;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==2 && najlRuch.kolumna==0){x=51;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==0 && najlRuch.kolumna==1){x=57;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==1 && najlRuch.kolumna==1){x=57;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==2 && najlRuch.kolumna==1){x=57;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==0 && najlRuch.kolumna==2){x=63;y=4;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==1 && najlRuch.kolumna==2){x=63;y=8;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}
            if((ruch%2)==0 && najlRuch.wiersz==2 && najlRuch.kolumna==2){x=63;y=12;sterowanie(x,y);zamiana(x,y,tablica,zpc);zakt=zpc;ruch++;goto sprawdzenie2;}


		sterowanie(x, y);
	for (;;)
	{

        klaw = getch();
		sterowanie(x, y);

        if ((klaw == 119 && y > 4) || (klaw == 72 &&  y > 4)) y=y-4;
        if ((klaw == 115 && y < 12) || (klaw == 80 && y<12)) y=y+4;
        if ((klaw == 97 && x > 52) || (klaw == 75 && x > 52)) x=x-6;
        if ((klaw == 100 && x < 63) || (klaw == 77 && x < 63)) x=x+6;
		if (klaw==13)
		{
		    if((ruch%2)==1)
                {zakt=zgr;
                    zamiana(x,y,tablica,zgr);
                    ruch++;
                    goto sprawdzenie2;
                }

		}
		sterowanie(x, y);
	}

sprawdzenie2:;

 if ((tablica[0][0]!=" " && tablica[0][0]==tablica[1][1] && tablica[0][0]==tablica[2][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[1][1] && tablica[2][0]==tablica[0][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[0][1] && tablica[0][0]==tablica[0][2]) ||
     (tablica[1][0]!=" " && tablica[1][0]==tablica[1][1] && tablica[1][0]==tablica[1][2]) ||
     (tablica[2][0]!=" " && tablica[2][0]==tablica[2][1] && tablica[2][0]==tablica[2][2]) ||
     (tablica[0][0]!=" " && tablica[0][0]==tablica[1][0] && tablica[0][0]==tablica[2][0]) ||
     (tablica[0][1]!=" " && tablica[0][1]==tablica[1][1] && tablica[0][1]==tablica[2][1]) ||
     (tablica[0][2]!=" " && tablica[0][2]==tablica[1][2] && tablica[0][2]==tablica[2][2])
     ) {

          sterowanie(25,16);
if(zakt==zpc)
cout << "Wygral komputer :/ (Ze znakiem: "<<zakt<<" ) Moze nastepnym razem sie uda? "<<endl;
else cout<< "Wygrales!!!";
sterowanie(44,17);
cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
	x=40;y=18;
		sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
     }

     }
   else if(ruch==10)
   {
sterowanie(44,16);
cout << "Remis!!!"<<endl;
sterowanie(44,17);
cout<<"Chcesz zagrac jeszcze raz?\n\t\t\t\t\t1.Tak\n\t\t\t\t\t2.Nie" << endl;
x=40;y=18;
sterowanie(x, y);
	for (;;)
	{

		klaw = getch();
		sterowanie(x, y);
        if ((klaw == 119 && y > 3) || (klaw == 72 && y > 18)) y=y-1;
        if ((klaw == 115 && y < 4) || (klaw == 80 && y < 19)) y=y+1;
		if (klaw==13)
		{
		    if(y==18)goto start;
		    else return 0;
		}
		sterowanie(x, y);
    }
   }
    else goto ruchkomp;
            }

		}
		sterowanie(x, y);
	}
	system("PAUSE");
}
