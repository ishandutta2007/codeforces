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
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int rock, water;

vector<iii> change;

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
        sort(a + 1, a + n + 1);
        // bomman limit
        rock = a[1] * a[n]; water = a[1] + a[n];
        change.clear();
        for1(i, 2, n - 1){
            int cr = a[i] * a[n];
            int cw = a[i] + a[n];
            rock += cr; water += cw;
            cr = a[i] * a[1] - cr;
            cw = a[i] + a[1] - cw;
            change.pb({-a[i], ii(cr, cw)});
        }
        change.pb({oo, ii(0, 0)});
        sort(all(change));
        int le = -oo;
        int ans = -oo;
        for(auto pr : change){
            int ri = pr.fi;
            int pi;
            if(water != 0){
                if(water < 0) pi = le;
                else pi = ri;
                if(abs(pi) == oo) ans = oo;
                else ans = max(ans, pi * water + rock);
            }
            else ans = max(ans, rock);
            le = ri;
            rock += pr.se.fi;
            water += pr.se.se;
        }
        if(ans == oo) cout << "INF\n";
        else cout << ans << endl;
    }
}