#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
int c,d;
struct mincostflow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Runtime: O(|E|^2 *(1+log2(C )))
    struct edge {
        int f,c;
        int to, cost;
        bool special=false;
    };
    typedef vector<edge> ve;
    vector<vector<int>> adj;
    vector<edge> edges;
    int n;
    mincostflow(int _n) {
        n=_n;
        adj.resize(n);
        dist.resize(n);
        parent.resize(n);
        pflow.resize(n);
    }
    void addEdge(int a, int b, int w, int cost, bool special = false) {
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b,cost,special});
        edges.push_back({0,0,a,special?cost:-cost,special});
    }
    bitset<mxN> inqueue;
    vector<int> dist, pflow;
    vi parent;

    void SPFA() {
        fill(all(dist),oo);
        queue<int> q; q.push(0);
        parent[0] = -1;
        dist[0] = 0;
        inqueue[0]= true;
        pflow[0] = 1;
        while(!q.empty()) {
            int at = q.front(); q.pop();
            inqueue[at] = false;
            for(int ei: adj[at]) {
                auto& e = edges[ei];
                if(e.c-e.f<1) continue;
                ll constraint = min(e.c-e.f,pflow[at]);
                if(dist[at]+e.cost < dist[e.to]) {
                    parent[e.to] = ei;
                    pflow[e.to] = constraint;
                    dist[e.to] = dist[at]+e.cost;
                    if(!inqueue[e.to]) {
                        inqueue[e.to] = true;
                        q.push(e.to);
                    }
                } else if(dist[at]+e.cost==dist[e.to]) {
                    if(pflow[e.to]< constraint) {
                        parent[e.to] = ei;
                        pflow[e.to] = constraint;
                    }
                }
            }
        }

    }
    void findPath(ll extra) {
        int at = n-1;
        // string path = {letter[at]};
        while(at!=0) {
            int ei = parent[at];
            auto& e = edges[ei];
            e.f+=extra;
            auto& o = edges[ei^1];
            if(e.special) e.cost+=2*d,o.cost-=2*d;
            o.f-=extra;
            at = o.to;
        }
        // reverse(all(path));
        // debug(path);
    }
    pair<ll,ll> solve() {
        ll flow = 0, cost = 0;
        while(true) {
            SPFA();
            if(dist[n-1]==oo)  {
                break;
            }
            int extraflow = pflow[n-1];
            ll shortestpath = dist[n-1];
            flow+=extraflow;
            cost+=shortestpath*extraflow;
            findPath(extraflow);
        }
        return {flow,cost};
    }
};
const int mxT = 120;
int main() {
    int n,m,k; cin >> n >> m >> k >> c >> d;
    vi starting(n+1);
    mincostflow mcmf(n*mxT+2);
    for(int i=1;i<=n;++i) {
        for(int t=0;t<mxT-1;++t) {
            mcmf.addEdge(n*t+i,n*(t+1)+i,oo,0);
        }
    }
    for(int t=0;t<mxT;++t) {
        mcmf.addEdge(t*n+1,n*mxT+1, oo,c*t);
    }
    for(int i=0;i<k;++i) {
        int a; cin >> a;
        starting[a]++;
    }
    for(int i=2;i<=n;++i) {
        mcmf.addEdge(0,i,starting[i],0);
    }
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        for(int t=0;t<mxT-1;++t) {
            mcmf.addEdge(n*t+a,n*(t+1)+b,oo,d,true);
            mcmf.addEdge(n*t+b,n*(t+1)+a,oo,d,true);
        }
    }


    auto [f,cost] = mcmf.solve();
    cout << cost << '\n';

}