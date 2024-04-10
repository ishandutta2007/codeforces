#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int licz[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,t;
    cin>>a>>t;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        licz[tab[x]]++;
    }
    while(t--)
    {
        int siema;
        cin>>siema;
        int x;
        cin>>x;
        if(siema == 1)
        {
            licz[tab[x]]--;
            licz[1-tab[x]]++;
            tab[x] = 1-tab[x];
        }
        else
        {
            if(licz[1]>=x)
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
    }
	return 0;
}