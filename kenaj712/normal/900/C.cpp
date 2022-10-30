#include<bits/stdc++.h>
using namespace std;
int tab[100005];
int czy_ok[100005];
int licz[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b=0,c=0;
	cin>>a;
	for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        if(tab[x]>c)
        {
            b=c;
            c=tab[x];
            czy_ok[tab[x]]=1;
        }
        else if(tab[x]<c&&tab[x]>b)
        {
            b=tab[x];
            licz[c]++;
        }
    }
    int liczba=1,maks=-1;
    for(int x=1;x<=a;x++)
        if(licz[x]-czy_ok[x]>maks)
        {
            maks=licz[x]-czy_ok[x];
            liczba=x;
        }
    cout<<liczba;
	return 0;
}