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

int c0[maxN], c1[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 0, n + 1){
            c0[i] = 0;
            c1[i] = 0;
        }
        for1(i, 1, n) cin >> a[i];
        int ans = oo;
        for1(i, 1, n) c1[i] = c1[i - 1] + a[i];
        for2(i, n, 1) c0[i] = c0[i + 1] + 1 - a[i];
        // for1(i, 1, n) cout << c1[i] << " " << c0[i] << endl;
        for1(i, 0, n) ans = min(ans, max(c1[i], c0[i + 1]));
        cout << ans << endl;
    }
}