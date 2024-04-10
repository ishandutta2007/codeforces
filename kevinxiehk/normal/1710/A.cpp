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
    int n, m, k;
    cin >> n >> m >> k;
    int siz = n * m;
    int arr[k + 5];
    int arr2[k + 5];
    int cnt1 = 0, cnt2 = 0;
    int mi = min(n, m);
    int ma = max(n, m);
    for(int i = 0; i < k; i++) cin >> arr[i];
    for(int i = 0; i < k; i++) {
        arr2[i] = arr[i] / ma;
        arr[i] = arr[i] / mi;
    }
    sort(arr, arr + k);
    reverse(arr, arr + k);
    sort(arr2, arr2 + k);
    reverse(arr2, arr2 + k);
    for(int i = 0; i < k; i++) {
        if(arr[i] > 1) cnt1 += arr[i];
        if(arr2[i] > 1) cnt2 += arr2[i];
    }
    if(ma % 2 == 1 && arr[0] == 2) cnt1 = -1;
    if(mi % 2 == 1 && arr2[0] == 2) cnt2 = -1;
    if(cnt1 >= ma || cnt2 >= mi) cout << "YES\n";
    else cout << "NO\n";

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