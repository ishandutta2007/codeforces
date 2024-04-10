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

int b[maxN];

int pre[5005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
        }
        memset(pre, 0, sizeof(pre));
        int ans = 0;
        for2(j, n, 1){
            memset(pre, 0, sizeof(pre));
            for1(i, j + 1, n) ++pre[a[i]];
            for1(i, 1, n) pre[i] += pre[i - 1];
            int res = 0;
            for2(i, j - 1, 2){
                res += pre[a[i] - 1];
                if(a[i - 1] < a[j]) ans += res;
            }
        }
        cout << ans << endl;
    }
}