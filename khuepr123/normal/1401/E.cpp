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
const ll mod = 1e9 + 7;
const int lim = 1e6;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int m;

int ftree[maxN * 3];

void upd(int plc){
    while(plc < maxN * 3){
        ++ftree[plc];
        plc += plc & -plc;
    }
}

int take(int plc){
    int res = 0;
    while(plc){
        res += ftree[plc];
        plc -= plc & -plc;
    }
    return res;
}

vector<ii> fl[4];
int ans = 0;

void solve(vector<ii> v1, vector<ii> lst){
    map<int, int> mp;
    sort(v1.begin(), v1.end());
    for(auto &cc : v1){
        cc.fi = lim - cc.fi;
        mp[cc.se] = 0;
    }
    for(auto &cc : lst){
        swap(cc.fi, cc.se);
        mp[cc.se] = 0;
    }
    x = 0; for(auto itr = mp.begin(); itr != mp.end(); ++itr)
    itr->se = ++x;
    for(auto &cc : v1) cc.se = mp[cc.se];
    for(auto &cc : lst) cc.se = mp[cc.se];
    sort(lst.begin(), lst.end());
    lst.insert(lst.begin(), ii(-mod, 0));
    memset(ftree, 0, sizeof(ftree));
    int res = 0;
    for(ii &cc : v1){
        while(lst.back().fi >= cc.fi){
            upd(lst.back().se);
            lst.pop_back();
        }
        res += take(cc.se);
    }
    // cout << res << endl;
    ans += res;
}

/*
|
|
v

------------>

*/

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for1(i, 1, n){
        cin >> y >> x >> z;
        if(x == 0 && z == lim) ++ans;
        ans = ans;
        if(x == 0){
            fl[0].pb(ii(lim - y, z));
        }
        else{
            fl[2].pb(ii(y, lim - x));
        }
    }
    for1(i, 1, m){
        cin >> x >> y >> z;
        if(y == 0 && z == lim) ++ans;
        ans = ans;
        if(y == 0){
            fl[1].pb(ii(x, z));
        }
        else{
            fl[3].pb(ii(lim - x, lim - y));
        }
    }
    // solve(fl[0], fl[1]);
    for1(i, 0, 3) solve(fl[i], fl[(i + 1) % 4]);
    cout << ans + 1 << endl;
}