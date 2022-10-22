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
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN], tg[maxN];
bool act[maxN];
int x, y, z, k;

int dp[maxN];

map<int, int> mp;
int pre[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for1(i, 1, n){
        cin >> a[i] >> tg[i] >> act[i];
        mp[a[i]] = i;
    }
    for1(i, 1, n){
        int cls = mp.upper_bound(tg[i])->se;
        dp[i] = a[i] - tg[i];
        if(cls != i) dp[i] += pre[i - 1] - pre[cls - 1];
        dp[i] %= mod;
        pre[i] = pre[i - 1] + dp[i];
        pre[i] %= mod;
    }
    int ans = a[n] + 1;
    for1(i, 1, n){
        if(act[i]) ans += dp[i];
    }
    cout << (ans % mod + mod) % mod << endl;
}