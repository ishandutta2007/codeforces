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
int x2, y2, x3, y3, z, k;
int m;
int r, c;

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k >> r >> c;
    int bigg = n * m; int midd = r * c; int smol;
    cin >> x2 >> y2 >> x3 >> y3;
    int val1 = min(x2 + r, x3 + r) - max(x2, x3);
    int val2 = min(y2 + c, y3 + c) - max(y2, y3);
    if(val1 < 0 || val2 < 0) smol = 0;
    else smol = val1 * val2;
    if(x2 == x3 && y2 == y3) cout << pw(k, bigg) << endl;
    else cout << pw(k, bigg - midd) << endl;
}