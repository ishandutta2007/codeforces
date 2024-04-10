
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
const int lim = 1e6;
int ans = -1;

bool killed = 0;

bool chk_x(int vx1, int vx2){
    bool rtv;
    vx2 = vx2 - n - vx1;
    if(vx2 > (n - x) || vx1 < 0) rtv = 0;
    else rtv = 1;
    if(vx1 < 0 || vx2 < 0 || vx1 > x || vx2 > (n - x)) return rtv;
    if((k - vx1) % (n + vx1 + vx2) == 0){
        // cout << vx1 << " " << vx2 << " " << k << " " << x << endl;
        if(killed && vx1 == 0) return 0;
        ans = max(ans, vx1 + vx2);
        return rtv;
    }
    return rtv;
}

void solve_x(int val){
    int rem = k % val;
    chk_x(rem, val);
}

void solve_dumb(int val){
    int l = n;
    int r = n * 2;
    while(l <= r){
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if(chk_x(k - val * mid, mid)) l = mid + 1;
        else r = mid - 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x >> y >> k;
    if(y < x) y += n;
    x = y - x;
    ++x;
    k -= x;
    // n: number of children
    // x: segment
    // k: candy
    if(n <= lim){
        for1(i, n, n * 2) solve_x(i);
    }
    else{
        for1(i, 0, lim) solve_dumb(i);
    }
    ++k; killed = 1;
    if(n <= lim){
        for1(i, n, n * 2) solve_x(i);
    }
    else{
        for1(i, 0, lim) solve_dumb(i);
    }
    cout << ans << endl;
}