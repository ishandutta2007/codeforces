    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 3030;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Most used functions--------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
vector<ii> fact(int x){
    vector<ii> ret;
    for(int i=2; i*i<=x; i++){
        if( x % i == 0 ){
            int cnt_ = 0;
            while( x % i == 0 )
                x /= i, cnt_ ++;
            ret.pb({i,cnt_});
        }
    }
    if( x > 1 ){
        ret.pb({x,1});
    }
    return ret;
}
/// My Code -------------------------------------------------

// requires #include<bits/stdc++.h>
// computes maximum flow in a graph from s(given) to t(given) in O(V^2*E) or O(EsqrtV) for unit networks
// tested on spoj FASTFLOW (0.31s) and FAST MAXIMUM MATCHING (TLE)
// initialize only with the number of vertices (plus one since they are 0-indexed)
// add edges from u to v with capacity cap with addedge(u,v,cap)
// computes the flow from s to t with flow(s,t), you can call int multiple times
// after computing the flow edges will contain a vector with the edges and the flow that passes trough
// each edge, this vector will store the flow from the last call to flow()
// written by humbertoyusta

struct flowedge{
    int u, v;
    long long cap, flow = 0;
    flowedge(int u,int v,long long cap) : u(u), v(v), cap(cap) {}
};

struct dinic{
    const long long flow_inf = 2000000000000000007ll;
    int V, E, s, t;
    vector<flowedge> edges;
    vector<vector<int>> adj;
    vector<int> lv, ptr;
    queue<int> q;

    dinic(int _V){
        V = _V; E = 0;
        adj.clear(); adj.resize(V);
        lv.clear(); lv.resize(V);
        ptr.clear(); ptr.resize(V);
    }

    void addedge(int u,int v,int cap){
        edges.push_back(flowedge(u,v,cap));
        edges.push_back(flowedge(v,u,0));
        adj[u].push_back(E);
        adj[v].push_back(E+1);
        E += 2;
    }

    long long dfs(int u,int pushed){
        if( pushed == 0 ) return 0;
        if( u == t ) return pushed;
        for(int &cid = ptr[u]; cid < adj[u].size(); cid ++){
            int id = adj[u][cid];
            int v = edges[id].v;
            if( edges[id].cap - edges[id].flow <= 0 || lv[v] != lv[u] + 1 )
                continue;
            long long fl = dfs( v , min( pushed , edges[id].cap - edges[id].flow ) );
            if( fl == 0 )
                continue;
            edges[id].flow += fl;
            edges[id^1].flow -= fl;
            return fl;
        }
        return 0;
    }

    bool bfs(){
        q.push(s);
        lv[s] = 0;
        while( !q.empty() ){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if( edges[v].cap - edges[v].flow <= 0 || lv[edges[v].v] != -1 )
                    continue;
                lv[edges[v].v] = lv[u] + 1;
                q.push(edges[v].v);
            }
        }
        return lv[t] != -1;
    }

    long long flow(int _s,int _t){
    	for(int i=0; i<edges.size(); i++)
    	    edges[i].flow = 0;
        s = _s;
        t = _t;
        int ret_flow = 0;
        while( true ){
            fill( lv.begin() , lv.end() , -1 );
            if( !bfs() )
                break;
            fill( ptr.begin() , ptr.end() , 0 );
            while( true ){
                long long pushed = dfs(s,flow_inf);
                if( pushed == 0 ) break;
                ret_flow += pushed;
            }
        }
        return ret_flow;
    }

};

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;
    dinic graph = dinic(n+m+2);

    for(int i=1; i<=n; i++){
        int u;
        cin >> u;
        graph.addedge(i,n+m+1,u);
    }

    int sum = 0;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        graph.addedge(0,n+i,w);
        graph.addedge(n+i,u,1000ll*mod);
        graph.addedge(n+i,v,1000ll*mod);
    }

    cout << sum - graph.flow(0,n+m+1) << '\n';

    return 0;
}