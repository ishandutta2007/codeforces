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
map<int, int> mp[maxN];
int ans[maxN];

void dfs(int node, int par){
    ans[a[node]]++;
    mp[node][a[node]]++;
    for(int child : vc[node]){
        if(child == par) continue;
        dfs(child, node);
        for(ii ch : mp[child]){
            for(ii chh : mp[node]) ans[__gcd(ch.fi, chh.fi)] += ch.se * chh.se;
        }
        for(ii ch : mp[child]){
            mp[node][__gcd(ch.fi, a[node])] += ch.se;
        }
        mp[child].clear();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(ans, 0, sizeof(ans));
    cin >> n;
    for1(i, 1, n){
        cin >> a[i];
    }
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y); vc[y].pb(x);
    }
    dfs(1, 0);
    for1(i, 1, maxN - 1){
        if(ans[i]) cout << i << " " << ans[i] << endl;
    }
}