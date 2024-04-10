#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    if(a==1)
    {
        cout<<0<<'\n';
        return;
    }
    if(a==2)
    {
        if(tab[1]==1)
        {
            cout<<0<<'\n';
        }
        else
            cout<<1<<'\n';
        return;
    }
    int licz=0;
    for(int x=1;x<a;x++)
    {
        if(tab[x]!=x && tab[x+1]==x+1)
            licz++;
    }
    if(tab[a]!=a)
        licz++;
    if(licz==0)
        cout<<0;
    else if(licz==1)
        cout<<1;
    else
        cout<<2;
    cout<<'\n';
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