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
const int mxN = 3e5+30, oo = 1e9;
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
int p[mxN], order[mxN];
int currank=0;
bitset<mxN> visited;
void dfs(int at) {
    visited[at]=true;
    for(int to : adj[at]) if(!visited[to]) {
        dfs(to);
    }
    order[currank++]=at;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;

    for(int i=0;i<n;++i) {
        cin >> p[i], p[i]--;
    }
    vector<pi> pairs(k);
    vi comp(n);
    {
    DSU dsu(n);
    for(auto& [a,b]:pairs) {
        cin >> a >> b,--a,--b;
        dsu.unite(a,b);
    }
    for(int i=0;i<n;++i) comp[i]=dsu.find(i);
    }
    for(int i=0;i<n;++i) {
        if(p[i]!=-1) {
            adj[comp[p[i]]].push_back(comp[i]);
        }
    }
    for(int i=0;i<n;++i) if(!visited[i] and comp[i]==i) {
        dfs(i);
    }
    vi comporder(order,order+currank);
    for(int i=0;i<n;++i) adj[i].clear();
    currank=0, visited.reset();
    for(auto [a,b]: pairs) adj[a].push_back(b);
    for(int i=0;i<n;++i) if(!visited[i]) dfs(i);
    vvi compressed(n);
    for(int i=0;i<n;++i) {
        int j = order[i];
        compressed[comp[j]].push_back(j);
    }
    vi res;
    for(auto& i: comporder) for(auto j: compressed[i]) {
        res.push_back(j);
    }
    reverse(all(res));
    vi inv(n); for(int i=0;i<n;++i) inv[res[i]]=i;
    for(auto [a,b]:pairs) {
        if(inv[a]!=inv[b]-1) {
            cout << "0\n";
            exit(0);
        }
    }
    for(int i=0;i<n;++i) if(p[i]!=-1) {
        if(inv[p[i]]>inv[i]) {
            cout << "0\n";
            exit(0);
        }
    }
    for(auto i: res) cout << i+1 << ' ';
    cout << '\n';


}