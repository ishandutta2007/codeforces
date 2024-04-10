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
#define ld long double
#define EPS 1e-7
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN], b[maxN];
int x, y, z, k;

bool solve(ld ds){
    ld mx = (ld) mod;
    ld mn = (ld)-mod;
    for1(i, 1, n){
        ld cy = (ld)(b[i]) - ds;
        ld dumb = b[i];
        if(cy > ds) return 0;
        cy = sqrt(dumb) * sqrt(ds + ds - dumb);
        mx = min(mx, (ld)a[i] + cy);
        mn = max(mn, (ld)a[i] - cy);
    }
    // cout << mx << " " << mn << endl;
    return mx - mn + EPS > 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        cin >> a[i] >> b[i];
        if(b[i] * b[1] < 0){
            cout << "-1\n";
            return 0;
        }
    }
    for1(i, 1, n){
        b[i] = abs(b[i]);
    }
    ld lef = 0;
    ld rig = oo;
    for1(dumbass, 1, 900){
        ld mid = (lef + rig) / 2;
        if(solve(mid)) rig = mid;
        else lef = mid;
    }
    cout << fixed << setprecision(7) << lef;
}