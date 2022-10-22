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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

int fac[maxN];
int invfac[maxN];

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

int inv(int num){
    return pw(num, mod - 2);
}

int C(int n1, int n2){
    int res = (fac[n1 + n2] * invfac[n1]) % mod;
    return (res * invfac[n2]) % mod;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    fac[0] = 1;
    for1(i, 1, maxN - 1) fac[i] = (fac[i - 1] * i) % mod;
    for1(i, 0, maxN - 1) invfac[i] = inv(fac[i]);
    int inv2 = (mod + 1) / 2;
    while(o--){
        cin >> n >> m >> k; m = n - m;
        if(m == 0) cout << ((n * k) % mod + mod) % mod << endl;
        else if(m == n) cout << 0 << endl;
        else{

        int pivot = n - m;
        int ans = 0;
        for1(i, 1, pivot){
            int ds = pivot - i;
            int res = (pw(inv2, n - i) * C(ds, m - 1)) % mod;
            ans = (ans + res * (k * i % mod)) % mod;
        }
        cout << ans << endl;

        }
    }
}