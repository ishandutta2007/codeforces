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
ll ans;
struct DSU{
    vector<int> sz,parent;
    vector<set<int>> disc;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        disc.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
        if(disc[b].size()>disc[a].size()) swap(disc[a],disc[b]);
        for(auto v : disc[b]) {
            if(disc[b].count(v+1)) ans++;
            add(a,v);
        }
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    void add(int i, int v) {
        i = find(i);
        auto& d = disc[i];
        if(d.count(v-1)) ans--;
        if(d.count(v+1)) ans--;
        d.insert(v);
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
    DSU dsu(m);
    ans = n-1;
    for(int i=0;i<n;++i) {
        int j; cin >> j,--j;
        dsu.add(j,i);
    }
    for(int rep=0;rep<m;++rep) {
        cout << ans << '\n';
        if(rep==m-1) break;
        int a,b; cin >> a >> b,--a,--b;
        dsu.unite(a,b);
    }
    
}