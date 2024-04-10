#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int tab[1000005];
const int mod = 1e9+7;
long long res = 1;
void dfs(int a)
{
    odw[a] = true;
    for(auto x:pol[a])
        if(!odw[x])
            dfs(x);
}
void solve()
{
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    for(int x=1;x<=a;x++)
    {
        int b;
        cin>>b;
        pol[b].push_back(tab[x]);
        pol[tab[x]].push_back(b);
    }
    for(int x=1;x<=a;x++)
        if(!odw[x])
        {
            res = (res*2)%mod;
            dfs(x);
        }
   // return ;
    cout<<res<<'\n';
    for(int x=1;x<=a;x++)
    {
        odw[x] = false;
        pol[x].resize(0);
    }
    res = 1;

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