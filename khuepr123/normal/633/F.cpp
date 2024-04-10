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
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
#define euthan(vale) combo[node] = max(combo[node], vale)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int combo[maxN];
int bong[maxN];
int stick[maxN];
vector<int> vc[maxN];

void decap(vector<int> &v){
    for1(i, 0, 4) v.pb(0);
}

int ans = 0;

void dfs(int node, int par){
    // cout << node << endl;
    combo[node] = 0;
    bong[node] = 0;
    stick[node] = 0;
    vector<int> candbong;
    vector<int> candstick;
    vector<int> candcombo;
    vector<ii> binding;
    decap(candbong);
    decap(candstick);
    decap(candcombo);
    for1(i, 0, 3) binding.pb({0, 0});
    for(int cc : vc[node]) if(cc != par){
        dfs(cc, node);
        euthan(combo[cc]);
        bong[node] = max(bong[node], bong[cc]);
        stick[node] = max(stick[node], stick[cc]);
        candbong.pb(bong[cc]);
        candstick.pb(stick[cc]);
        candcombo.pb(combo[cc]);
        binding.pb(ii(stick[cc], bong[cc]));
    }
    sort(all(binding), greater<ii>());
    for(int i = 4; i < binding.size(); ++i){
        if(binding[i].se > binding[3].se){
            swap(binding[i], binding[3]);
        }
    }
    binding.resize(4);
    for1(i, 0, 3) for1(j, 0, 3) for1(g, 0, 3)
        if(i != j && i != g && j != g){
            int copium = binding[i].fi + binding[j].fi
                    + binding[g].se + a[node];
            ans = max(ans, copium);
        }
    sort(all(candbong), greater<int>());
    sort(all(candstick), greater<int>());
    sort(all(candcombo), greater<int>());
    ans = max(ans, candcombo[0] + candstick[1] + a[node]);
    ans = max(ans, candcombo[1] + candstick[0] + a[node]);
    ans = max(ans, candbong[0] + candbong[1]);
    for(int cc : vc[node]) if(cc != par){
        if(combo[node] == combo[cc] && stick[node] != stick[cc]){
            ans = max(ans, combo[node] + stick[node] + a[node]);
        }
    }
    // throughoutly calculated ans
    for(int cc : vc[node]) if(cc != par){
        if(bong[node] == bong[cc] && stick[node] != stick[cc]){
            euthan(stick[node] + bong[node]);
        }
    }
    euthan(candbong[0] + candstick[1]);
    euthan(candbong[1] + candstick[0]);
    combo[node] += a[node];
    stick[node] += a[node];
    bong[node] = max(bong[node], candstick[0] + candstick[1] + a[node]);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n) cin >> a[i];
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs(2, 0);
    cout << ans << endl;
}