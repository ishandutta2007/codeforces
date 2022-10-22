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
int b[maxN];
int x, y, z, k;

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        ii ans = {oo, 0};
        int fval = n + k; if(fval & 1) ++fval;
        fval /= 2;
        // limit must surpass
        for1(i, 1, n){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        for1(i, 1, n) if(i >= fval){
            ans = min(ans, ii(a[i] - a[i - fval + 1], i));
        }
        int id = ans.se;
        int l = a[id - fval + 1], r = a[id];
        cout << l << " " << r << endl;
        int sm = 0;
        int chuck = 0;
        cout << "1 ";
        int goal = 1;
        for1(i, 1, n) a[i] = b[i];
        for1(i, 1, n){
            if(a[i] >= l && a[i] <= r) ++sm;
            else --sm;
            if(sm == goal && chuck + 1 < k){
                ++goal;
                cout << i << endl << i + 1 << " ";
                ++chuck;
            }
        }
        cout << n << endl;
    }
}