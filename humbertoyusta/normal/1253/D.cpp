#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
#define maxn 200010
using namespace std;
typedef pair<int,int> ii;

int n, m, comp[maxn], cc;
vector<int> g[maxn];
ii seg[maxn];

void dfs(int u,int c){
    comp[u] = c;
    seg[c].f = min( seg[c].f , u );
    seg[c].s = max( seg[c].s , u );
    for( auto v : g[u] )
        if( !comp[v] )
            dfs(v,c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        seg[i] = {inf,0};

    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
        if( !comp[i] )
            dfs(i,++cc);

    sort( seg + 1 , seg + cc + 1 );

    int mx = 0, ans = 0;
    for(int i=1; i<=cc; i++){
        if( seg[i].f <= mx ) ans++;
        mx = max( mx , seg[i].s );
    }
    cout << ans;

    return 0;
}