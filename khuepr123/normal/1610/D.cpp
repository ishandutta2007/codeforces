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

int pw(int num, int coef){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % mod;
        num = (num * num) % mod;
        coef >>= 1;
    }
    return res;
}

int ost[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
        cin >> n;
        for1(i, 0, 35) ost[i] = 0;
        for1(i, 1, n){
            cin >> a[i];
            if(a[i] % 2 == 0){
                ost[__builtin_ctz(a[i])]++;
            }
        }
        int tot = 0;
        int ans = 0;
        for2(i, 32, 1) if(ost[i]){
            ans -= pw(2, tot);
            tot += ost[i];
            ans += pw(2, tot - 1);
            ans %= mod;
        }
        ans = pw(2, tot) - ans;
        ans = pw(2, n) - ans;
        cout << (ans % mod + mod) % mod << endl;
}