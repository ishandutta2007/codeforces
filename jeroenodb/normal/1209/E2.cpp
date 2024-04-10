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
const int LG = 12, PW = 1<<LG, oo = 1e9;
void cmax(int& a, int b) {a=max(a,b);}
int solve2(vvi a) {
    int n = a[0].size(), full = (1<<n)-1;
    vi dp(1<<n,-oo);
    dp[0]=0;
    for(auto v : a) {
        auto ndp = dp;
        for(int i=0;i<(1<<n);++i) {
            int got=0;
            for(int j=0;j<n;++j) if(i&1<<j) {
                got+=v[j];
            }
            int j = i^full;
            for(int sub = j ; sub > 0 ; sub = (sub-1) & j ) {
                cmax(ndp[sub|i],ndp[sub]+got);
            }
            cmax(ndp[i],got);
        }
        for(int rep=0;rep<n;++rep) for(int i=0;i<1<<n;++i) {
            int nxtperm = i>>1;
            if(i&1) nxtperm|=1<<(n-1);
            cmax(ndp[nxtperm],ndp[i]);
        }
        swap(ndp,dp);
    }
    return dp.back();
}
void solve() {
    int n,m; cin >> n >> m;
    vvi a(m, vi(n));
    vector<pi> order;
    for(int j=0;j<n;++j) for(int i=0;i<m;++i) cin >> a[i][j], order.push_back({i,j});
    sort(all(order), [&](pi c, pi d){return a[c.first][c.second]>a[d.first][d.second]; });
    vector<bool> chosen(m);
    int best[PW];
    fill_n(best,PW,-oo);
    best[0]=0;
    int sm=0;
    vvi nwa;
    for(auto [i,j] : order) {
        if(sm==n) break;
        if(!chosen[i]) {
            nwa.push_back(a[i]);
            chosen[i]=true;
            sm++;
        }
    }
    cout << solve2(nwa) << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}