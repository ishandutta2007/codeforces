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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int split[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        for1(i, 1, n) cin >> a[i];
        int oldsum = 0;
        int ans = 0;
        for1(r, 1, n){
            // r stop phase
            split[r] = 1;
            for2(i, r - 1, 1){
                int vl = a[i + 1] / split[i + 1];
                // x <= vl * split
                x = a[i];
                y = x / vl;
                if(x % vl) ++y;
                if(split[i] == y) break;
                oldsum -= split[i] * i;
                split[i] = y;
                oldsum += split[i] * i;
                oldsum %= mod;
            }
            ans += oldsum;
            ans %= mod;
        }
        cout << (ans % mod + mod) % mod << endl;
    }
}