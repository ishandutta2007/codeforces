#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int jmp[1000005];
int a;
int licz = 0;
void przelicz()
{
    int last = a+1;
    for(int x=a;x>=1;x--)
    {
        if(tab[x] > 1)
            last = x;
        jmp[x] = last;
    }
}
void dfs(int b)
{
    if(b <= a && tab[b] == 1)
        b = jmp[b];
    if(b >= a+1)
        return;
    int pom = b + tab[b];
    tab[b]--;
    if(tab[b] == 1)
        licz++;
    dfs(pom);
}
void solve()
{
    cin>>a;
    licz = 0;
    long long ans = 0;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
    }
    przelicz();
    for(int x=1;x<=a;x++)
        if(tab[x] == 1)
            licz++;
    while(licz!=a)
    {
        int pom = jmp[1];
        if(tab[pom]>5000)
        {
            ans += tab[pom] - 5000;
            tab[pom] = 5000;
        }
        int pom2 = licz;
        dfs(1);
        if(pom2 != licz)
            przelicz();
        ans++;
    }
    cout<<ans<<'\n';
    for(int x=1;x<=a;x++)
    {
        tab[x] = 0;
        jmp[x] = 0;
    }
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