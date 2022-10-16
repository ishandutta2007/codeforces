#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int n, arr[1000005];    
int MOD = 1000000007;
vector<int> conn[1000005];
bool vi[1000005];
void init(int k) {
    for(int i = 0; i <= k; i++) {
        arr[i] = 0;
        vi[i] = false;
        conn[i].clear();
    }
}
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
int fac[200005];
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
int ncr(int a, int b) {
    return fac[a] * inv(fac[b], MOD) % MOD * inv(fac[a - b], MOD) % MOD;
}
void solve() {  
    int l, r;
    cin >> n >> l >> r;
    l *= -1; l++;
    r -= n; 
    int ans = 0;
    int c1 = n / 2;
    int c2 = n - c1;
    int t = min(l, r);
    l -= t;
    r -= t;
    for(int i = 0; i <= n + 5; i++) {
        int ll, rr;
        ll = rr = 0;
        ll = max(ll, i - l);
        rr = max(rr, i - r);
        if(ll + rr > n) break;
        int tans = 0;
        if(!(ll > c1 || n - ll - rr < c1 - ll)) tans += ncr(n - ll - rr, c1 - ll);
        if(n % 2 != 0) {
            if(!(ll > c2 || n - ll - rr < c2 - ll)) tans += ncr(n - ll - rr, c2 - ll);  
        }
        //cout << i << tans << '\n';
        if(i == 0) ans = (ans + tans * t) % MOD;
        else ans = (ans + tans) % MOD;
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for(int i = 1; i <= 200000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}