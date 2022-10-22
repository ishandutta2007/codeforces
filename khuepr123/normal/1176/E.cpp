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

vector<int> vc[maxN];
set<int> ans;
bool used[maxN];
void dfs(int node, bool fal){
    if(fal) ans.insert(node);
    used[node] = 1;
    for(int child : vc[node]){
        if(used[child]) continue;
        dfs(child, !fal);
    }
}
int m;

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        for1(i, 1, n){
            vc[i].clear();
            used[i] = 0;
        }
        for1(i, 1, m){
            cin >> x >> y;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        ans.clear();
        dfs(1, 0);
        if(ans.size() > n / 2){
            set<int> ans2;
            for1(i, 1, n){
                if(ans.find(i) == ans.end()) ans2.insert(i);
            }
            ans = ans2;
        }
        cout << ans.size() << endl;
        for(int cc : ans) cout << cc << " ";
        cout << endl;
    }
}