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
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc[maxN];

void dfs(int node, int par, int tag){
    // sum subtree equal tag
    int tot = tag;
    for(int cc : vc[node]) if(cc != par){
        dfs(cc, node, -tag);
        tot -= -tag;
    }
    if(node == 1) tot += -tag;
    a[node] = tot;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n) vc[i].clear();
        for1(i, 2, n){
            cin >> x >> y; vc[x].pb(y);
            vc[y].pb(x);
        }
        dfs(1, 1, 1);
        for1(i, 1, n) cout << a[i] << " ";
        cout << endl;
    }
}