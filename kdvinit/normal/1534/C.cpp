/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6;
vector<int> adj[N];
int vis[N];

const int mod = 1e9 + 7;

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int $result=1; base%=mod;
   while(expo) {   if(expo%2==1)  $result=($result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return $result;
}


void DFS(int chi, int par)
{
    vis[chi]=1;
    for(auto x: adj[chi])
    {
        if(x==par || vis[x]==1) continue;
        DFS(x, chi);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) { adj[i].clear(); vis[i]=0; }

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    for(int i=1; i<=n; i++)
    {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;
        ans++;
        DFS(i, -1);
    }
    ans = Power(2, ans);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}