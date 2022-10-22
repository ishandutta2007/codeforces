#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, m, a[75][75];
int x, y, z, k;
// cnt rem
int dp[75][75];
int mx[75];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for1(i, 0, 71){
        for1(j, 0, 71){
            dp[i][j] = -oo;
            mx[i] = -oo;
        }
    }
    mx[0] = 0;
    for1(i, 1, n){
        for1(j, 1, m){
            cin >> a[i][j];
        }
        for1(j, 0, 71){
            dp[0][j] = mx[j];
        }
        for1(j, 1, m){
            for2(cnt, m / 2, 1){
                for1(rem, 0, k - 1){
                    dp[cnt][rem] = max(dp[cnt][rem],
                    dp[cnt - 1][((rem - a[i][j]) + k * 75) % k] + a[i][j]);
                }
            }
        }
        for2(cnt, m / 2, 0){
            for1(rem, 0, k - 1){
                mx[rem] = max(mx[rem], dp[cnt][rem]);
            }
        }
    }
    
    cout << mx[0];
}