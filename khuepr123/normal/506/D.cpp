/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int blk;
int n, a[maxN];
int x, y, z, k;
int m;

bool used[maxN];
vector<ii> ed[maxN];
vector<int> vc[maxN];

int cnt = 0;
vector<int> stk;
vector<int> stock[maxN];
vector<int> id[maxN];
int loc[maxN];

void dfs(int node){
    used[node] = 1; stk.pb(node);
    for(int cc : vc[node]) if(!used[cc]) dfs(cc);
}

void cock(int root){
    if(!used[root]){
        stk.clear(); dfs(root);
        stock[++cnt] = stk;
    }
}

int ans[500][maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m; blk = sqrt(n);
    for1(i, 1, m){
        cin >> x >> y >> z; ed[z].pb(ii(x, y));;
    }
    memset(used, 0, sizeof(used));
    for1(clr, 1, m){
        for(ii cc : ed[clr]){
            vc[cc.fi].pb(cc.se);
            vc[cc.se].pb(cc.fi);
        }
        for(ii cc : ed[clr]){
            cock(cc.fi); cock(cc.se);
        }
        for(ii cc : ed[clr]){
            vc[cc.fi].clear();
            vc[cc.se].clear();
            used[cc.fi] = 0; used[cc.se] = 0;
        }
    }
    m = cnt;
    for1(i, 1, m){
        for(int cc : stock[i]) id[cc].pb(i);
    }
    memset(loc, 0, sizeof(loc));
    cnt = 0;
    for1(i, 1, n){
        if(id[i].size() >= blk){
            loc[i] = ++cnt;
            for(int idx : id[i]){
                for(int cc : stock[idx]) ++ans[cnt][cc];
            }
        }
    }
    memset(used, 0, sizeof(used));
    int o; cin >> o; while(o--){
        cin >> x >> y; if(loc[y]) swap(x, y);
        if(loc[x]) cout << ans[loc[x]][y] << endl;
        else{
            int res = 0;
            for(int idx : id[x]) used[idx] = 1;
            for(int idx : id[y]) if(used[idx]) ++res;
            for(int idx : id[x]) used[idx] = 0;
            cout << res << endl;
        }
    }
}