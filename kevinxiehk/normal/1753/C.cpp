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
int invv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
const int mod = 998244353;
void solve(int TC) {
    int n;
    cin >> n;
    int arr[n + 5];
    int brr[n + 5];
    int cn = 0, inv = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i];
        // if(arr[i]) cn++;
        // else inv += cn;
    }
    sort(brr, brr + n);
    for(int i = 0; i < n; i++) if(arr[i] != brr[i]) inv++;
    inv /= 2;
    int add = 0;
    if(inv == 0) {
        cout << "0\n";
        return;
    }
    int sum = 0;
    double estimate = 0;
    for(int i = 0; i < inv; i++) {
        sum += invv((i + 1) * (i + 1) % mod, mod);
        sum %= mod;
        estimate += 1. / (i + 1) / (i + 1);
    }
    sum %= mod;
    int t = n * (n - 1) / 2;
    t %= mod;
    cout << t * sum % mod << '\n';
    // cout << estimate * t << '\n';
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