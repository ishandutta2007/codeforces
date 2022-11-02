#include<bits/stdc++.h>
using namespace std;
string tab[6][2];
bool odw[6];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    tab[0][0]="Power";
    tab[0][1]="purple";
    tab[1][0]="Time";
    tab[1][1]="green";
     tab[2][0]="Space";
     tab[2][1]="blue";
     tab[3][0]="Soul";
     tab[3][1]="orange";
     tab[4][0]="Reality";
     tab[4][1]="red";
     tab[5][0]="Mind";
     tab[5][1]="yellow";
     int a;
     cin>>a;
     string b;
     for(int t=0;t<a;t++)
     {
         cin>>b;
         for(int x=0;x<6;x++)
            if(tab[x][1]==b)
                odw[x]=true;
     }
     cout<<6-a<<'\n';
     for(int x=0;x<6;x++)
        if(odw[x]==false)
            cout<<tab[x][0]<<'\n';
	return 0;
}