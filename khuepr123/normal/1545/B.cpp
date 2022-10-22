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
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int fac[maxN];
int inv[maxN];

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
    int o; cin >> o;
    fac[0] = 1;
    for1(i, 1, maxN - 1){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    for1(i, 0, maxN - 1){
        inv[i] = pw(fac[i], mod - 2);
    }
    while(o--){
        cin >> n;
        char c;
        int c0 = -1;
        int c1 = 0;
        int tracker = 0;
        for1(i, 1, n){
            cin >> c;
            a[i] = (c == '1');
        }
        a[++n] = 0;
        for1(i, 1, n){
            if(a[i]) tracker++;
            else{
                c1 += (tracker / 2);
                tracker = 0;
                c0++;
            }
        }
        int ans = fac[c0 + c1];
        ans *= inv[c0]; ans %= mod;
        ans *= inv[c1]; ans %= mod;
        cout << (ans % mod + mod) % mod << endl;
    }
}