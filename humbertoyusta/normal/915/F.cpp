#include <bits/stdc++.h>
#define maxn 1000010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int n,smin,smax,p[maxn],ran[maxn],c[maxn];
vector<int> g[maxn];
ii a[maxn];

int find_(int x){
    if( p[x] == x ) return x;
    return p[x] = find_( p[x] );
}

void add_edge_max(int U,int V){
    int u = find_(U), v = find_(V);
    if( u != v ){
        smax += c[U] * ran[v] * ran[u];
        ran[u] += ran[v];
        p[v] = u;
    }
}

void add_edge_min(int U,int V){
    int u = find_(U), v = find_(V);
    if( u != v ){
        smin += c[U] * ran[v] * ran[u];
        ran[u] += ran[v];
        p[v] = u;
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i].f;
        c[i] = a[i].f;
        a[i].s = i;
    }

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sort(a+1,a+n+1);

    for(int i=1; i<=n; i++){
        p[i] = i;
        ran[i] = 1;
    }

    for(int i=n; i>=1; i--){
        int u = a[i].s;
        for( auto v : g[u] )
            if( c[v] >= c[u] )
                add_edge_min(u,v);
    }

    for(int i=1; i<=n; i++){
        p[i] = i;
        ran[i] = 1;
    }

    for(int i=1; i<=n; i++){
        int u = a[i].s;
        for( auto v : g[u] )
            if( c[v] <= c[u] )
                add_edge_max(u,v);
    }

    cout << smax - smin << '\n';

    return 0;
}