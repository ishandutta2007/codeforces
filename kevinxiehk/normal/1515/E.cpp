#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
//clock_t ti = clock();
int mod, n;
int p2[405], fac[405], uhfac[405];
int lookup[405][405];
int dp[405][405];
int bm(int a, int b) {
    if(b == 1) return a;
    int t = bm(a, b / 2);
    if(b % 2) return t * t % mod * a % mod;
    else return t * t % mod;
}
int nCrt(int n, int r) {
    if(r > n) return 1;
    return fac[n] * uhfac[r] % mod * uhfac[n - r] % mod;
}
int nCr(int n, int r) {
    if(n < 0) return 0;
    return lookup[n][r];
}
int part(int emp) {
    int m = n - emp;
    if(m * 2 - n - 1 < 0) return 0; 
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) dp[i][0] = nCr(m, i);
    for(int i = 2; i <= n; i++) {
        for(int j = max(1LL, emp - (n - i) / 2); j <= min((i - 1) / 2, emp); j++) {
            for(int k = i - 2; k >= (j - 1) * 2; k--) {
                //cout << i << ' ' << j << ' ' << k << ' ' << m - k + j - 1 << ' ' << i - k - 1 << '\n';
                //fflush(stdout);
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * nCr(m - k + j - 1, i - k - 1)) % mod;
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }
    //cout << emp << ' ' << dp[n][emp] * p2[m * 2 - n - 1] << '\n';
    return dp[n][emp] * p2[m * 2 - n - 1] % mod;
}
void solve() {
    cin >> n >> mod;
    int ans = 0;
    uhfac[0] = fac[0] = p2[0] = 1;
    for(int i = 1; i <= 400; i++) {
        fac[i] = fac[i - 1] * i % mod;
        uhfac[i] = bm(fac[i], mod - 2);
        p2[i] = p2[i - 1] * 2 % mod;
    }
    for(int i = 0; i <= 400; i++) for(int j = 0; j <= 400; j++) lookup[i][j] = nCrt(i, j);
    //ans = part(11);
    for(int i = 0; i <= (n - 1) / 2; i++) ans = (ans + part(i)) % mod;
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    //cout << fixed << setprecision (10) << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << '\n';
    return 0;
}