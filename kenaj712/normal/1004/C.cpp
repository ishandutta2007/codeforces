#include<bits/stdc++.h>
using namespace std;
int tab[100005];
int licz2[100005];
bool odw[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    long long licz=0,ile=0;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        if(licz2[tab[x]]==0)
            ile++;
        licz2[tab[x]]++;
    }
    for(int x=0;x<a;x++)
    {
        licz2[tab[x]]--;
        if(licz2[tab[x]]==0)
            ile--;
        if(odw[tab[x]]==false)
        {
            licz+=ile;
            odw[tab[x]]=true;
        }
        //cout<<licz<<'\n';
    }
    cout<<licz;
	return 0;
}