/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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
#define ld long double
const ll mod = 1e9 + 7;
const int maxN = 600005;
const ll oo = 3e18 + 7;
int n, a[maxN];
int x, y, z, k;

int liy, lia, lib;
int pre[maxN];
map<ld, int> mp;

vector<ld> vac;

pair<int, ld> accrue(int cx){
    int v1 = cx * y + x * liy;
    int v2 = liy + y;
    ld frc = (ld)v1 / (ld)v2;
    vac.pb(frc);
    auto ptr = mp.lower_bound(frc);
    assert(ptr != mp.end());
    auto pr = *ptr;
    // cout << pr.fi << " " << pr.se << endl;
    ld lost = (ld)0;
    if(pr.se % 2 == 0) lost = pr.fi - frc;
    return {pr.se, lost};
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> liy >> lia >> lib >> n;
    liy = -liy;
    pre[0] = 0;
    for1(i, 1, n){
        cin >> x >> y;
        pre[i * 2 - 1] = pre[i * 2 - 2];
        pre[i * 2] = pre[i * 2 - 1] + (y - x);
        mp[(ld)x] = i * 2 - 1;
        mp[(ld)y] = i * 2;
    }
    pre[n * 2 + 1] = pre[n * 2];
    mp[(ld)oo] = n * 2 + 1;
    cout << fixed << setprecision(7);
    int o; cin >> o; for1(cas, 1, o){
        vac.clear();
        cin >> x >> y;
        auto p1 = accrue(lia);
        auto p2 = accrue(lib);
        ld ans = p1.se - p2.se;
        ans += (ld)(pre[p2.fi] - pre[p1.fi]);
        cout << ans * (ld)(abs(lia - lib)) / (vac[1] - vac[0]) << endl;
    }
}