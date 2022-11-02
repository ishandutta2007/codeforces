#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int licz=0;
    int out=0;
    for(int x=1;x<a;x++)
    {
        if(tab[x])
            licz++;
        else if(licz)
        {
            out+=licz/3;
            licz=0;
        }
    }
    out+=licz/3;
    cout<<out+tab[0]<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}