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

int cnt[2005];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        int tot = 0;
        for1(i, 0, n) cnt[i] = 0;
        for1(i, 1, n) for1(j, 1, n){
            char c; cin >> c;
            bool cac = (c == '1');
            if(cac) ++tot;
            if(cac) cnt[(i - j + n) % n]++;
        }
        x = 0;
        for1(i, 0, n - 1) x = max(x, cnt[i]);
        cout << (n - x) + (tot - x) << endl;
    }
}