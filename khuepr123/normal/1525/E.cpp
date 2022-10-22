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
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int arrap[21][maxN];
int ans = 0;

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

void solve(){
    int nope = 1;
    sort(a + 1, a + n + 1);
    for1(i, 1, n){
        x = a[i] - i;
        if(x < 0) nope = 0;
        nope *= x;
        nope %= mod;
    }
    ans += nope;
    // cout << nope << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    int frac = 1;
    for1(i, 1, n){
        for1(j, 1, o){
            cin >> arrap[i][j];
        }
        frac *= i;
        frac %= mod;
    }
    for1(j, 1, o){
        for1(i, 1, n){
            a[i] = arrap[i][j];
        }
        solve();
    }
    ans %= mod;
    // cout << ans << endl;
    ans = (ans * inv(frac)) % mod;
    ans = o - ans;
    cout << (ans % mod + mod) % mod << endl;
}