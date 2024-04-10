#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
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
pair<int, int> arr[200005];
int n;
bool can(int yes) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i].fi >= yes - cnt - 1 && arr[i].se >= cnt) cnt++;
    }
    if(cnt >= yes) return true;
    return false;
}
void solve(int TC) {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    int l = 0, r = n;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(can(m)) l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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