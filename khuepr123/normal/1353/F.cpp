/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[105][105];
int x, y, z, k;
int m;
int ans = oo;
int dp[105][105];
void solve(int vl){
    memset(dp, 125, sizeof(dp));
    dp[1][0] = 0;
    for1(i, 1, n){
        for1(j, 1, m){
            if(a[i][j] >= vl)
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + a[i][j] - vl;
        }
    }
    ans = min(ans, dp[n][m]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        ans = oo;
        cin >> n >> m;
        for1(i, 1, n) for1(j, 1, m){
            cin >> a[i][j];
            a[i][j] -= (i + j);
        }
        for1(i, 1, n) for1(j, 1, m){
            solve(a[i][j]);
        }
        cout << ans << endl;
    }
}