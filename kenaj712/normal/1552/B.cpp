#include<bits/stdc++.h>
using namespace std;
int tab[50005][10];
bool cmp(int a,int b)
{
    int licz = 0;
    for(int x=1;x<=5;x++)
        if(tab[a][x] <= tab[b][x])
            licz++;
    return licz >= 3;
}
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=5;y++)
            cin>>tab[x][y];
    int cur = 1;
    for(int x=1;x<=a;x++)
        if(!cmp(cur,x))
            cur = x;
    bool czy = true;
    for(int x=1;x<=a;x++)
        czy &= cmp(cur, x);
    if(czy)
        cout<<cur<<'\n';
    else
        cout<<"-1\n";
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