#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long
using namespace std;

const int nmax=200500;

string s;
int used[nmax];
vector<int> g[nmax];
map<char, int> cur;

void dfs(int v)
{
    used[v]=1;
    cur[s[v-1]]++;
    for (int i:g[v])
        if (used[i]==0)
            dfs(i);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n, k;
        cin>>n>>k;
        cin>>s;
        for (int i=1; i<=n; i++)
            used[i]=0, g[i].clear();
        int ans=n;
        for (int i=1; i<=n-k; i++)
            g[i].pb(i+k), g[i+k].pb(i);
        for (int i=1; i<=n/2; i++)
            g[i].pb(n+1-i), g[n+1-i].pb(i);
        for (int i=1; i<=n; i++)
            if (used[i]==0)
        {
            cur.clear();
            dfs(i);
            int mx=0;
            for (auto pa:cur)
                mx=max(mx, pa.se);
            ans-=mx;
        }
        cout<<ans<<"\n";
    }

}