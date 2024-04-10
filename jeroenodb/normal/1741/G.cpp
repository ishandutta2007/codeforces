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
const int mxN = 2e4+3;
const ll oo = 1e18;
struct mincostflow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Runtime: O(|E|^2 *(1+log2(C )))
    struct edge {
        ll f,c;
        int to, cost;
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
        inqueue.resize(n);
    }
    void addEdge(int a, int b, ll w, int cost, bool directed = true) {
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b,cost});
        edges.push_back({0,directed?0:w,a,-cost});
    }
    vector<bool> inqueue;
    vector<ll> dist, pflow;
    vi parent;

    void SPFA() {
        fill(all(dist),oo);
        queue<int> q; q.push(0);
        parent[0] = -1;
        dist[0] = 0;
        inqueue[0]= true;
        pflow[0] = oo;
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
        while(at!=0) {
            int ei = parent[at];
            auto& e = edges[ei];
            e.f+=extra;
            auto& o = edges[ei^1];
            o.f-=extra;
            at = o.to;
        }
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
            if(shortestpath>=0) break;
            // debug(shortestpath);
            // debug(extraflow);
            flow+=extraflow;
            cost+=shortestpath*extraflow;
            findPath(pflow[n-1]);
            
        }
        return {flow,cost};
    }
};
void solve() {
    int n,m; cin >> n >> m;
    vector<basic_string<int>> adj(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi q;
    vi d(n,1e9);
    auto process = [&](int at, int di) {
        if(d[at]>di) {
            d[at]=di;
            q.push_back(at);
        }
    };
    process(0,0);
    for(int i=0;i<(int)q.size();++i) {
        int at = q[i];
        for(int to : adj[at]) process(to,d[at]+1);
    }
    mincostflow fl(n*2+1);
    for(int at=0;at<n;++at) {
        fl.addEdge(at*2,at*2+1,1e9,0);
        for(int to : adj[at]) if(d[to]-d[at]==1) {
            fl.addEdge(at*2+1,to*2,1e9,0);
        }
    }
    int f; cin >> f;
    vi friends(f);
    for(auto& i : friends) cin >> i,--i;
    int p; cin >> p;
    map<int,int> gain;
    for(int rep=0;rep<p;++rep) {
        int i; cin >> i;
        --i;
        int& fr = friends[i];
        gain[fr]+=1;
        
        fr=-1;
    }
    for(auto& [fr,x] : gain) {
        fl.addEdge(fr*2,fr*2+1,1,-x);
    }
    for(auto& i : friends) {
        if(i!=-1) 
            fl.addEdge(i*2+1,n*2,1,0);
    }
    auto [flow,cost] =  fl.solve();
    cout << p+cost << '\n';
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}