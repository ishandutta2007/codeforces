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
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<m;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
struct DSU{
    vector<int> sz,parent;
    vector<bool> f;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        f.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b, bool myf=true) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
        f[b]=myf;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb,f[a]==f[b]);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) {
            return a;
        }
        int root = find(parent[a]);
        f[a]=f[a] != f[parent[a]];
        return parent[a] = root;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<string> g(n);
    for(auto& i : g) cin >> i;
    auto id = [&](pt p) {
        return p.X*m + p.Y;
    };
    DSU dsu(n*m);
    vvi res(n,vi(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(g[i][j]=='X') {
        vi ne;
        pt at = {i,j};
        for(auto to : dir4) {
            to+=at;
            if(g[to.X][to.Y]=='.') {
                ne.push_back(id(to));
            }
        }
        if(ne.size()%2==1) {
            cout << "NO\n";
            exit(0);
        }
        for(int i=1;i<ne.size();++i) {
            dsu.unite(ne[i-1],ne[i]);
        }
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(g[i][j]=='.') {
        auto tmp = id({i,j});
        dsu.find(tmp);
        res[i][j] = dsu.f[tmp]?1:4;
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(g[i][j]=='X') {
        pt at = {i,j};
        for(auto to : dir4) {
            to+=at;
            if(g[to.X][to.Y]=='.') res[i][j]+=res[to.X][to.Y];
        }
    }
    cout << "YES\n";
    for(auto i : res) cout << i << '\n';
}