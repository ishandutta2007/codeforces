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

int tree[maxN];
vector<ii> qr[maxN];
vector<int> vc[maxN];

void inc(int plc, int val){
    while(plc < maxN){
        tree[plc] += val;
        plc += (plc & -plc);
    }
}

void range(int le, int ri, int val){
    inc(le, val);
    inc(ri + 1, -val);
}

int take(int plc){
    int res = 0;
    while(plc){
        res += tree[plc];
        plc -= (plc & -plc);
    }
    return res;
}

void dfs(int node, int par, int h){
    for(ii vole : qr[node]){
        z = vole.fi; y = vole.se;
        range(h, h + y, z);
    }
    a[node] = take(h);
    for(int child : vc[node]){
        if(child == par) continue;
        dfs(child, node, h + 1);
    }
    for(ii vole : qr[node]){
        z = vole.fi; y = vole.se;
        range(h, h + y, -z);
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(tree, 0, sizeof(tree));
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    int o; cin >> o; while(o--){
        cin >> x >> y >> z;
        qr[x].pb(ii(z, y));
    }
    dfs(1, 1, 1);
    for1(i, 1, n) cout << a[i] << " ";
    cout << endl;
}