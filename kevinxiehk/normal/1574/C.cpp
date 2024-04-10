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
void solve(int TC) {
    int n; cin >> n;
    int arr[n + 5];
    int sum = 0;
    for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    sort(arr, arr + n);
    arr[n] = LLONG_MAX;
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = n;
        while(l < r) {
            int m = (l + r) / 2;
            if(arr[m] >= x) r = m;
            else l = m + 1;
        }
        int ans1 = LLONG_MAX;
        if(l != n) ans1 = max(0LL, y - (sum - arr[l]));
        int ans2 = LLONG_MAX;
        if(l != 0) ans2 = max(0LL, x - arr[l - 1] + max(0LL, y - sum + arr[l - 1]));
        cout << min(ans1, ans2) << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}