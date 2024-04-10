/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;

vector<int> in[N], out[N];
int vis[N], ans[N];

void solve()
{
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        in[i].clear(); out[i].clear();
        vis[i]=0;
    }

    int cnt[n+1]={0};
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        out[u].push_back(v);
        in[v].push_back(u);
        cnt[u]++;
    }

    vector<int> pos[m+1];
    pos[0].push_back(n);

    for(int i=0; i<=m; i++)
    {
        for(int x: pos[i])
        {
            if(vis[x]) continue;
            ans[x]=i;
            vis[x]=1;

            for(int y: in[x])
            {
                if(vis[y]) continue;
                cnt[y]--;
                int tmp = i+cnt[y]+1;
                if(tmp<=m) pos[tmp].push_back(y);
            }
        }
    }

    cout<<ans[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}