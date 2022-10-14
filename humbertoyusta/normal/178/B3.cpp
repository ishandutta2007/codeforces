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

struct edges{
    int u,v,w;
    bool operator < ( const edges & other ) const {
        return w < other .w;
    }
};

int n,m,low[maxn],dt[maxn],cont,p[maxn],parent[maxn],dist[maxn],lca[maxn][20],lv[maxn],q;
bool mk[maxn];
vector<int> g[maxn];
vector<int> tree[maxn];
vector<edges> edge;
map<ii,bool> bridges;

void tarjan_bridges(int u){
    low[u] = dt[u] = ++cont;
    for(auto v : g[u]){
        if( !dt[v] ){
            p[v]=u;
            tarjan_bridges(v);
            low[u] = min( low[u] , low[v] );

            if(low[v] > dt[u]){
                bridges[ii{u,v}] = 1;
                bridges[ii{v,u}] = 1;
            }
        }
        else if( p[u] != v )
            low[u] = min( low[u] , dt[v] );
    }
}

int find_(int x){
    if( parent[x] == x ) return x;
    return parent[x] = find_( parent[x] );
}

void kruskall(){
    for(int i=1; i<=n; i++)
        parent[i] = i;
    sort(edge.begin(),edge.end());
    for(auto i : edge){
        int a = i.u;
        int b = i.v;
        int c = i.w;

        if( find_(a) != find_(b) ){
            parent[find_(a)] = find_(b);
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
}

int dfs(int u,int par){
    for(auto v : tree[u]){
        if( v != par ){
            dist[v] = dist[u] + bridges[ii{u,v}];
            lca[v][0] = u;
            lv[v] = lv[u] + 1;
            dfs(v,u);
        }
    }
}

void prec(){
    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++)
            lca[j][i] = lca[lca[j][i-1]][i-1];
}

int query(int a,int b){
    if( lv[a] < lv[b] ) swap(a,b);

    int d = lv[a] - lv[b];
    if(d) for(int i=0; i<20; i++)
              if( d & (1<<i) )
                  a = lca[a][i];
    if( a == b ) return a;

    for(int i=lg2(lv[a]); i>=0; i--)
        if( lca[a][i] != lca[b][i] )
            a = lca[a][i], b = lca[b][i];

    return lca[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    p[1] = 1;
    tarjan_bridges(1);

    for(int i=1; i<=n; i++)
        for(auto j : g[i])
            edge.push_back(edges{i,j,bridges[ii{i,j}]});

    kruskall();

    lv[1] = 1;
    dfs(1,1);

    prec();

    cin >> q;

    for(int i=1; i<=q; i++){
        int a,b;
        cin >> a >> b;
        int LCA = query(a,b);
        cout << dist[a] + dist[b] - 2 * dist[LCA] << '\n';
    }

    return 0;
}