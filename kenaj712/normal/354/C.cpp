#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int pocz[1000005];
int kon[1000005];
int licz[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,k,mini=1e9;
    cin>>a>>k;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        mini=min(mini,tab[x]);
    }
    if(mini<=k+1)
    {
        cout<<mini;
        return 0;
    }
    int maks=k+1,zlicz=0;
    for(int x=1;x<=a;x++)
    {
        kon[tab[x]]++;
        pocz[tab[x]-k]++;
    }
    for(int x=1;x<=1e6;x++)
    {
        zlicz+=pocz[x];
        licz[x]=zlicz;
        zlicz-=kon[x];
    }
    for(int x=k+2;x<=1e6;x++)
    {
        zlicz=0;
        for(int y=x;y<=1e6;y+=x)
            zlicz+=licz[y];
        if(zlicz==a)
            maks=x;
    }
    cout<<maks;
	return 0;
}