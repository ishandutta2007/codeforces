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
int fac[100005];
int invfac[100005];
int mod = 998244353;
int ncr(int n, int r) {
    if(r > n || r < 0) return 0;
    return fac[n] * invfac[r] % mod * invfac[n - r] % mod;
}
void solve(int TC) {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = n - 1;
    int sl = 0, sr = 0;
    vector<pair<int, int>> aa;
    while(r >= l) {
        pair<int, int> t = mp(0, 0);
        while(arr[l] == 0 && l <= r) {
            t.fi++;
            l++;
        }
        if(l > r) t.se--;
        else {
            while(arr[r] == 0 && l <= r) {
                t.se++;
                r--;
            }
        }
        aa.pb(t);
        if(l >= r) break;
        sl += arr[l]; l++;
        sr += arr[r]; r--;
        while(l <= r && sl != sr) {
            if(sl < sr) {
                sl += arr[l]; l++;
            }
            else {
                sr += arr[r]; r--;
            }
        }
        if(l > r && sl == sr) aa.pb(mp(0, -1));
    }
    // for(auto x: aa) cout << x.fi << ' ' << x.se << '\n'; 
    int ans = 1;
    for(int i = 0; i < aa.size(); i++) {
        auto x = aa[i];
        if(i == 0) {
            if(x.se == -1) {
                ans = bm(2, x.fi - 1, mod);
            }
            else {
                int t = 0;
                for(int j = 0; j <= min(x.fi, x.se); j++) {
                    t += ncr(x.fi, j) % mod * ncr(x.se, j) % mod;
                    t %= mod;
                }
                ans = ans * t % mod;
            }
        }
        else {
            if(x.se == -1) {
                ans *= bm(2, x.fi + 1, mod);
                ans %= mod;
            }
            else {
                int t = 0;
                for(int j = 0; j <= min(x.fi, x.se) + 1; j++) {
                    t += ncr(x.fi + 1, j) % mod * ncr(x.se + 1, j) % mod;
                    t %= mod;
                }
                ans = ans * t % mod;
            }
        }
    }
    cout << ans << '\n';
    // cout << "---\n";
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    fac[0] = 1; invfac[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = inv(fac[i], mod);
    }
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}