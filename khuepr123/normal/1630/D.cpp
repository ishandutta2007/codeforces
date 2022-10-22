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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

bool stat[maxN];
int vle[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n; int o; cin >> o;
        for1(i, 1, n){
            cin >> a[i];
        }
        int avg = 0;
        while(o--){
            cin >> x; avg = __gcd(avg, x);
        }
        for1(i, 0, n){
            stat[i] = 0;
            vle[i] = oo;
        }
        for1(i, 1, n){
            int g = i % avg;
            if(a[i] < 0){
                a[i] = -a[i];
                stat[g] = !stat[g];
            }
            vle[g] = min(vle[g], a[i]);
        }
        int ans = oo;
        for1(dumb, 0, 1){
            int res = 0;
            for1(i, 0, avg - 1) stat[i] = !stat[i];
            for1(i, 0, avg - 1) if(stat[i]) res += vle[i];
            ans = min(ans, res);
        }
        ans = -ans; ans *= 2;
        for1(i, 1, n) ans += a[i];
        cout << ans << endl;
    }
}