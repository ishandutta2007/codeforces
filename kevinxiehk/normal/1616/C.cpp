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
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = n - 1;
    if(n == 1) {
        cout << "0\n";
        return;
    }
    // for(int st = -100; st <= 100; st++) {
        for(int dk = 0; dk < n; dk++) {
            int st = arr[dk];
            for(int gap = -100; gap <= 100; gap++) {
                for(int inter = 1; inter < n; inter++) {
                    int cnt = 0, tc = 0;
                    for(int i = dk; i < n; i += inter) {
                        if(abs(gap * cnt + st) > 100) break;
                        if(arr[i] != gap * cnt + st) tc++;
                        cnt++;
                    }
                    tc += (n - cnt);
                    ans = min(ans, tc);
                }
            }
        }
    // }
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