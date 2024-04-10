#include<bits/stdc++.h>
using namespace std;
int tab[10005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        tab[abs(b)]++;
    }
    int licz = (bool)tab[0];

    for(int x=1;x<=100;x++)
        licz += min(2,tab[x]);
    cout<<licz<<'\n';
    for(int x=0;x<=100;x++)
        tab[x] = 0;
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