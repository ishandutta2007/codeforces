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

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        map<int, int> mp;
        for1(i, 1, n) cin >> a[i];
        reverse(a + 1, a + n + 1);
        for1(i, 1, n) cin >> b[i];
        reverse(b + 1, b + n + 1);
        vector<ii> acc1;
        a[n + 1] = a[n] + 1;
        x = 0;
        for1(i, 1, n + 1){
            if(i > 1 && a[i] != a[i - 1]){
                acc1.pb(ii(a[i - 1], x));
                x = 1;
            }
            else ++x;
        }
        b[n + 1] = b[n] + 1;
        y = 1;
        bool saved = 1;
        for(ii pr : acc1){
            x = 0;
            while(b[y] == pr.fi){
                ++y; ++x;
            }
            x -= pr.se;
            x += mp[pr.fi]; mp.erase(pr.fi);
            if(x < 0) saved = 0;
            mp[pr.fi] = x;
        }
        if(saved) cout << "YES\n";
        else cout << "NO\n";
    }
}