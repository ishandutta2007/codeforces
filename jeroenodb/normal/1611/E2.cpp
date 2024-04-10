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
const int mxN = 2e5+1, oo = 1e9;
int vert[mxN],out[mxN],cnt=0;
vi adj[mxN], st;
bitset<mxN> vis,vis2;
void dfs(int at, int from) {
    vert[cnt++]=at;
    st.push_back(at);
    if(vis[at]) {
        vis2[st[st.size()/2]]=true;
    }
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
    }
    out[at]=cnt;
    st.pop_back();
}
void cmin(int& a, int b) {a=min(a,b);}
void solve() {
    int n,k; cin >> n >> k;
    for(int i=0;i<n;++i) 
        adj[i].clear(),vis[i]=false,vis2[i]=false;
    while(k--) {
        int x; cin >> x,--x;
        vis[x]=true;
    }
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt=0;
    dfs(0,0);
    vi dp(n+1,oo);
    dp[1]=0;
    for(int i=0;i<n;++i) {
        int j = vert[i];
        if(out[j]>i+1) {
            cmin(dp[i+1],dp[i]);
        }
        if(vis[j] or vis2[j]) {
            cmin(dp[out[j]],dp[i]+1);
        }
    }
    // E1
    // if(dp[n]!=oo) cout << "NO\n";
    // else cout << "YES\n";
    // E2
    if(dp[n]==oo) cout << "-1\n";
    else cout << dp[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {

        solve();
    }
}