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
int n;
int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};
bool valid(int x, int y) {
    if(max(x, y) >= n || min(x, y) < 0) return false;
    return true;
}
void solve(int TC) {
    cin >> n;
    int ans = 0;
    int cnt[n + 5][n + 5];
    int arr[n + 5][n + 5];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j], cnt[i][j] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cnt[i - 1][j] % 2 == 0) {
                ans ^= arr[i][j];
                for(int k = 0; k < 4; k++) {
                    if(valid(i + dx[k], j + dy[k])) cnt[i + dx[k]][j + dy[k]]++;
                }
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