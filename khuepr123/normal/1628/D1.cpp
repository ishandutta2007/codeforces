/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
int n, a[maxN];
int x, y, z, k;
int m;

int dp[2005][2005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // dp[i][j] ith turn, j spell left
    int o; cin >> o; while(o--){
        cin >> n >> m >> k; m = n - m;
        for1(i, 1, n) for1(j, 0, i){
            if(j == i) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = (k * i) % mod;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
            if(dp[i][j] & 1) dp[i][j] += mod;
            dp[i][j] /= 2; dp[i][j] %= mod;
        }
        cout << (dp[n][m] * 2 % mod + mod) % mod << endl;
    }
}