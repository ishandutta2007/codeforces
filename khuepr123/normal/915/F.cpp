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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int par[maxN];
vector<int> vc[maxN];

int find(int i){
    if(par[i] < 0) return i;
    else return par[i] = find(par[i]);
}

void unite(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    par[i] += par[j];
    par[j] = i;
}

int solve(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int ans = 0;
    for1(i, 1, n){
        par[i] = -1;
        pq.push(ii(a[i], i));
    }
    while(!pq.empty()){
        int node = (pq.top()).se; pq.pop();
        int cn = 1;
        int tot = 0;
        for(int cc : vc[node]){
            x = find(cc);
            if(ii(a[node], node) < ii(a[cc], cc)) continue;
            tot -= cn * par[x];
            cn -= par[x];
            unite(x, node);
        }
        // cout << node << " " << tot << endl;
        ans += tot * a[node];
    }
    return ans;
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
    int ans = solve();
    // cout << ans << endl;
    for1(i, 1, n) a[i] = -a[i];
    ans += solve();
    cout << ans << endl;
}