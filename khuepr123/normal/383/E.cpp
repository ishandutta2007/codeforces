/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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
const int maxN = 20000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

const int lim = (1 << 24) - 1;
int dp[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));
    while(o--){
        vector<int> dbb;
        for1(i, 0, 2){
            char c; cin >> c; dbb.pb(c - 'a');
        }
        sort(dbb.begin(), dbb.end());
        dbb.resize(unique(dbb.begin(), dbb.end()) - dbb.begin());
        x = dbb.size();
        for1(i, 0, x - 1) a[1 << dbb[i]]++;
        for1(i, 0, x - 1) for1(j, i + 1, x - 1){
            a[(1 << dbb[i]) | (1 << dbb[j])]--;
        }
        if(x == 3) a[(1 << dbb[0]) | (1 << dbb[1]) | (1 << dbb[2])]++;
    }

    for1(i, 0, lim) dp[i] = a[i];
    for1(i, 0, 23) for1(mask, 0, lim){
        if(mask & (1 << i)) dp[mask] += dp[mask ^ (1 << i)];
    }
    int ans = 0;
    for1(mask, 0, lim){
        ans ^= (dp[mask] * dp[mask]);
    }
    cout << ans << endl;
}