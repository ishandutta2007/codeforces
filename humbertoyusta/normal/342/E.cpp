#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, q, lv[maxn], lca[maxn][20], pct[maxn], subt[maxn], mk[maxn], dp[maxn];
vector<int> g[maxn], gct[maxn];

void dfs_1(int u){
    for( auto v : g[u] )
        if ( !lv[v] ){
            lv[v] = lv[u] + 1;
            lca[v][0] = u;
            dfs_1(v);
        }
}

void prec_lca(){
    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++)
            lca[j][i] = lca[lca[j][i-1]][i-1];
}

int LCA(int a,int b){
    if( lv[b] > lv[a] ) swap( a , b );

    for(int i=lg2(lv[a]); i>=0; i--)
        if( lv[a] - (1<<i) >= lv[b] && lca[a][i] )
            a = lca[a][i];

    if( a == b ) return a;

    for(int i=lg2(lv[a]); i>=0; i--)
        if( lca[a][i] != lca[b][i] && lca[a][i] && lca[b][i] )
            a = lca[a][i], b = lca[b][i];

    return lca[a][0];
}

int dist(int a,int b){
    return lv[a] + lv[b] - 2 * lv[LCA(a,b)];
}

void dfs_2(int u,int p){
    subt[u] = 1;
    for( auto v : g[u] ){
        if( v == p || mk[v] ) continue;
        dfs_2(v,u);
        subt[u] += subt[v];
    }
}

int dfs_3(int u,int p,int root){
    int nxt = -1;
    for( auto v : g[u] )
        if( !mk[v] && v != p && subt[v] > subt[root] / 2 )
            nxt = v;
    if( nxt == -1 ) return u;
    return dfs_3(nxt,u,root);
}

void build_ct(int root,int p){

    dfs_2(root,p);
    int centroid = dfs_3(root,p,root);

    gct[p].push_back(centroid);
    pct[centroid] = p;
    mk[centroid] = 1;

    for( auto v : g[centroid] )
        if( v != p && !mk[v] ){
            build_ct(v,centroid);
        }
}

void update(int a,int b){
    while( a != 0 ){
        dp[a] = min( dp[a] , dist( a , b ) );
        a = pct[a];
    }
}

int query(int a,int b){
    int res = inf;
    while( a != 0 ){
        res = min( res , dist(a,b) + dp[a] );
        a = pct[a];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    cin >> n >> q;

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lv[1] = 1;
    dfs_1(1);

    prec_lca();

    build_ct(1,0);

    fill( dp , dp + n + 1 , inf );

    update(1,1);

    for(int i=1; i<=q; i++){
        int u, v;
        cin >> u >> v;
        if( u == 1 ) update(v,v);
            else cout << query(v,v) << '\n';
    }

    return 0;
}