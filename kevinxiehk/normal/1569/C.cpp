#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int mod = 998244353;
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
int fac[200005];
int npr(int n, int r) {
    return fac[n] * inv(fac[n - r], mod) % mod;
}
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    if(arr[0] == arr[1]) {
        cout << fac[n] << '\n';
        return;
    }
    if(arr[0] - arr[1] > 2){
        cout << "0\n";
        return;
    }
    int cnt = 0;
    while(cnt < n - 1 && arr[cnt + 1] == arr[0] - 1) {
        cnt++;
    }
    int ans = fac[n];
    for(int i = 0; i < n - cnt; i++) {
        ans -= npr(n - cnt - 1, i) * fac[n - i - 1];
        ans %= mod;
    }
    ans = (ans + mod) % mod;
    cout << ans << '\n';
    
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for(int i = 1; i <= 200000; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}