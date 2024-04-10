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
int main() {
    int n,k; cin >> n >> k;
    struct wave {
        int l,r,a;
    };
    vector<wave> ws(n);
    for(auto& w : ws) cin >> w.l >> w.r >> w.a;
    ws.push_back({-100,-100,0});
    vector<ll> dp(n+1,oo);
    dp[0]=0;
    ll ans = oo;
    for(int i=0;i<n;++i) {
        if(dp[i]==oo) continue;
        ll mag = k,used=dp[i];
        for(int j=i;j<n;++j) {
            auto& w = ws[j];
            ll reloads = max(0LL,(w.a-mag+k-1)/k);
            if(reloads>w.r-w.l) break;
            if(reloads+w.l < ws[j+1].l ) {
                dp[j+1] = min(dp[j+1], used+reloads*k+mag);
            }
            mag = (mag+k*reloads)-w.a;
            used+=w.a;
            if(j==n-1) ans=min(ans,used);
        }
    }
    cout << (ans==oo?-1LL:ans) << '\n';

}