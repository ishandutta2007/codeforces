#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int nmax=2e5+100;

int n, m, a, b, c;
int val[nmax];
vector<int> g[nmax];

void bfs(vector<int>& v, int x)
{
    v.assign(n+1, -1);
    queue<int> q;
    v[x]=0;
    q.push(x);
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for (int i:g[t])
            if (v[i]==-1)
                v[i]=v[t]+1, q.push(i);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        cin>>n>>m>>a>>b>>c;
        for (int i=1; i<=m; i++)
            cin>>val[i];
        sort(val+1, val+m+1);
        for (int i=1; i<=m; i++)
            val[i]+=val[i-1];
        for (int i=1; i<=n; i++)
            g[i].clear();
        for (int x, y, i=0; i<m; i++)
        {
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        vector<int> va, vb, vc;
        bfs(va, a);
        bfs(vb, b);
        bfs(vc, c);
        int ans=1e18;
        for (int i=1; i<=n; i++)
        {
            int sa=va[i];
            int sb=vb[i];
            int sc=vc[i];
            if (sa+sb+sc <= m)
            {
                int s= val[sa+sb+sc] + val[sb];
                ans=min(ans, s);
            }
        }
        cout<<ans<<"\n";
    }
}