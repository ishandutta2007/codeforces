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

int par[maxN];
vector<int> vc[maxN][2];
int ans;

int find(int i){
    if(par[i] < 0) return i;
    // assert(par[i] != i);
    return par[i] = find(par[i]);
}

void unite(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    par[i] += par[j];
    par[j] = i;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; ans = 0;
    for1(i, 1, n) par[i] = -1;
    for1(i, 2, n){
        cin >> x >> y >> z;
        vc[x][z].pb(i);
        vc[y][z].pb(i);
    }
    for1(i, 1, n) for1(j, 0, 1){
        for(int cc : vc[i][j]) unite(cc, vc[i][j][0]);
    }
    for1(i, 2, n){
        if(par[i] < 0) ans += (par[i] * (par[i] - 1));
    }
    for1(i, 1, n){
        if(vc[i][0].empty() || vc[i][1].empty()) continue;
        x = vc[i][0][0];
        y = vc[i][1][0];
        x = find(x); y = find(y);
        ans += par[x] * par[y];
    }
    cout << ans << endl;
}