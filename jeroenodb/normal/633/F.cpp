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
const int mxN = 1e5+1;
const ll oo = 1e18;
array<ll,3> dp[mxN];
vi adj[mxN];
vi a;
#define rep(i,n) for(int i=0;i<n;++i)
ll ans=0;
void cmax(ll& c, ll b) {c = max(c,b);}
void dfs(int at, int from) {
    auto& c = dp[at];
    c = {a[at],0, 0};
    ll curl = a[at];
    for(auto to : adj[at]) if(to!=from) {
        dfs(to,at);
        auto& old = dp[to];
        auto nw = c;
        auto ncurl = curl;
        rep(i,3) {
            auto score = old[i];
            // connect to a[at]
            if(i==0) {
                cmax(nw[0],a[at]+score);
                cmax(nw[1],max({c[0] + score, c[2]+score+a[at]}));
                cmax(nw[2],score);
                cmax(ncurl,c[0]+score);
                cmax(ans,max({c[0],c[1],c[2],curl}) + score);
            } else if(i==1) {
                cmax(nw[1], score+a[at]);
                cmax(ans,c[0]+score);
            } if(i==2) {
                cmax(nw[1],c[0]+score);
                cmax(nw[2],score);
                cmax(ans,max({c[0],c[2],curl}) + score);
            }
        }
        curl = ncurl;
        c=nw;
    }
    cmax(c[2],curl);
    cmax(ans, *max_element(all(c)));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    a.resize(n);
    for(auto& i : a) cin >> i;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    cout << ans << '\n';
}