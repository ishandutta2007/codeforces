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
struct SCC {
    vector<vi> adj,rev;
    vi comp,ord,sz;
    vector<bool> vis;
    SCC(int n) : adj(n),rev(n),comp(n),sz(n),vis(n) {}
    void addE(int a, int b) {
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    void dfs(int at) {
        vis[at]=true;
        for(auto to : rev[at]) if(!vis[to]) dfs(to);
        ord.push_back(at);
    }
    void dfs2(int at) {
        vis[at]=true;
        sz[comp[at]]++;
        for(auto to : adj[at]) if(!vis[to]) {
            comp[to]=comp[at];
            dfs2(to);
        }
    }
    void run() {
        int n = adj.size();
        for(int i=0;i<n;++i) if(!vis[i]) dfs(i);
        reverse(all(ord));
        fill(all(vis),0);
        for(auto root : ord) if(!vis[root]) {
            comp[root]=root;
            dfs2(root);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    SCC scc(n);
    vector<vector<pi>> adj(n);
    for(int i=0;i<m;++i) {
        int u,v,w; cin >> u >> v >> w;
        --u,--v;
        adj[u].push_back({v,w});
        scc.addE(u,v);
    }
    scc.run();
    vector<ll> d(n,1e18);
    struct el {
        ll d;
        int at; 
        bool operator<(const el& o) const {
            return d>o.d;
        }
    };
    priority_queue<el> pq;
    vector<ll> period(n);
    auto process = [&](el e, int f) {
        if(scc.comp[e.at] != scc.comp[f] or d[e.at]<=e.d) return;
        pq.push(e);
        d[e.at]=e.d;
    };
    for(int i=0;i<n;++i) if(scc.comp[i]==i) process({0,i},i);
    
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(e.d!=d[e.at]) continue;
        for(auto [to,w] : adj[e.at]) {
            process({w+e.d,to},e.at);
        }
    }
    for(int at=0;at<n;++at) for(auto [to,w] : adj[at]) if(scc.comp[at]==scc.comp[to]) {
        ll g = abs(d[at]-d[to] + w);
        period[scc.comp[at]] = gcd(period[scc.comp[at]],g);
    }
    int q; cin >> q;
    while(q--) {
        int v,s,t; cin >> v >> s >> t; --v;
        v = scc.comp[v];
        if(scc.sz[v]==1) {
            if(s==0) {
                cout << "YES\n";
            } else cout << "NO\n";
            continue;
        }
        auto g = period[v];
        // can change by any thing of g
        // g*x = t-s mod t
        // only solution if: 
        // => g*x + t*y = t-s
        int myg = gcd(g,t);
        if( (t-s) %myg==0) {
            cout << "YES\n";
        } else cout << "NO\n";
        

    }

}