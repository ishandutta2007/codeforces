#pragma GCC optimize("Ofast")
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
    int n, k; cin >> n >> k;
    int way[n + 5][2];
    int ans[n + 5];
    for(int i = 0; i <= n; i++) way[i][0] = way[i][1] = 0;
    for(int i = 0; i <= n; i++) ans[i] = 0;
    way[0][0] = 1;
    way[0][1] = 1;
    const int mod = 998244353;
    int sm = 0;
    for(int i = k; max(i, sm) <= n; i++) {
        // cerr << i << '\n';
        sm += i;
        for(int k = 0; k <= n; k++) way[k][i & 1] = 0;
        for(int j = 0; j < i; j++) {
            for(int k = j + i; k <= n; k += i) {
                way[k][i & 1] = (way[k - i][(i & 1) ^ 1] + way[k - i][i & 1]) % mod;
                ans[k] += way[k][i & 1];
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] % mod << ' ';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}