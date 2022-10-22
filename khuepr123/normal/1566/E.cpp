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
// #define endl "\n"
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

vector<int> vc[maxN];
vector<int> bud;
bool isbud[maxN];
bool isleaf[maxN];

void dfs(int node, int par){
    isleaf[node] = 1;
    isbud[node] = 1;
    for(int cc : vc[node]){
        if(cc == par) continue;
        dfs(cc, node);
        if(isbud[cc]) continue;
        if(!isbud[cc]) isleaf[node] = 0;
        if(!isleaf[cc]) isbud[node] = 0;
    }
    if(isleaf[node]) isbud[node] = 0;
    if(node != 1) assert(isbud[node] ^ isleaf[node]);
    if(node == 1){
        isleaf[node] = 0;
        isbud[node] = 0;
    }
    if(isbud[node]){
        int fl = 0;
        for(int cc : vc[node]){
            if(cc == par || isbud[cc]) continue;
            if(isleaf[cc]) ++fl;
        }
        bud.pb(fl);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            vc[i].clear();
            isbud[i] = 0;
            isleaf[i] = 0;
        }
        bud.clear();
        for1(i, 2, n){
            cin >> x >> y;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        dfs(1, 0);
        int ans = 0;
        for(int cc : vc[1]){
            if(!isbud[cc]) ++ans;
        }
        if(ans){
            for(int cc : bud) ans += cc - 1;
            cout << ans << endl;
        }
        else{
            for(int cc : bud) ans += cc - 1;
            if(bud.size() == 0) cout << ans << endl;
            else
            cout << ans + 1 << endl;
        }
    }
}