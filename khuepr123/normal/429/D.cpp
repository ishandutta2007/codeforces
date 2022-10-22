/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
const int mod = 1e9 + 7;
const int maxN = 300005;
int n, a[maxN];
int x, y, z, k;

int ans = mod;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x; --n;
    // this fucking suck but i still leave it here: a[0] = 0
    for1(i, 1, n){
        cin >> a[i]; a[i] += a[i - 1];
    }
    for1(ds, 1, 4000){
        int res = mod;
        for1(i, ds, n){
            res = min(res, abs(a[i] - a[i - ds]));
        }
        if(res < 20005)
        ans = min(ans, res * res + ds * ds);
    }
    cout << ans << endl;
}