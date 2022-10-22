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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = oo;
    for1(i, 1, n) cin >> a[i];
    for1(mid, 1, n){
        int res = 0;
        int pval = 0;
        for2(i, mid - 1, 1){
            ++pval;
            int cum = pval / a[i] * a[i];
            if(cum < pval) cum += a[i];
            pval = cum;
            res += pval / a[i];
        }
        pval = 0;
        for1(i, mid + 1, n){
            ++pval;
            int cum = pval / a[i] * a[i];
            if(cum < pval) cum += a[i];
            pval = cum;
            res += pval / a[i];
        }
        ans = min(ans, res);
        // cout << res << endl;
    }
    cout << ans << endl;
}