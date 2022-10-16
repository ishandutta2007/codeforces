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
int ask(int k) {
    cout << "? " << k << endl;
    fflush(stdout);
    int a;
    cin >> a;
    return a;
}
void solve(int TC) {
    int n;
    cin >> n;
    int l = 1, r = 1000000000;
    while(l < r) {
        int mid = (l + r) / 2;
        if(ask(mid) == 1) r = mid;
        else l = mid + 1;
    }
    // cout << l << '\n';
    for(int i = 2; i <= n; i++) {
        // i lines;
        int k = (r - 1) / i;
        int x = ask(k);
        if(x * k <= l && x != 0) {
            l = k * x;
        }
    }
    cout << "! " << l << endl;
}
signed main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}