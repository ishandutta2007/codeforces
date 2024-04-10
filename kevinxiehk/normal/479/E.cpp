#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1000005; // REMEMBER TO CHANGE UPPER BOUND
// int n;
int mod = 1000000007;
int mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], arr[maxn + 5];
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
int dp[2][5005]; // how to fast transition hm // ah psum
void solve(int TC) {
    // cin >> n;
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
    int a, b, k;
    cin >> n >> a >> b >> k;
    // for(int i = 0; i < 2; i++) for(int j = 0; j <= n; j++) dp[i][j] = 0;
    dp[0][a] = 1;
    for(int i = a; i <= n; i++) dp[0][i] = 1;
    for(int i = 1; i <= k; i++) {
        int ii = (i & 1);
        for(int j = 1; j <= n; j++) {
            dp[ii][j] = 0;
            if(j == b) continue;
            if(j < b) {
                dp[ii][j] += dp[ii ^ 1][j - 1];
                int mid = (j + b - 1) / 2;
                dp[ii][j] += dp[ii ^ 1][mid] - dp[ii ^ 1][j];
            }
            else {
                dp[ii][j] += dp[ii ^ 1][n] - dp[ii ^ 1][j];
                int mid = (j + b) / 2;
                dp[ii][j] += dp[ii ^ 1][j - 1] - dp[ii ^ 1][mid];
            }
        }
        for(int j = 2; j <= n; j++) {
            dp[ii][j] += dp[ii][j - 1];
            dp[ii][j] += mod;
            dp[ii][j] %= mod;
            dp[ii][j] += mod;
            dp[ii][j] %= mod;
        }
    }
    cout << dp[k & 1][n] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}