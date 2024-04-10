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
int b[maxN];

int pre[32][maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    memset(pre, 0, sizeof(pre));
    for1(i, 1, maxN - 1){
        for1(j, 0, 29){
            pre[j][i] = pre[j][i - 1];
            if((i & (1ll << j)) == 0) ++pre[j][i];
        }
    }
    while(o--){
            int l, r;
        cin >> l >> r;
        int ans = oo;
        for1(j, 0, 29) ans = min(ans, pre[j][r] - pre[j][l - 1]);
        cout << ans << endl;
    }
}