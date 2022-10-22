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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int dp[maxN]; // max profit from subtree i
int nxt[25][maxN]; // profit going up
int contrib[maxN];
int clutch[maxN];
int par[25][maxN];
vector<ii> vc[maxN];
int h[maxN];
int path[maxN];

int ans;
void inc(int &node, int &jp){
    ans += nxt[jp][node];
    node = par[jp][node];
}

void dfs(int node, int pare){
    par[0][node] = pare;
    h[node] = h[pare] + 1;
    dp[node] = a[node];
    for(ii cc : vc[node]){
        int child = cc.se;
        if(child == pare) continue;
        dfs(child, node);
        x = dp[child] - cc.fi * 2;
        x = max(x, 0ll);
        contrib[child] = x;
        dp[node] += x;
        path[child] = cc.fi;
    }
    for(ii cc : vc[node]){
        int child = cc.se;
        if(child == pare) continue;
        nxt[0][child] = dp[node] - cc.fi - contrib[child];
    }
}

void dfs2(int node, int pare){
    for(ii cc : vc[node]){
        int child = cc.se;
        if(child == pare) continue;
        clutch[child] = max(0ll, clutch[node] + nxt[0][child] - cc.fi);
        dfs2(child, node);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 2, n){
        cin >> x >> y >> z;
        vc[x].pb({z, y});
        vc[y].pb({z, x});
    }
    h[0] = -1;
    dfs(1, 0);
    clutch[1] = 0;
    dfs2(1, 0);
    par[0][0] = 0;
    for1(ds, 0, 20){
        for1(i, 1, n){
            par[ds + 1][i] = par[ds][par[ds][i]];
            nxt[ds + 1][i] = nxt[ds][i] + nxt[ds][par[ds][i]];
        }
    }
    while(o--){
        cin >> x >> y;
        if(h[x] < h[y]) swap(x, y);
        int vole = h[x] - h[y];
        // cout << x << " " << y << endl;
        ans = dp[x];
        for1(i, 0, 20){
            if(vole & (1 << i)) inc(x, i);
        }
        if(x == y) z = x;
        else{
            ans += dp[y];
            for2(i, 20, 0){
                if(par[i][x] != par[i][y]){
                    inc(x, i);
                    inc(y, i);
                }
            }
            z = par[0][y];
            ans += dp[z] - contrib[x] - contrib[y] - path[x] - path[y];
        }
        cout << ans + clutch[z] << endl;
    }
}