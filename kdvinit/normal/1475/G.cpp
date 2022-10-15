/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;

vector<int> adj[N];

int vis[N];
int freq[N];
int val[N];

void dfs(int v)
{
    vis[v]=1;
    int ans=freq[v];

    int tmp=0;
    for(int x: adj[v])
    {
        if(freq[x]==0 || x<v) continue;
        if(vis[x]==0) dfs(x);
        tmp=max(tmp,val[x]);
    }
    ans+=tmp;
    
    val[v]=ans;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=N;i++) vis[i]=0;
    for(int i=1;i<=N;i++) freq[i]=0;
    for(int i=1;i<=N;i++) val[i]=0;

    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }

    dfs(1);
    int ans=n-val[1];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i=1;i<=N;i++)
    {
        for(int j=2*i;j<=N;j+=i)
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    int t; cin>>t;
    while(t--) solve();
    return 0;
}