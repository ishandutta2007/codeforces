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
// #define solve(node) (take(in[node]) - take(in[tg[node]]))
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int root;

ii pr[maxN];
int par[maxN];
int tag;
int h[maxN];
int cnt = 1;
int ftree[maxN];
int in[maxN];
int tg[maxN];
vector<int> vc[maxN];

void inc(int plc, int val){
    while(plc <= n){
        ftree[plc] += val;
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

inline int solve(int node){
    return (take(in[node]) - take(tg[node]));
}

void dfs(int node, int pare){
    par[node] = pare;
    h[node] = h[pare] + 1;
    in[node] = ++cnt;
    tg[node] = tag;
    for(int cc : vc[node]){
        if(cc == pare) continue;
        dfs(cc, node);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(ftree, 0, sizeof(ftree));
    for1(i, 1, n) inc(i, 1);
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
        pr[i - 1] = ii(x, y);
    }
    root = 1;
    for1(i, 2, n) if(vc[i].size() > 2) root = i;
    par[root] = 0;
    h[root] = 0;
    in[root] = 1;
    for(int cc : vc[root]){
        tag = cnt;
        dfs(cc, root);
    }

    int o; cin >> o; while(o--){
        cin >> z >> x;
        if(z < 3){
            if(z == 2) z = -1;
            y = pr[x].fi;
            if(par[y] != pr[x].se) y = pr[x].se;
            inc(in[y], z);
        }
        else{
            cin >> y;
            if(x == y){
                cout << 0 << endl;
                continue;
            }
            if(h[x] > h[y]) swap(x, y);
            if(x == root){
                cout << ((solve(y) == h[y]) ? h[y] : -1);
            }
            else if(tg[x] == tg[y]){
                z = h[y] - h[x];
                cout << ((solve(y) - solve(x) == z) ? z : -1);
            }
            else{
                z = h[y] + h[x];
                cout << ((solve(y) + solve(x) == z) ? z : -1);
            }
            cout << endl;
        }
    }
}