/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 5e5;
vector<int> adj[N];

void solve()
{
    int n, k;
    cin>>n>>k;

    if(n==1)
    {
        if(k==0)  cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }

    for(int i=1; i<=n; i++) adj[i].clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int deg[n+1], ans[n+1], vis[n+1];
    vector<int> v;

    for(int i=1; i<=n; i++)
    {
        deg[i]=adj[i].size();
        if(deg[i]==1) v.push_back(i);
    }

    for(int i=1; 1; i++)
    {
        if(v.size()==0) break;
        vector<int> v2;
        for(int x: v)
        {
            ans[x]=i;
            for(int y: adj[x])
            {
                deg[y]--;
                if(deg[y]==1) v2.push_back(y);
            }
        }
        v=v2;
    }

    int cnt=0;
    for(int i=1; i<=n; i++) if(ans[i]>k) cnt++;
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}