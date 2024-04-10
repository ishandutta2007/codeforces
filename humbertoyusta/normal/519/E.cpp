/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;

int n,lca[maxn][20],p[maxn],lv[maxn],q,subt[maxn];
vector<int> g[maxn];

void dfs(int u){
    subt[u] = 1;
    for(auto v : g[u])
        if( v != p[u] ){
            p[v] = u;
            lv[v] = lv[u] + 1;
            lca[v][0] = u;
            dfs(v);
            subt[u] += subt[v];
        }
}

void prec(){
    for(int j=1; j< 20; j++)
        for(int i=1; i<=n; i++)
            lca[i][j] = lca[lca[i][j-1]][j-1];
}

int query(int a,int b){
    if( lv[a] < lv[b] ) swap(a,b);

    int d = lv[a]-lv[b];
    if( d )
        for(int i=0; i<20; i++)
            if( d & (1<<i) )
                a = lca[a][i];
    if( a == b ) return a;

    for(int i=lg2(lv[a])+1; i>=0; i--){
        if( lca[a][i] != lca[b][i] && lca[a][i] ){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

int find_(int a,int d){
    for(int i=0; i<20; i++)
        if( d & (1<<i) )
            a = lca[a][i];
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<n; i++){
        int aa, bb;
        cin >> aa >> bb;
        g[aa].push_back(bb);
        g[bb].push_back(aa);
    }

    p[1] = 1;
    lv[1] = 1;
    dfs(1);
    prec();

    cin >> q;
    for(int i=1; i<=q; i++){
        int aa, bb;
        cin >> aa >> bb;
        if( aa == bb ){ cout << n << '\n'; continue; }
        int LCA = query(aa,bb);
        int dist = lv[aa] + lv[bb] - 2 * lv[LCA];
        if( dist % 2 == 1 ){ cout << 0 << '\n'; continue; }
        if( lv[aa] < lv[bb] ) swap( aa , bb );
        if( lv[aa] == lv[bb] ){ cout << n - subt[find_(aa,lv[aa]-lv[LCA]-1)] - subt[find_(bb,lv[bb]-lv[LCA]-1)] << '\n'; continue; }
        int node_half = find_( aa , dist / 2 );
        cout << subt[node_half] - subt[find_(aa,dist/2-1)] << '\n';
    }

    return 0;
}