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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int dp[maxN];
int toid[maxN];
int fac[maxN];
int inv[maxN];

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

int C(int n, int k){
    if(n >= k && k >= 0){
        return fac[n] * inv[k] % mod * inv[n - k] % mod;
    }
    else return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // diatonic
    memset(dp, 0, sizeof(dp));
    memset(toid, 0, sizeof(toid));
    dp[0] = 1;
    dp[1] = 0;
    for1(i, 2, maxN - 1){
        dp[i] = (dp[i - 2] * (i - 1) * 2ll % mod) % mod;
    }
    toid[0] = 1;
    toid[1] = 1;
    for1(i, 2, maxN - 1){
        toid[i] = (toid[i - 1] + toid[i - 2] * (i - 1) % mod) % mod;
    }
    // for1(i, 1, 4) cout << toid[i] << endl;
    fac[0] = 1;
    for1(i, 1, maxN - 1) fac[i] = fac[i - 1] * i % mod;
    for1(i, 0, maxN - 1) inv[i] = pw(fac[i], mod - 2);
    int o; cin >> o; while(o--){
        cin >> n;
        int ans = 0;
        for1(i, 0, n) if(n - i >= i){
            ans += (C(n - i, i) * dp[i] % mod * toid[n - i - i] % mod);
            // cout << i << " " << C(n - i, i) * dp[i] % mod * toid[n - i - i] << endl;
        }
        cout << (ans % mod + mod) % mod << endl;
    }
}