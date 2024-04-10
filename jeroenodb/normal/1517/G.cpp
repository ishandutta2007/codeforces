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
const int mxN = 5e3+2, mxM = 6e3+2;
const ll oo = 1e12;
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
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir[] = {{1,0},{0,1},{-1,0}, {0,-1}};
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
struct cmp {
    bool operator()(const pt& p,const pt& q) const {
        if(p.X!=q.X) return p.X<q.X;
        return p.Y<q.Y;
    }
};
int color(pt p) {
    if(p.X%2==0 and p.Y%2==0) return 1;
    if(p.Y%2==0) return 0;
    if(p.X%2==0) return 2;
    return 3;
}
int main() {
    int n; cin >> n;
    map<pt,int,cmp> ptmap;
    vector<pt> pts(n);
    vi w(n);
    ll sm = 0;
    for(int i=0;i<n;++i) {
        auto& p = pts[i];
        read(p);
        cin >> w[i];
        sm+=w[i];
        ptmap[p] = i;
    }
    flow f(2*n+2);
    for(int i=0;i<n;++i) {
        auto at = pts[i];
        if(color(at)==0) f.addEdge(0,2*i+1,oo);
        if(color(at)==3) f.addEdge(2*i+2, n*2+1,oo);
        f.addEdge(2*i+1,2*i+2, w[i]);
        auto addpath = [&](pt to) {
            if(color(at) == color(to)-1 and ptmap.count(to)) {
                f.addEdge(2*i+2, ptmap[to]*2+1,oo);
            }
        };
        for(auto d : dir) addpath(at+d);
    }
    auto ans = sm-f.solve();
    cout << ans  << '\n';
}