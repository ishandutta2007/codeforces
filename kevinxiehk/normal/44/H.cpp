#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1000005; // REMEMBER TO CHANGE UPPER BOUND
int mod = 1000000007, mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], arr[maxn + 5];
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
    string s;
    cin >> s;
    n = s.length();
    // int ans = 0;
    int dp[25][n + 5];
    for(int i = 0; i <= 20; i++) for(int j = 0; j <= n; j++) dp[i][j] = 0;
    for(int i = 0; i <= 9; i++) {
        dp[i][1] = 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 9; j++) {
            // cout << dp[j][i] << ' ';
            int k = j + (s[i] - '0');
            // cout << i << ' ' << j << ' ' << k << ' ' << dp[j][i] << '\n';
            if(k % 2 == 0) {
                dp[k / 2][i + 1] += dp[j][i];
            }
            else {
                dp[k / 2][i + 1] += dp[j][i];
                dp[k / 2 + 1][i + 1] += dp[j][i];
            }
        }
        // cout << '\n';
    }

    // ???

    int ans = 0;
    for(int i = 0; i <= 9; i++) ans += dp[i][n];

    int sem = true;
    // if(s[1] >= s[0] + 5) sem = false;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1] && s[i] != s[i - 1] + 1 && s[i] != s[i - 1] - 1) sem = false;
    }

    ans -= sem;
    cout << ans << '\n';
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}