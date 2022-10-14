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
    int n,m,k,q; cin >> n >> m >> k >> q;
    vector<vector<pi>> adj(n);
    struct edge {
        int u,v;
        ll w;
        bool operator<(const edge& o) {return w<o.w;}
    };
    vector<edge> es(m);
    for(auto& e : es) {
        cin >> e.u >> e.v >> e.w;
        --e.u,--e.v;
        adj[e.u].emplace_back(e.v,e.w);
        adj[e.v].emplace_back(e.u,e.w);
    }
    struct el {
        int at; ll d;
        bool operator<(const el& o) const {
            return d>o.d;
        };
    };
    priority_queue<el> pq;
    vector<ll> dist(n,oo);
    vi root(n); iota(all(root),0);
    for(int i=0;i<k;++i) dist[i]=0, pq.push({i,0});
    while(!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if(c.d!=dist[c.at]) continue;
        for(auto [to,w] : adj[c.at]) {
            ll tmp = w+c.d;
            if(tmp<dist[to]) {
                dist[to]=tmp;
                root[to] = root[c.at];
                pq.push({to,tmp});
            }
        }
    }
    vector<pi> qs(q);
    for(auto& [a,b] : qs) cin >> a >> b,--a,--b;
    for(auto& e : es) {
        e.w += dist[e.u]+dist[e.v];
        e.u = root[e.u], e.v = root[e.v];
    }
    es.erase(remove_if(all(es), [&](edge& e){return e.u==e.v;}), es.end());
    sort(all(es));
    vector<array<int,2>> bounds(q, {0,m-1});
    while(any_of(all(bounds), [&](array<int,2>& ar) {return ar[0]!=ar[1];})) {
        vvi when(m);
        for(int i=0;i<q;++i) {
            when[(bounds[i][0]+bounds[i][1])/2].push_back(i);
        }
        DSU dsu(k);
        for(int i=0;i<m;++i) {
            auto& e = es[i];
            dsu.unite(e.u,e.v);
            for(auto j : when[i]) {
                auto [a,b] = qs[j];
                if(dsu.find(a)==dsu.find(b)) {
                    bounds[j][1] = i;
                } else bounds[j][0]=i+1;
            }
        }
    }
    for(int i=0;i<q;++i) {
        cout << es[bounds[i][0]].w << '\n';
    }

}