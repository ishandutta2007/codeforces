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
const int mxN = 1000+1;
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
    int perfect=0,perfect2=0;
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
    void addEdge(int a, int b, ll w, int cost, bool directed = true) {
        if(a==0) perfect+=w;
        if(b==n-1) perfect2+=w;
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b,cost});
        edges.push_back({0,directed?0:w,a,-cost});
    }
    bitset<mxN> inqueue;
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

    // ll dfs(int at=0, ll mn=1e18) {
    //     if(at==n-1) return mn;
    //     visited[at] = true;
    //     for(int i: adj[at]) {
    //         auto& e = edges[i];
    //         if(!visited[e.to] and e.f+scale<=e.c) {
    //             ll tmp = min(mn,e.c-e.f);
    //             tmp =  min(tmp,dfs(e.to,tmp));
    //             if(tmp) {
    //                 e.f+=tmp;
    //                 auto& o = edges[i^1];
    //                 o.f-=tmp;
    //                 return tmp;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    void findPath(ll extra) {
        int at = n-1;
        // string path = {letter[at]};
        while(at!=0) {
            int ei = parent[at];
            auto& e = edges[ei];
            e.f+=extra;
            auto& o = edges[ei^1];
            o.f-=extra;
            at = o.to;
            // path.push_back(letter[at]);
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
            // debug(shortestpath);
            // debug(extraflow);

            flow+=extraflow;
            cost+=shortestpath*extraflow;
            findPath(pflow[n-1]);
        }
        return {flow,cost};
    }
};
struct tree {
    vvi adj;
    vi lab,num;
    void dfs(int at,int from=-1) {
        if(lab[at]!=-1) {
            if(from!=-1) 
                num[lab[from]]-=num[lab[at]];
        } else lab[at] = lab[from];
        for(auto to : adj[at]) if(to!=from) {
            dfs(to,at);
        }
    }
    tree(int n) : adj(n),lab(n,-1) {
        for(int i=0;i<n-1;++i) {
            int u,v; cin >> u >> v,--u,--v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void readDemands() {
        int q; cin >> q;
        num.resize(q);
        int id=0;
        for(auto& i : num) {
            int k; cin >> k,--k;
            assert(lab[k]==-1);
            lab[k]=id;
            cin >> i;
            ++id;
        }
    }
    void solve(int root) {
        assert(lab[root]!=-1);
        dfs(root);
        for(auto& i : num) {
            if(i<0) {
                cout << "-1\n";
                exit(0);
            }
        }
    }
};
int main() {
    int n,x,y; cin >> n >> x >> y;
    --x,--y;
    vi a(n); for(auto& i : a) cin >> i;
    tree tr1(n), tr2(n);
    tr1.readDemands(), tr2.readDemands();
    tr1.solve(x),tr2.solve(y);
    int S=0,T = tr1.num.size()+tr2.num.size()+1;
    mincostflow f(T+1);
    for(int i=0;i<(int)tr1.num.size();++i) {
        f.addEdge(S,i+1,tr1.num[i],0);
    }
    for(int i=0;i<(int)tr2.num.size();++i) {
        f.addEdge(i+1+tr1.num.size(),T,tr2.num[i],0);
    }
    for(int i=0;i<n;++i) {
        f.addEdge(tr1.lab[i]+1,tr2.lab[i]+1+tr1.num.size(),1,-a[i]);
    }
    auto [flow,cost] = f.solve();
    if(flow!=f.perfect or flow!=f.perfect2) cout << "-1\n";
    else cout << -cost << '\n';
}