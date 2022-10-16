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
    int n, x, y;
    cin >> n >> x >> y;
    y %= 4;
    x %= 4;
    int a[n + 5];
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] %= 4;
    bool can[5][n + 5][2];
    for(int i = 0; i <= n; i++) for(int j = 0; j < 4; j++) can[j][i][0] = can[j][i][1] = false;
    can[x % 4][0][0] = true;
    can[(x + 3) % 4][0][1] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 3; j++) {
            if(can[j][i - 1][0]) {
                // cout << "A " << i << ' ' << j << '\n';
                can[(j + a[i]) % 4][i][0] = true;
                can[j ^ a[i]][i][0] = true;
            }
            if(can[j][i - 1][1]) {
                // cout << "B " << i << ' ' << j << '\n';
                can[(j + a[i]) % 4][i][1] = true;
                can[j ^ a[i]][i][1] = true;
            }
        }
    }
    if(can[y][n][0]) cout << "Alice\n";
    else cout << "Bob\n";
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