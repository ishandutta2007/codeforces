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
const ll mod = 998244353;
const int maxN = 9000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int chr[23][26];

int dp[1 << 23];

void dfs(int mask, vector<int> &vl){
    dp[mask] = -1; if(__builtin_popcount(mask) & 1) dp[mask] = 1;
    for1(i, 0, 25) dp[mask] = (dp[mask] * vl[i]) % mod;
    vector<int> vl2;
    for1(i, 0, n - 1){
        if(mask & (1 << i)) break;
        vl2 = vl; for1(j, 0, 25) vl2[j] = min(vl2[j], chr[i][j]);
        dfs(mask | (1 << i), vl2);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(chr, 0, sizeof(chr));
    for1(i, 0, n - 1){
        string s; cin >> s;
        for(char c : s) chr[i][c - 'a']++;
        for1(j, 0, 25) chr[i][j]++;
    }
    vector<int> chim;
    for1(i, 0, 25) chim.pb(mod);
    dfs(0, chim);
    for1(i, 0, n - 1){
        for1(mask, 0, (1 << n) - 1) if(mask & (1 << i)){
            dp[mask] += dp[mask ^ (1 << i)];
        }
    }
    int ans = 0;
    int sm;
    for1(mask, 0, (1 << n) - 1){
        x = (dp[mask] % mod + mod) % mod;
        // cout << x << endl;
        sm = 0;
        int vl = __builtin_popcount(mask);
        for1(i, 0, n - 1) if(mask & (1 << i)) sm += i;
        ans ^= x * vl * (sm + vl);
    }
    cout << ans << endl;
}