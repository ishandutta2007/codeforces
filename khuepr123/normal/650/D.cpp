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
const int maxN = 400005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<ii> qr[maxN];
int pre[maxN];
int ans[maxN];

void solve(int *b, bool flp){
    vector<int> vl;
    vl.pb(-mod);
    for1(i, 1, n){
        for(ii cc : qr[i]){
            // cout << cc.fi << " " << cc.se << "    ";
            // for(int ccc : vl) cout << ccc << " ";
            // val - index answer
            if(cc.fi > vl.back()) ans[cc.se] += vl.size();
            else{
                int vls = lower_bound(all(vl), cc.fi) - vl.begin();
                ans[cc.se] += vls;
            }
            // cout << cc.se << endl;
        }
        if(a[i] > vl.back()) vl.pb(a[i]);
        int ids = lower_bound(all(vl), a[i]) - vl.begin();
        vl[ids] = a[i];
        b[i] = ids;
    }
}

map<int, int> loc[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n) cin >> a[i];
    for1(i, 1, o){
        cin >> x >> y;
        qr[x].pb(ii(y, i));
    }
    solve(pre, 0);
    // for1(i, 1, o) cout << ans[i] << endl;
    x = 0;
    for1(i, 1, n){
        loc[pre[i]][i] = a[i];
        x = max(x, pre[i]);
    }
    k = x;
    loc[x + 1][n + 1] = mod;
    set<int> matter;
    for2(i, x, 1){
        vector<int> trash;
        for(auto cl : loc[i]){
            // cout << cl.fi << " " << cl.se << endl;
            ii pr = *loc[i + 1].lower_bound(cl.fi);
            // cout << pr.fi << " " << pr.se << endl;
            if(pr.se <= cl.se) trash.pb(cl.fi);
        }
        for(int cc : trash) loc[i].erase(cc);
        if(loc[i].size() == 1) matter.insert(loc[i].begin()->fi);
        loc[i][n + 1] = -mod;
    }
    reverse(qr + 1, qr + n + 1);
    reverse(a + 1, a + n + 1);
    for1(i, 1, n) for(ii &cc : qr[i]) cc.fi = 0 - cc.fi;
    for1(i, 1, n) a[i] = -a[i];
    solve(pre, 1);
    reverse(qr + 1, qr + n + 1);
    // for1(i, 1, o) cout << ans[i] << endl;
    for1(i, 1, n){
        int cn = k; if(matter.find(i) != matter.end()) cn = k - 1;
        for(ii cc : qr[i]){
            // cout << i << " " << cc.fi << " " << cc.se << endl;
            ans[cc.se] = max(ans[cc.se] - 1, cn);
        }
    }
    for1(i, 1, o) cout << ans[i] << endl;
}