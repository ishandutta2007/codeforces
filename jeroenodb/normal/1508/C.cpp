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
const int mxN = 2e5+1, oo = 1e9;
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
        sz[a] = max(sz[a],sz[b]+1);
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
vi adj[mxN];
struct edge {
    int a,b,w;
    bool inMST=false;
    bool bad = false;
    bool operator<(const edge& o) {
        return w<o.w;
    }
};
struct arraylist {
    vi nxt;
    vector<bool> out;
    int head=0, size;
    arraylist() {}
    arraylist(int n) {
        size = n;
        nxt.resize(n);
        iota(all(nxt),1);
        nxt.back() = -1;
        out.resize(n);
    }
    int getnxt(int a) {
        if(nxt[a]==-1) return -1;
        if(out[nxt[a]]) {
            return nxt[a] = getnxt(nxt[a]);
        }
        return nxt[a];
    }
    void erase(int a) {
        // only call on elements in the list
        size--;
        out[a] = true;
        if(a==head) {
            head = getnxt(a);
        }
    }

} unvisited; // can be optimized with linked list with path compression
DSU uns(0);
void dfs(int at, int cnt) {
    // different kind of DFS for super dense graphs, where the complement of the graph is known
    sort(all(adj[at]));
    // comp[at] = cnt;
    unvisited.erase(at);
    for(int to=unvisited.head;to!=-1;to = unvisited.getnxt(to)) {
        if(!binary_search(all(adj[at]),to)) {
            dfs(to,cnt);
            uns.unite(at,to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    uns = DSU(n);
    vector<edge> edges(m);
    int toxor = 0;
    for(auto& e : edges) {
        cin >> e.a >> e.b >> e.w;
        e.a--,e.b--;
        toxor^=e.w;
        adj[e.a].push_back(e.b);
        adj[e.b].push_back(e.a);
    }
    sort(all(edges));
    int cnt = 0;
    unvisited = arraylist(n);
    while(unvisited.size)
        dfs(unvisited.head,cnt++);
    ll total = n*(n-1LL)/2;
    ll ans = 0;
    DSU badcycle(n);
    for(auto& e : edges) {
        if(uns.unite(e.a,e.b)) {
            ans+=e.w;
            e.inMST=true;
        }
        if(!badcycle.unite(e.a,e.b)) {
            e.bad = true;
        }
    }
    int extra = 0;
    if(n-cnt>=total-m) {
        // can't be a cycle in the graph of unassigned edges
        extra = toxor;
        for(auto& e : edges) {
            // not in a cycle where it's the worst
            if(!e.inMST and !e.bad) {
                extra = min(extra,e.w);
            }
        }
    }
    cout << ans+extra << '\n';


}