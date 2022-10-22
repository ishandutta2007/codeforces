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
ll mod = 1e9 + 7;
const int maxN = 1005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int cnt[maxN];
int dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z >> mod; for1(i, 1, n) cnt[i] = 2;
    while(z--){
        char c; for1(i, 1, n){
            cin >> c; if(c == '1') cnt[i]--;
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for1(i, 0, 502) for1(j, 0, 1003){
        if(i && j) dp[i][j] += i * j * 2 * dp[i - 1][j];
        if(j) dp[i][j] += (j * (j * 2 - 1)) * dp[i][j - 1];
        if(i > 1) dp[i][j] += ((i * (i - 1)) / 2) * dp[i - 2][j + 1];
        dp[i][j] %= mod;
    }
    int cn1 = 0, cn2 = 0;
    for1(i, 1, n){
        if(cnt[i] == 1) ++cn1;
        if(cnt[i] == 2) ++cn2;
    }
    cout << (dp[cn2][cn1 / 2] % mod + mod) % mod << endl;
}