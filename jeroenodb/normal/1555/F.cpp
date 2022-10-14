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
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};

struct HLD {
    int n;
    vi chain, in, parent, sz;
    vector<bool> pref,vis;
    vector<set<int>> s;
    vector<vector<pi>> adj;
    int cnt;
    void dfs(int at, int path) {
        vis[at]=true;
        in[at] = cnt;
        chain[cnt++] = path;
        bool heavy = true;
        for(auto [to,w]: adj[at]) {
            pref[to]=pref[at]^w;
            parent[cnt] = in[at];
            dfs(to,heavy?path:cnt);
            heavy = false;
        }
    }
    HLD(int nn) {
        n=nn;
        adj.assign(n,{});
        s.assign(n,{});
        in.assign(n,-1);
        sz.assign(n,1);
        pref.resize(n),vis.resize(n);
    }
    void addedge(int a,int b, int w) {
        adj[a].emplace_back(b,w);
        adj[b].emplace_back(a,w);
    }
    void init() {
        {
            vector<pi> q; q.reserve(n);
            // also has to work on forests!
            int j=0;
            for(int i=0;i<n;++i) {
                if(i==(int)q.size()) {
                    while(vis[j]) ++j;
                    q.push_back({j,-1});
                }
                auto [at,from] = q[i];
                vis[at]=true;
                for(auto it = adj[at].begin();it!=adj[at].end();++it) {
                    if(it->first==from) {
                        adj[at].erase(it);
                        break;
                    }
                }
                for(auto [to,w]: adj[at])
                    q.emplace_back(to,at);
            }
            for(int i=n-1;i>=0;--i) {
                auto at = q[i].first;
                auto heavy = adj[at].begin();
                for(auto to = heavy; to!=adj[at].end();++to){
                    sz[at]+=sz[to->first]; // calculate sizes of subtrees
                    if(sz[to->first]>sz[heavy->first]) {
                        swap(*to,*heavy); // move heaviest child to front
                    }
                }
            }
        }
        chain.assign(n,-1);
        parent.assign(n,-1);
        cnt=0;
        fill(all(vis),0);
        for(int i=0;i<n;++i) if(!vis[i]) dfs(i,i);
    }
    auto query(int a, int b) {
        for(a = in[a],b = in[b];chain[a]!=chain[b];b = parent[chain[b]]) {
            if(a>b) swap(a,b);
            auto& mys = s[chain[b]];
            if(!mys.empty() and *mys.begin()<=b) {
                return true;
            }
        }
        if(a>b) swap(a,b);
        auto& mys = s[chain[a]];
        auto it = mys.upper_bound(a);
        return it!=mys.end() and *it<=b;
    }
    void add(int a, int b) {
        for(a = in[a],b = in[b];chain[a]!=chain[b];b = parent[chain[b]]) {
            if(a>b) swap(a,b);
            while(b!=chain[b]) {
                s[chain[b]].insert(b);
                b--;
            }
            s[b].insert(b);
        }
        if(a>b) swap(a,b);
        for(int i=a+1;i<=b;++i) {
            s[chain[a]].insert(i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // find spanning tree with earliest edges
    // go over all edges in order again, and if it is cycleforming edge,
    // check that xor is 1, and it doesn't share any edge with another cycle.
    // when placing a cycle, mark edges in the spanning tree  ( O(n log(n)) amortized )
    // when checking if cycle is possible: 
    //   path from a to b, check if marked edges from a to LCA(a,b), b to LCA(a,b)
    // Use heavy light decomposition for this, can be done with a set for each chain
    int n,q; cin >> n >> q;
    DSU dsu(n);
    HLD hld(n);
    vector<array<int,3>> es(q);
    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w,--u,--v;
        if(dsu.unite(u,v)) {
            hld.addedge(u,v,w);
            w=-1;
        }
    }
    hld.init();
    auto yes = [](){cout << "YES\n";};
    auto no = [](){cout << "NO\n";};
    for(auto& [u,v,w]: es) {
        if(w==-1) {
            yes();
            continue;
        }
        if(hld.pref[u]^hld.pref[v]==w) {
            no();
        } else {
            if(hld.query(u,v)) no();
            else {
                yes();
                // add cycle to HLD sets
                hld.add(u,v);
            }
        }
    }


}