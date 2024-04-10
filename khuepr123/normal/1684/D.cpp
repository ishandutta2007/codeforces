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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n >> k;
        for1(i, 1, n) cin >> a[i];
        reverse(a + 1, a + n + 1);
        vector<ii> ord;
        for1(i, 1, n){
            ord.pb({a[i] - i, i});
        }
        sort(all(ord), greater<ii>());
        reverse(a + 1, a + n + 1);
        for1(i, 0, k - 1){
            ii pr = ord[i];
            a[n + 1 - pr.se] = -1;
            // cout << pr.se << endl;
        }
        int base = 0;
        int rack = 0;
        // for1(i, 1, n) cout << a[i] << " ";
        // cout << endl;
        for1(i, 1, n){
            if(a[i] == -1) ++base;
            else rack += base + a[i];
        }
        cout << rack << endl;
    }
}