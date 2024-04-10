#include<bits/stdc++.h>
using namespace std;
int odw[1000005];
bool odw2[1000005];
set<int> s;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    long long licz=0;
    for(int x=1;x<=b;x++)
        cin>>tab[x];
    for(int x=b;x>=1;x--)
    {
        odw2[tab[x]]=true;
        odw[tab[x]]=odw2[tab[x]-1]+odw2[tab[x]+1]+odw2[tab[x]];
    }
    for(int x=1;x<=a;x++)
        licz+=odw[x];
    cout<<3*a-2-licz;
	return 0;
}