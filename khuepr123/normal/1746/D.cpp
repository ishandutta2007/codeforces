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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> vc[maxN];

ii dfs(int node, int v1){
    int sz = vc[node].size();
    ii ans = ii(v1 * a[node], (v1 + 1) * a[node]);
    if(sz == 0) return ans;
    int fv1 = v1 / sz;
    int sum = 0;
    vector<int> cum;
    for(int cc : vc[node]){
        ii pr = dfs(cc, fv1);
        sum += pr.fi; cum.pb(pr.se - pr.fi);
    }
    ans.fi += sum;
    ans.se += sum;
    sort(all(cum), greater<int>());
    for1(i, v1, v1 + 1){
        int rem = i - sz * fv1;
        int fork = 0;
        for1(j, 0, rem - 1) fork += cum[j];
        if(i == v1) ans.fi += fork;
        else        ans.se += fork;
    }
    return ans;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        for1(i, 1, n){
            vc[i].clear();
        }
        for1(i, 2, n){
            cin >> x; vc[x].pb(i);
        }
        for1(i, 1, n){
            cin >> a[i];
        }
        ii pr = dfs(1, k);
        cout << pr.fi << endl;
    }
}