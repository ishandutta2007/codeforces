#include<bits/stdc++.h>
using namespace std;
long long tab[505][505];
set<long long> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    if(a==1)
    {
        cout<<1;
        return 0;
    }
    int pom1,pom2;
    for(int x=0;x<a;x++)
        for(int y=0;y<a;y++)
        {
            cin>>tab[x][y];
            if(tab[x][y]==0)
            {
                pom1=x;
                pom2=y;
            }
        }
    if(pom1==0)
    {
       pom1=1;
       pom2=0;
    }
    else
    {
        pom2=pom1;
        pom1=0;
    }
    long long suma=0;
    for(int x=0;x<a;x++)
        suma+=tab[pom1][x];
    for(int x=0;x<a;x++)
        suma-=tab[pom2][x];
    for(int x=0;x<a;x++)
        for(int y=0;y<a;y++)
            if(tab[x][y]==0)
                tab[x][y]=suma;
    long long out=suma;
    suma=0;
    for(int x=0;x<a;x++)
    {
        suma=0;
        for(int y=0;y<a;y++)
            suma+=tab[x][y];
        s.insert(suma);
    }
    for(int x=0;x<a;x++)
    {
        suma=0;
        for(int y=0;y<a;y++)
            suma+=tab[x][y];
        s.insert(suma);
    }
    for(int x=0;x<a;x++)
    {
        suma=0;
        for(int y=0;y<a;y++)
            suma+=tab[y][x];
        s.insert(suma);
    }
    suma=0;
    for(int x=0;x<a;x++)
        suma+=tab[x][x];
    s.insert(suma);
    suma=0;
    for(int x=0;x<a;x++)
        suma+=tab[x][a-x-1];
    s.insert(suma);
    if(s.size()==1&&out>0)
        cout<<out;
    else
        cout<<-1;
	return 0;
}