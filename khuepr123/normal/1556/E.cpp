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
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int maxi[25][maxN];
int mini[25][maxN];
int lg2[maxN];

int xr(int le, int ri){
    ++ri;
    int ds = lg2[ri - le];
    return max(maxi[ds][le], maxi[ds][ri - (1 << ds)]);
}

int nr(int le, int ri){
    ++ri;
    int ds = lg2[ri - le];
    return min(mini[ds][le], mini[ds][ri - (1 << ds)]);
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n) cin >> a[i];
    for1(i, 1, n){
        cin >> x; a[i] -= x;
    }
    a[0] = 0;
    lg2[0] = -1;
    for1(i, 1, n){
        a[i] += a[i - 1];
    }
    for1(i, 1, maxN - 1){
        lg2[i] = lg2[i / 2] + 1;
    }
    for1(i, 0, n){
        maxi[0][i] = a[i];
        mini[0][i] = a[i];
    }
    for1(ds, 0, 20){
        for1(i, 0, n + 1 - (1 << (ds + 1))){
            maxi[ds + 1][i] = max(maxi[ds][i], maxi[ds][i + (1 << ds)]);
            mini[ds + 1][i] = min(mini[ds][i], mini[ds][i + (1 << ds)]);
        }
    }
    // max <= pre;
    // pre - min = ans
    while(o--){
        cin >> x >> y; --x;
        int mxi = xr(x, y);
        int mni = nr(x, y);
        // cout << mxi << " " << mni << endl;
        if(a[x] != mxi || a[x] != a[y]) cout << "-1\n";
        else cout << abs(mni - a[x]) << endl;
    }
}