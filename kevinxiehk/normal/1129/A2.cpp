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
    cin >> n;
    int m;
    cin >> m;
    vector<int> lef[n + 5];
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        int di = b - a;

        if(di < 0) di += n;
        lef[a].pb(di);
        // cout << di << '\n';
    }
    for(int i = 1; i <= n; i++) lef[i].pb(n);
    for(int i = 1; i <= n; i++) sort(lef[i].begin(), lef[i].end());
    int need[n + 5];
    for(int i = 1; i <= n; i++) {
        need[i] = ((int)lef[i].size() - 2) * n + lef[i][0];
        // cout << need[i] << ' ';
    }
    // cout << '\n';
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = i; j < i + n; j++) {
            int tt = j;
            if(tt > n) tt -= n;
            if(need[tt] > 0)ans = max(ans, need[tt] + j - i);
        }
        cout << ans << ' ';
    }
    cout << '\n';
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}