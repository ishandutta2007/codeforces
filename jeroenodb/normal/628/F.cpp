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
const int mxN = 1e4+8, mxM = 5e4+2,oo=1e9;
// use Dinic
struct flow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Instead of adjacency vectors with pointers to edges inside, use nxt pointer
    struct edge {
        ll f,c;
        int to;
    };
    typedef vector<edge> ve;
    vector<int> adj[mxN];
    ve edges;
    int n;
    ll scale=0;
    flow(int _n) {
        n=_n;
    }
    void addEdge(int a, int b, ll w) {
        if(a==b) return;
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b});
        edges.push_back({0,0,a});
        if(a==0 or b==n-1) scale = max(scale,w);
    }
 
    int q[mxN], level[mxN];
    bitset<mxN> visited;
    int leveljump[mxM*2], lend[mxN], iter[mxN];
    bool constructlevels() {
        visited.reset();
        int tail = 1, beginp = 0;
        q[0] = 0; level[0] = 0; visited[0] = true; // visit the first node, node 0
        bool finished=false;
        for(int head=0;head<tail;++head) {
            int at = q[head];
            iter[at] = beginp;
            if(at==n-1) {
                finished = true; 
                continue; // edges from the sink to other nodes are not important
            }
            for(int ei: adj[at]) {
                const auto& e = edges[ei];
                if(e.c-e.f<scale or (visited[e.to] and level[e.to]!=level[at]+1)) continue;
                leveljump[beginp++] = ei;
                if(!visited[e.to]) {
                    visited[e.to] = true;
                    q[tail++] = e.to;
                    level[e.to] = level[at]+1;
                }
            }
            lend[at] = beginp;
        }
        return finished;
    }
 
    ll dfs(int at, ll f) {
        if(at==n-1) {
            // debug(f);
            return f;
        }
        for(int& id = iter[at];id<lend[at];++id) {
            int eid = leveljump[id];
            auto& e = edges[eid];
            if(e.c-e.f>0) {
                auto ff = dfs(e.to, min(f,e.c-e.f));
                if(ff!=0) {
                    e.f+=ff;
                    edges[eid^1].f-=ff;
                    return ff;
                }
            } 
        }
        return 0;
    }
    ll solve() {
        ll res = 0;
        while(true) {
            bool good = constructlevels();
            if(!good) {
                scale/=2;
                if(!scale) break;
            } else {
                // Do DFS's
                ll tmp;
                do {
                    tmp = dfs(0,1e18);
                    res+=tmp;
                } while(tmp>0);
            }
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,b,q; cin >> n >> b >> q;
    flow f(b+7);
    const int Sink = b+6,Source=0;
    for(int i=1;i<=b;++i) f.addEdge(i,b+1+(i%5),1);

    for(int j=b+1;j<Sink;++j) f.addEdge(j,Sink,n/5);
    vector<pi> hints(q);
    
    for(auto& [i,v] : hints) cin >> i >> v;
    hints.push_back({b,n});
    sort(all(hints));
    int have=0;
    pi prv={0,0};
    for(auto& [i,v] : hints) {
        if(prv.first==i and v!=prv.second) {
            cout << "unfair";
            exit(0);
        }
        int add = v-have;
        if(add<0) {
            cout << "unfair";
            exit(0);
        }
        for(int j=prv.first+1;j<i;++j) f.addEdge(j+1,j,oo);
        f.addEdge(Source,i,add);
        have=v;
        prv={i,v};
    }
    auto ans = f.solve();
    // for(int i=0;i<b;++i) {
    //     if(f.edges[i*2].f) {
    //         cout << i+1 << '\n';
    //     }
    // }
    if(ans!=n) cout << "un";
    cout << "fair";
}