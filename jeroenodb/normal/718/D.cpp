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
map<vi,int> mp;
int cnt=0;
int get(vi v) {
    sort(all(v));
    if(mp.count(v)) return mp[v];
    return mp[v] = cnt++;
}
vi dp,par;
vvi adj;
void dfs(int at) {
    vi cs;
    for(int to : adj[at]) if(to!=par[at]) {
        par[to]=at;
        dfs(to);
        cs.push_back(dp[to]);
    }
    dp[at] = get(cs);
}
set<int> ans;
vi downdp;
void add(int at, int v) {
    if(adj[at].size()<4) ans.insert(v);
}
void dfs2(int at) {
    for(int to : adj[at]) if(to!=par[at]) {
        vi cs = {};
        if(par[at]!=-1) cs.push_back(downdp[at]);
        for(int cur : adj[at]) if(cur!=to and cur!=par[at]) {
            cs.push_back(dp[cur]);
        }
        downdp[to] = get(cs);
    }
    if(par[at]==-1) {
        add(at,dp[at]);
    } else {
        vi cs = {downdp[at]};
        for(int to : adj[at]) if(to!=par[at]) {
            cs.push_back(dp[to]);
        }
        add(at,get(cs));
    }
    for(int to : adj[at]) if(to!=par[at]) 
        dfs2(to);
}
int main() {
    int n; cin >> n;
    adj.resize(n);
    dp.resize(n),par.resize(n,-1);
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    downdp = dp;
    dfs2(0);
    cout << ans.size() << '\n';
    
}