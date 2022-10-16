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
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.fi.se > b.fi.se;
}
void solve(int TC) {
    int n;
    cin >> n;
    pair<pair<int, int>, int> arr[n + 5], arr2[n + 5];
    
    for(int i = 0; i < n; i++) cin >> arr[i].fi.fi;
    for(int i = 0; i < n; i++) cin >> arr[i].fi.se;
    for(int i = 0; i < n; i++) arr[i].se = i;
    for(int i = 0; i < n; i++) arr2[i] = arr[i];
    bool can[n + 5];
    for(int i = 0; i < n; i++) can[i] = false;
    // for(int i = 0; i < n; i++) conn[i].clear();
    sort(arr, arr + n);
    reverse(arr, arr + n);
    sort(arr2, arr2 + n, cmp);
    int amin = arr2[0].fi.fi, bmin = arr[0].fi.se;
    can[arr[0].se] = can[arr2[0].se] = true;
    int pt1 = 1, pt2 = 1;
    while((pt1 < n && arr[pt1].fi.fi >= amin) || (pt2 < n && arr2[pt2].fi.se >= bmin)) {
        if(pt1 < n && arr[pt1].fi.fi >= amin) {
            bmin = min(bmin, arr[pt1].fi.se);
            can[arr[pt1].se] = true;
            pt1++;
        }
        else {
            amin = min(amin, arr2[pt2].fi.fi);
            can[arr2[pt2].se] = true;
            pt2++;
        }
    }
    for(int i = 0; i < n; i++) cout << (can[i] ? '1' : '0');
    cout << '\n';
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