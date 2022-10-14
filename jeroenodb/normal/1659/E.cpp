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
    vector<bool> good;
    int components;
    DSU() {}
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        good.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        good[a]=good[a] or good[b];
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
    int n,m; cin >> n >> m;
    DSU dsu[30];
    for(int i=0;i<30;++i) {
        dsu[i] = DSU(n);
    }
    vector<array<int,3>> es(m);
    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w,--u,--v;
        if(w%2==0) {
            for(int i=0;i<30;++i) dsu[i].good[u]=dsu[i].good[v]=1;
        }
    }
    for(auto [u,v,w] : es) {
        for(int i=0;i<30;++i) if(w & (1<<i)) {
            dsu[i].unite(u,v);
        }
    }
    int q; cin >> q;
    while(q--) {
        int u,v; cin >> u >> v;
        --u,--v;
        auto query = [&]() {
            for(int i=0;i<30;++i) {
                if(dsu[i].find(u)==dsu[i].find(v)) {
                    return 0;
                }
            }
            for(int i=1;i<30;++i) {
                if(dsu[i].good[dsu[i].find(u)]) {
                    return 1;
                }
            }
            return 2;
        };
        cout << query() << '\n';

    }
    
}