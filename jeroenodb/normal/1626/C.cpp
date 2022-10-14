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
void solve() {
    int n; cin >> n;
    vi k(n); for(auto& i : k) cin >> i;
    vi h(n); for(auto& i : h) cin >> i;
    vector<ll> dp(n+1, ll(oo)*oo);
    vector<vector<pair<ll,int>>> trans(n);
    for(int i=0;i<n;++i) for(int j=i;j<n;++j) {
        ll s = k[i]-h[i]+1;
        bool bad=false;
        int f=-1;
        for(int o=0;o<=j;++o) if(k[o]>=s) {
            if(f==-1) f=o;
            if(k[o]-s+1<h[o]) bad=true;
        }
        ll len = 1+k[j]-s;
        if(!bad) trans[f].push_back({len*(len+1)/2, j+1});
    }
    dp[0]=0;
    for(int i=0;i<n;++i) for(auto [cost,to] : trans[i]) {
        dp[to]=min(dp[to],dp[i]+cost);
    }
    cout << dp[n] << '\n';
    
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}