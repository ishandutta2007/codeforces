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
int n, a[1005][1005];
int x, y, z, k;

int ans = 0;

void solve(){
    int v1 = n / 2 + 1; int v2 = n / 2;
    for1(i, 1, n){
        for1(j, 1, n){
        if((i + j) % 2){
            int ds = max(abs(i - v1), abs(j - v2));
            int cock = v2 - ds;
            if(cock % 4 == 2 || cock % 4 == 1){
                // cout << 1;
                ans ^= a[i][j];
            }
            // else cout << 0;
        }
        // else cout << 0;
        // cout << max(abs(i - v1), abs(j - v2)) << " ";
        }
        // cout << endl;
    }
    // cout << endl;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        ans = 0;
        for1(i, 1, n) for1(j, 1, n) cin >> a[i][j];
        solve();
        for1(i, 1, n / 2) for1(j, 1, n)
            swap(a[i][j], a[n + 1 - i][j]);
        solve();
        cout << ans << endl;
    }
}