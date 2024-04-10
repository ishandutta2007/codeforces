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
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}
int aaa[90005];
int count(int l, int r) {
    int t = 0;
    for(int i = l; i <= r; i++) t += (aaa[i] ^ 1);
    return t;
}
void solve(int TC) {
    for(int i = 0; i <= 300; i++) aaa[i] = 0;
    int n, m;
    cin >> n >> m;
    pair<int, int> arr[n * m + 5];
    for(int i = 0; i < n * m; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr, arr + n * m, cmp);
    int ans = 0;
    for(int i = 0; i < n * m; i++) {
        ans += count(arr[i].se + 1, n * m - 1);
        aaa[arr[i].se]++;
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