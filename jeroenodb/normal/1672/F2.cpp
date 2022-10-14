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
vector<bool> vis,mark;
bool dfs(int at) {
    mark[at]=true;
    vis[at]=true;
    for(auto to : adj[at]) {
        if(mark[to]) return true;
        if(!vis[to]) {
            if(dfs(to)) return true;
        }
    }
    mark[at]=false;
    return false;
}
bool solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    adj.assign(n,{});
    for(int i=0;i<n;++i) adj[a[i]-1].push_back(b[i]-1);
    int d=0;
    for(auto& i : adj) d = max(d,(int)i.size());
    int i=0;
    while(adj[i].size()<d) ++i;
    adj[i].clear();
    mark.assign(n,0);
    vis=mark;
    for(int i=0;i<n;++i) if(!vis[i]) {
        if(dfs(i)) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        auto res = solve();
        if(res) cout << "AC\n";
        else cout << "WA\n";
    }
}