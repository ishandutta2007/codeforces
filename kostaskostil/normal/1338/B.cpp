#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;
const int nmax=5e5+100;

vector<int> g[nmax];
int d[nmax];

void dfs(int v, int p=-1, int l=0)
{
    d[v]=l;
    for (int i:g[v])
        if (i!=p)
            dfs(i, v, l+1);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int x, y, i=1; i<n; i++){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int mx=n-1;
    for (int i=1; i<=n; i++){
        int c=0;
        for (int j:g[i])
            if (g[j].size()==1)
                c++;
        if (c>1)
            mx-=(c-1);
    }
    dfs(1);
    int par[2];
    for (int i=1; i<=n; i++)
        if (g[i].size()==1)
            par[d[i]%2]=1;
    if ((par[0]==1) and (par[1]==1))
        cout<<3<<" ";
    else
        cout<<1<<" ";
    cout<<mx<<"\n";

    return 0;
}