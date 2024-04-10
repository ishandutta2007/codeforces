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
int main() {
    int n,m; cin >> n >> m;
    vector<array<int,3>> es(m);
    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w;
        --u,--v;
    }
    vi q;
    {
        int p,k,a,b,c;
        cin >> p >> k >> a >> b >> c;
        q.reserve(k);
        q.resize(p);
        for(auto& i : q) cin >> i;
        while(q.size()<k) {
            q.push_back(((ll)q.back()*a + b)%c);
        }
        sort(all(q));
    }
    vi rebuild = {0};
    for(int i=0;i<m;++i) for(int j=i;j<m;++j) {
        rebuild.push_back((es[i][2]+es[j][2])/2 + 1);
    }
    sort(all(rebuild));
    rebuild.erase(unique(all(rebuild)),rebuild.end());
    DSU dsu(n);
    rebuild.push_back(oo);
    auto it = q.begin();
    ll res=0;
    ll ans=0,change=0,rebuildt;
    for(auto t : rebuild) {
        while(it!=q.end() and *it<t) {
            auto cur = ans+change*(*it - rebuildt);;
            res^=cur;
            ++it;
        }
        rebuildt=t;
        ans=0,change=0;
        sort(all(es),[&](const auto& i, const auto& j) {return abs(i[2]-t)<abs(j[2]-t);});
        dsu = DSU(n);
        for(auto [u,v,w] : es) {
            if(dsu.unite(u,v)) {
                ans+=abs(w-t);
                change += (w<=t) - (w>t);
            }
        }
    }
    cout << res << '\n';
}