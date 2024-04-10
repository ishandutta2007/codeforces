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
void solve(int TC) {
    int n;
    cin >> n;
    if(n & 1) {
        cout << "2\n";
        return;
    }
    int k = 1;
    while(n % (k * 2) == 0) k *= 2;
    int rem = n / k;
    if(rem <= 2e9 && rem * (rem + 1) <= n * 2 && rem != 1) {
        cout << rem << '\n';
        return;
    }
    else if(rem != 1 && k * (k * 2 + 1) <= n) {
        cout << k * 2 << '\n';
    }
    else cout << "-1\n";
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    // for(int i = 1; i < 10000000; i++) {
    //     int n = i;
    //     int an = -1;
    //     for(int j = 2; j * (j + 1) / 2 <= n; j++) {
    //         if((j * (j + 1) / 2) % j == n % j) {
    //             an = j;
    //             break;
    //         }
    //     }
    //     int k = 1;
    //     int ann = 1;
    //     while(n % (k * 2) == 0) k *= 2;
    //     int rem = n / k;
    //     if(rem <= 2e9 && rem * (rem + 1) <= n * 2 && rem != 1) {
    //         // cout << rem << '\n';
    //         // return;
    //     }
    //     else if(rem != 1 && k * (k * 2 + 1) <= n) {
    //         // cout << k * 2 << '\n';
    //     }
    //     else ann = -1;
    //     // if(an == -1) cout << i << '\n';
    //     // cout << n << ' ' << an << '\n';
    //     if(an != -1 && ann == -1) {
    //         cout << i << ' ' << an << '\n';
    //     }
    // }return 0;
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}