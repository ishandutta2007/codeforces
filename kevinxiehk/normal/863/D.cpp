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
int q, m;
void solve(int TC) {
    cin >> n; // I forgot how to use my template ; . ;
    cin >> q >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
    int ar[m + 5];

    // m = n;
    // int ar[n + 5];
    // for(int i = 0; i < n; i++) ar[i] = i + 1;
    pair<int, pair<int, int>> ops[q + 5];
    for(int i = 0; i < q; i++) cin >> ops[i].fi >> ops[i].se.fi >> ops[i].se.se;
    for(int i = 0; i < m; i++) cin >> ar[i];
    for(int j = q - 1; j >= 0; j--) {
        int t, l ,r;
        // cin >> t >> l >> r;
        t = ops[j].fi;
        l = ops[j].se.fi;
        r = ops[j].se.se;
        if(t == 1) {
            for(int i = 0; i < m; i++) {
                // cout << ar[i] << ' ';
                if(ar[i] <= r && ar[i] >= l) {
                    ar[i]--;
                    if(ar[i] < l) ar[i] = r;
                }
                // cout << ar[i] << "  ";
            }
        }
        else {
            for(int i = 0; i < m; i++) {
                // cout << ar[i] << ' ';
                if(ar[i] <= r && ar[i] >= l) {
                    ar[i] = r - (ar[i] - l);
                }
                // cout << ar[i] << "  ";
            }
        }
        // cout << '\n';
    // for(int i = 0; i < m; i++) cout << arr[ar[i]] << ' '; cout << '\n';
    }
    for(int i = 0; i < m; i++) cout << arr[ar[i]] << ' '; cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}