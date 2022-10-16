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
    int arr[n + 5];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int one = 0, two = 0;
    for(int i = 0; i < n; i++) {
        int d = mx - arr[i];
        one += d % 2;
        two += d / 2;
    }
    int an1;
    if(one > two) {
        an1 = one * 2 - 1;
        // cout <<  << '\n';
    }
    else {
        int t = (one + two * 2) % 3;
        an1 = (one + two * 2) / 3 * 2 + t;
        // cout <<  << '\n';
    }
    
    mx++;
    one = 0, two = 0;
    for(int i = 0; i < n; i++) {
        int d = mx - arr[i];
        one += d % 2;
        two += d / 2;
    }
    int an2;
    if(one > two) {
        an2 = one * 2 - 1;
        // cout <<  << '\n';
    }
    else {
        int t = (one + two * 2) % 3;
        an2 = (one + two * 2) / 3 * 2 + t;
        // cout <<  << '\n';
    }
    cout << min(an1, an2) << '\n';
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