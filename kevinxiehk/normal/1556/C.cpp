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
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    bool sth;
    for(int i = 0; i < n; i += 2) {
        int mx = arr[i], mi = 1;
        sth = false;
        for(int j = i + 1; j < n; j++) {
            if(sth) break;
            if(j % 2 == 1) {
                ans += max(0LL, min(arr[j], mx) - mi + 1);
                mx -= arr[j], mi -= arr[j];
                mi = max(0LL, mi);
                if(mx < 0) sth = true;
            }
            else {
                mx += arr[j], mi += arr[j];
            }
            //cout << i << ' ' << j << ' ' << ans << '\n';
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}