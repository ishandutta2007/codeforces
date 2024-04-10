/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+1;
vector<int> adj[N];

int ans[N];

void DFS(int chi, int par)
{
    int cnt=0;
    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi);
        cnt+=ans[x];
    }
    if(cnt==0) cnt=1;
    ans[chi]=cnt;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=2; i<=n; i++)
    {
        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    DFS(1, -1);
    sort(ans+1, ans+n+1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}