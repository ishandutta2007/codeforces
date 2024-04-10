#pragma GCC optimize("Ofast")
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
const int mxN = 3010, oo = 1e9;
typedef pair<int,ll> state;
state dp[mxN][mxN];
int dp2[mxN][mxN];
vi adj[mxN];
int sm[mxN],n,m;
int sz[mxN];
state sum(const state& a,const state& b) {
    return {a.first+b.first,a.second+b.second};
}
void dfs(int at, int from) {
    sz[at]=1;
    fill(dp2[at],dp2[at]+n+1,-oo);
    fill(dp[at],dp[at]+n+1,state{-oo,(ll)-1e18});
    dp[at][0] = {0,sm[at]};
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        int prv=sz[at];
        sz[at]+=sz[to];
        for(int i=sz[at];i>=0;--i) {
            state nwdp=state{-oo,(ll)-1e18};
            for(int j=max(0,i-prv);j<=min(sz[to],i);++j) {
                // transition with child in different partition
                nwdp=max(nwdp,sum({dp2[to][j],0},dp[at][i-j]));
                // transition with child in same partition
                nwdp=max(nwdp,sum(dp[to][j],dp[at][i-j]));
            }
            dp[at][i]=nwdp;
        }
    }
    // calculate dp2's
    for(int i=0;i<sz[at];++i) {
        dp2[at][i+1]=max(dp2[at][i],dp[at][i].first+(dp[at][i].second>0));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0;i<n;++i) {
            adj[i].clear();
            sz[i]=0;
            cin >> sm[i];
            sm[i]=-sm[i];
        }
        for(int i=0;i<n;++i) {
            int w; cin >> w;
            sm[i]+=w;
        }
        for(int i=0;i<n-1;++i) {
            int x,y; cin >> x >> y,--x,--y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0,-1);
        cout << dp2[0][m] << '\n';
    }
}