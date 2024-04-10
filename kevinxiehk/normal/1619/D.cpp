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
void solve(int TC) {
    int n, m;
    cin >> m >> n;
    int grid[m + 5][n + 5];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    bool flag[m + 5];
    for(int i = 0; i <= m; i++) flag[i] = false;
    int mx[n + 5][2];
    for(int i = 0; i <= n; i++) mx[i][0] = mx[i][1] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            mx[j][0] = max(mx[j][0], grid[i][j]);
        }
    }
    int aaa = INT_MAX;
    for(int i = 0; i < n; i++) aaa = min(aaa, mx[i][0]);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == mx[j][0]) {
                flag[i] = true;
                mx[j][0]++;
                grid[i][j]++;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++) cnt += flag[i];
    if(cnt < n) {
        cout << aaa << '\n';
        return;
    }
    int seb = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = 0; k < m; k++) {
                ans = max(ans, min(aaa, min(grid[k][i], grid[k][j])));
            }
        }
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