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
const int mxN = 1e5+1;
const ll oo = 1e18;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    for(int i=0;i<m;++i) {
        int u,v,w; cin >> u >> v >> w,--u,--v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int k; cin >> k;
    vi cmps(k); 
    for(auto& i : cmps) cin >> i,--i;
    vector<pair<ll,int>> best(n);
    vector<ll> d(n,oo);
    vi from(n,-1);
    struct el {
        ll d; int at;
        bool operator<(const el& o) const {
            return d>o.d;
        }
    };
    priority_queue<el> pq;
    auto process = [&](int to, int f, ll di) {
        if(di<d[to]) {
            d[to]=di;
            from[to]=f;
            pq.push({di,to});
        }
    };
    for(auto& i : cmps) process(i,i,0);
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(d[e.at]!=e.d) continue;
        for(auto [to,w] : adj[e.at]) {
            process(to,from[e.at],e.d+w);
        }
    }
    ll ans=0;
    DSU dsu(n);
    while(cmps.size()>1) {

        
        fill(all(best),pair<ll,int>{1e18,0});
        for(int i=0;i<n;++i) if(d[i]!=oo) for(auto [j,w] : adj[i]) {
            int a = dsu.find(from[i]), b = dsu.find(from[j]);
            if(a!=b) {
                best[a] = min(best[a], {d[i]+d[j]+w,b});
            }
        }
        sort(all(cmps),[&](int i, int j) {return best[i].first<best[j].first;});
        for(auto i : cmps) if(best[i].first!=oo) {
            if(dsu.unite(i,best[i].second)) {
                ans+=best[i].first;
            }
        }
        cmps.erase(partition(all(cmps),[&](int i) {return dsu.find(i)==i;}),cmps.end());
    }
    cout << ans+d[0] << '\n';
}