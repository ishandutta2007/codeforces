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
const int maxN = 4000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int dp[maxN];
int suf[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> mod;
    memset(dp, 0, sizeof(dp));
    memset(suf, 0, sizeof(suf));
    dp[n] = 1;
    suf[n] = 1;
    for2(i, n - 1, 1){
        dp[i] = suf[i + 1];
        for(int j = 2 * i; j <= n; j += i){
            dp[i] += suf[j] - suf[min(j + (j / i), n + 1)];
            dp[i] %= mod;
        }
        suf[i] = suf[i + 1] + dp[i];
        suf[i] %= mod;
    }
    cout << (dp[1] % mod + mod) % mod << endl;
}