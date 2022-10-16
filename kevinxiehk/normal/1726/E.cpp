#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
const int mod = 998244353;
int fac[300005];
int invfac[300005];
int ncr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fac[n] * invfac[r] % mod * invfac[n - r] % mod;
}
void brute(int n) {
    int arr[n + 5];
    for(int i = 1; i <= n; i++) arr[i] = i;
    int inv[n + 5];
    int cnt = 0;
    do{
        for(int i = 1; i <= n; i++) inv[arr[i]] = i;
        bool can = true;
        int prt = 0;
        for(int i = 1; i <= n; i++) {
            if(abs(arr[i] - inv[i]) > 1) can = false;
            if(abs(arr[i] - inv[i]) > 0) prt++;
        }
        cnt += can;
        // if(can && prt == n) {
        //     for(int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
        //     for(int i = 1; i <= n; i++) cout << inv[i] << " \n"[i == n];
        //     cout << '\n';
        // }
    }while(next_permutation(arr + 1, arr + 1 + n));
    cout << "Brute: " << cnt << '\n';
}
void solve(int TC) {
    int n;
    cin >> n;
    // if(n <= 10) brute(n);
    // cycles size <= 2
    // exception: 4 3 1 2 
    int arr[n + 5];
    arr[0] = arr[1] = 1;
    int ans = 0;
    for(int i = 2; i <= n; i++) arr[i] = (arr[i - 1] + (i - 1) * arr[i - 2]) % mod;
    for(int i = 0; i * 4 <= n; i++) {
        int w1 = ncr(n - i * 2, i * 2);
        int nn = i;
        // cerr << w1 << '\n';
        w1 *= fac[nn * 2] % mod;
        w1 %= mod;
        // cerr << w1 << '\n';
        w1 *= invfac[nn] % mod;
        w1 %= mod;
        // cerr << w1 << '\n';
        w1 *= inv(bm(2, nn, mod), mod) % mod;
        w1 %= mod;
        // cerr << w1 << '\n';
        w1 *= arr[n - nn * 4] % mod;
        w1 %= mod;
        w1 *= bm(2, i, mod) % mod;
        w1 %= mod;
        // cerr << w1 << '\n';
        // cerr << w1 << " aaaa" << '\n';
        ans += w1;
    }

    cout << ans % mod << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    fac[0] = invfac[0] = 1;
    for(int i = 1; i <= 300000; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = inv(fac[i], mod);
    }
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}