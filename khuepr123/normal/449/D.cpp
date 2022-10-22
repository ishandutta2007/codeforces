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
const int maxN = 1048575;
const ll oo = 1e18 + 7;
int n, a[maxN + 5];
int x, y, z, k;
 
int dp[maxN + 5];
int pw[maxN + 5];
 
int ans = 0;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for1(i, 1, n){
        cin >> x; dp[x]++;
    }
    pw[0] = 1;
    for1(i, 1, maxN) pw[i] = (pw[i - 1] << 1) % mod;
    for1(ds, 0, 19) for1(mask, 0, maxN){
        if((mask ^ (1 << ds)) > mask) dp[mask] += dp[mask | (1 << ds)];
    }
    ans = 0;
    for1(mk, 0, maxN){
        if(__builtin_popcount(mk) & 1) ans -= pw[dp[mk]];
        else ans += pw[dp[mk]];
        ans %= mod;
    }
    cout << (ans % mod + mod) % mod << endl;
}