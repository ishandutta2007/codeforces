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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k, m;

int h[maxN];
int id[maxN];
vector<ii> vc[maxN];
vector<int> cac;
ii ed[maxN];
bool ans[maxN];

void dfs(int node, int par, int tag, int hei){
    // cout << node << " " << par << endl;
    h[node] = hei;
    id[node] = tag;
    if(tag <= m) ans[tag] = 1;
    for(ii cc : vc[node]){
        if(id[cc.fi]){
            if(cc.fi != par) cac.pb(cc.se);
        }
        else dfs(cc.fi, node, cc.se, hei + 1);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        cac.clear();
        for1(i, 1, n){
            vc[i].clear();
        }
        for1(i, 1, m){
            cin >> x >> y;
            vc[x].pb(ii(y, i));
            vc[y].pb(ii(x, i));
            id[i] = 0;
            ed[i] = ii(x, y);
            ans[i] = 0;
        }
        dfs(1, 0, oo, 0);
        vector<int> fs;
        for(int cc : cac){
            fs.pb(ed[cc].fi);
            fs.pb(ed[cc].se);
        }
        sort(all(fs)); fs.resize(unique(all(fs)) - fs.begin());
        if(fs.size() == 3 && cac.size() == 6){
            // cout << "SHIIIT";
            ii best = {-oo, 0};
            for(int cc : fs) best = max(best, ii(h[cc], cc));
            int nd = best.se;
            for(int cc : cac){
                if(ed[cc].fi == nd || ed[cc].se == nd){
                    ans[cc] = 1; break;
                }
            }
            // cout << id[nd] << endl;
            ans[id[nd]] = 0;
        }
        for1(i, 1, m) cout << ans[i]; cout << endl;
    }
}