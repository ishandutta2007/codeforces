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
    vector<int> arr;
    int n, t;
    cin >> n;
    bool aa = false;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t) aa = true;
        if(aa) arr.pb(t);
    }
    n = arr.size();
    if(n == 0) {
        cout << "0\n";
        return;
    }
    int zero[n + 5], one[n + 5];
    zero[0] = one[0] = 0;
    for(int i = 0; i < n; i++) {
        one[i + 1] = one[i];
        zero[i + 1] = zero[i];
        if(arr[i] == 0) zero[i + 1]++;
        else one[i + 1]++;
    }
    int ans = inf;
    for(int i = 0; i <= n; i++) {
        ans = min(ans, max(one[i], zero[n] - zero[i]));
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