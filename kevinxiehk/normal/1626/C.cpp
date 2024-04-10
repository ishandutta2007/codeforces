#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1005; // REMEMBER TO CHANGE UPPER BOUND
int mod = 1000000007, mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], k[maxn + 5];
void mod998() {swap(mod, mod2);}
bool isprime(int k) {
    for(int i = 2; i * i <= k; i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2); 
    return (b % 2 == 1 ? t * t % mod * a % mod : t * t % mod);
}
int inv(int a) {return bm(a, mod - 2);}
int ncr(int n, int r) {
    return (r > n ? 0LL : fac[n] * invfac[r] % mod * invfac[n - r] % mod);
}
void pre_fac(int n) {
    fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
void pre_invfac(int n) {
    for(int i = 0; i <= n; i++) invfac[i] = inv(fac[i]);
}
void solve(int TC) {
    cin >> n;
    int h[1005];
    h[0] = k[0] = 0;
    for(int i = 1; i <= n; i++) cin >> k[i]; // 1 BASED!!
    for(int i = 1; i <= n; i++) cin >> h[i]; // 1 BASED!!
    // int dp[n + 5][n + 5]; // min cost: first i monsters, last pause before jth monster
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= n; j++) dp[i][j] = inf;
    // }
    // dp[0][0] = 0;
    // dp[1][1] = h[1] * (h[1] + 1) / 2;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = i; j > 0; j--) {
    //         if(h[j] - h[j - 1] > k[j] - k[j - 1]) continue;
    //         dp[i][j] = min(dp[i][j], dp[j - 1][])
    //     }
    // }
    // rewrite aaaa
    // ic dont 3-2 me in 20 mins aaaaaa
for(int _ = 0; _ <= n; _++){
    for(int i = n; i > 1; i--) {
        int need = h[i] - (k[i] - k[i - 1]);
        h[i - 1] = max(h[i - 1], need);
        int d = k[i] - k[i - 1];
        // cout << d << '\n';
        if(need > 0) {
            h[i] = max(h[i - 1] + d, h[i]);
        }
    }
}
    // for(int i = 1; i <= n; i++) cout << h[i] << '\n';
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(i != 1 && h[i] - h[i - 1] == k[i] - k[i - 1]) {
            int f = h[i - 1] + 1;
            int l = h[i];
            int t = h[i] - h[i - 1];
            ans += (f + l) * t / 2;
            // int d = h[i] - h[i - 1];
            // int th = h[i] + h[i - 1];
            // ans += d * th / 2;
        }
        else {
            ans += h[i] * (h[i] + 1) / 2;
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}