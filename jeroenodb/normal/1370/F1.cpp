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
vvi adj;
pi query(vi v) {
    cout << "? " << v.size() << ' ' << v << endl;
    int a,b; cin >> a >> b;
    return {a,b};
}
vi vert;
void dfs(int at,int from=-1) {
    vert.push_back(at);
    for(auto to : adj[at]) if(to!=from) {
        dfs(to,at);
    }
}
void dfs2(int at,int left, int from=-1) {
    if(left==0) {
        vert.push_back(at);
        return;
    }
    for(auto to : adj[at]) if(to!=from) {
        dfs2(to,left-1,at);
    }
}
void solve() {
    int n; cin >> n;
    adj.assign(n+1,{});
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi v(n); iota(all(v),1);
    auto [root,dist] = query(v);
    vert.clear();
    dfs(root);
    int lo = 1,hi = n-1;
    while(lo<hi) {
        int mid = (lo+hi+1)/2;
        auto [x,d] = query(vi(vert.begin()+mid,vert.end()));
        if(d==dist) lo = mid;
        else hi = mid-1;
    }
    int u = vert[lo];
    vert.clear();
    dfs2(u,dist);
    auto vv = query(vert).first;
    cout << "! " << u << ' ' << vv << endl;
    string verdict; cin>>verdict;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}