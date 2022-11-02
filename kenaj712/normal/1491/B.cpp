#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int maks = 0;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=1;x<a;x++)
        maks = max(maks, abs(tab[x+1] - tab[x]));
    if(maks == 0)
    {
        cout<<c + min(c,b)<<'\n';
    }
    else if(maks == 1)
    {
        cout<<min(b,c)<<'\n';
    }
    else
        cout<<0<<'\n';
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