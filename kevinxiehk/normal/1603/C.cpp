#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ll long long
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
int mod = 998244353;
void solve(int TC) {
    int n;
    cin >> n;
    int arr[n + 5];
    ll ans = 0;
    unordered_map<int, int> dk[2];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(ll i = n - 1; i >= 0; i--) {
        for(auto x: dk[(i & 1) ^ 1]) {
            ll k = (arr[i] + x.fi - 1) / x.fi;
            ans += (k - 1) * (i + 1) * x.se;
            dk[i & 1][arr[i] / k] += x.se;
        }
        dk[i & 1][arr[i]]++;
        ans %= mod;
        dk[(i & 1) ^ 1].clear();
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}