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
#define eb emplace_back
#define ii pair<int, int>
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

ii ans[maxN];
vector<int> vc[maxN];
int par[maxN];
int sub[maxN];

void dfs(int node){
    ++sub[node];
    for(int child : vc[node]){
        if(child == par[node]) continue;
        par[child] = node;
        dfs(child);
        sub[node] += sub[child];
    }
}

void compos(int node, int left, int right){
    ans[node].se = left + vc[node].size();
    for2(i, (int)vc[node].size() - 1, 0){
        int ch = vc[node][i];
        ans[ch].fi = left + (int)vc[node].size() - 1 - i;
    }
    left += vc[node].size();
    for(int ch : vc[node]){
        int sz = sub[ch] * 2 + 1;
        compos(ch, left + 1, left + sz);
        left += sz;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(par, 0, sizeof(par));
    memset(sub, 0, sizeof(sub));
    for1(i, 1, n - 1){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs(1);
    for1(i, 1, n){
        for1(j, 0, (int)vc[i].size() - 1){
            if(vc[i][j] == par[i]){
                vc[i].erase(vc[i].begin() + j);
                break;
            }
        }
    }
    ans[1].fi = 1;
    for1(i, 1, n) --sub[i];
    compos(1, 2, 2 * n);
    for1(i, 1, n){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }

}