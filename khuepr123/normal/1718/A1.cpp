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
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int pre[maxN];
int dp[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        map<int, int> mp;
        for1(i, 1, n) cin >> a[i];
        int ans = 0;
        pre[0] = 0;
        for1(i, 1, n) pre[i] = pre[i - 1] ^ a[i];
        dp[0] = 0;
        mp[0] = 0;
        for1(i, 1, n){
            dp[i] = dp[i - 1];
            if(mp.find(pre[i]) != mp.end()){
                dp[i] = max(dp[i], mp[pre[i]] + 1);
            }
            mp[pre[i]] = dp[i];
        }
        // for1(i, 1, n) cout << dp[i] << " ";
        // cout << endl;
        cout << n - dp[n] << endl;
    }
}