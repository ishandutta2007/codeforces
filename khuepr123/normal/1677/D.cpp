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
const ll mod = 998244353;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        for1(i, 1, n){
            cin >> a[i];
        }
        int ans = 1;
        for2(i, n, n - k + 1){
            if(a[i] > 0) ans = 0;
        }
        for1(i, 1, k){
            ans *= i; ans %= mod;
        }
        n -= k;
        for1(i, 1, n){
            int adder;
            if(a[i] == -1) adder = (i + k);
            else if(a[i] == 0){
                adder = k + 1;
            }
            else adder = 1;
            if(a[i] >= i) adder = 0;
            ans *= adder;
            ans %= mod;
        }
        cout << ans << endl;
    }
}