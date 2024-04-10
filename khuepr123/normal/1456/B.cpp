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

inline int range(int le, int ri){
    return a[ri] ^ a[le - 1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n > 100){
        cout << 1 << endl;
        return 0;
    }
    a[0] = 0;
    for1(i, 1, n){
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    int ans = mod;
    for1(l, 1, n) for1(r, l + 1, n) for1(i, l, r - 1){
        if(range(l, i) > range(i + 1, r)) ans = min(ans, r - l);
    }
    if(ans == mod) cout << "-1\n";
    else cout << ans - 1 << endl;
}