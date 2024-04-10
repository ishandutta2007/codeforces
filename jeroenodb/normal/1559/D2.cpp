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
    vvi complement;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        complement.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
        complement[a].clear();
        complement[b].clear();
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
    int n,m[2]; cin >> n >> m[0] >> m[1];
    DSU dsu[2] = {DSU(n),DSU(n)};
    for(int rep=0;rep<2;++rep)
        while(m[rep]--) {
            int u,v; cin >> u >> v,--u,--v;
            dsu[rep].unite(u,v);
        }
    vector<pi> res;
    auto add = [&](int i, int j) {
        res.push_back({i+1,j+1});
        dsu[0].unite(i,j),dsu[1].unite(i,j);
    };
    for(int i=0;i<n;++i) {
        if(dsu[0].find(i)!=dsu[0].find(0) and dsu[1].find(i) != dsu[1].find(0)) {
            add(0,i);
        }
    }
    auto good = [&](int i,bool side) {
        return (dsu[0].find(i)==dsu[0].find(0))==side and  (dsu[1].find(i)==dsu[1].find(0))!=side;
    };
    for(int i=0,j=0;i<n;++i) if(good(i,true)) {
        while(j<n and !good(j,false)) 
            ++j;
        if(j<n) {
            add(i,j);
            ++j;
        }
    }
    cout << res.size() << '\n';
    for(auto [u,v]: res) cout << u << ' ' << v << '\n';

}