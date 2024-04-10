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
int par[maxN];
int h[maxN];

int find(int i){
    if(par[i] == i) return i;
    else return par[i] = find(par[i]);
}

void unite(int i, int j){
    par[find(i)] = find(j);
}

void dfs_intern(int node, int pare, int hei){
    h[node] = hei;
    par[node] = pare;
    ++hei;
    for(int cc : vc[node]) if(cc != pare){
        dfs_intern(cc, node, hei);
    }
}

vector<int> qrym[maxN];
bool isswap[maxN];
bool xr[maxN];
bool used[maxN];
int cnt = 0;
int o;

void safe_game(){
    cout << "YES\n";
    for1(i, 1, o){
        if(isswap[i]) reverse(all(qrym[i]));
        cout << qrym[i].size() << endl;
        for(int cc : qrym[i]) cout << cc << " ";
        cout << endl;
    }
}

bool dfs_con(int node){
    used[node] = 1;
    int cn = 0;
    for(int cc : vc[node]) if(!used[cc]){
        ++cn;
        dfs_con(cc);
    }
    if(cn & 1){
        cnt -= cn / 2;
        return 0;
    }
    else{
        cnt -= cn / 2;
        ++cnt;
        return 1;
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z;
    for1(i, 1, n) par[i] = i;
    memset(xr, 0, sizeof(xr));
    while(z--){
        cin >> x >> y; if(find(x) != find(y)){
            vc[x].pb(y);
            vc[y].pb(x);
            unite(x, y);
            // cout << x << " " << y << endl;
        }
    }
    dfs_intern(1, 0, 0);
    cin >> o;
    for1(i, 1, o){
        cin >> x >> y;
        if(h[x] < h[y]){
            swap(x, y); isswap[i] = 1;
        }
        else isswap[i] = 0;
        vector<int> v1, v2;
        while(h[x] > h[y]){
            v1.pb(x);
            xr[x] = !xr[x];
            x = par[x];
        }
        while(x != y){
            v1.pb(x);
            v2.pb(y);
            xr[x] = !xr[x];
            xr[y] = !xr[y];
            x = par[x];
            y = par[y];
        }
        qrym[i] = v1;
        reverse(all(v2));
        qrym[i].pb(x);
        for(int cc : v2) qrym[i].pb(cc);
        // for1(i, 2, n) cout << xr[i] << " ";
        // cout << endl;
    }
    for1(i, 1, n) vc[i].clear();
    for1(i, 2, n) if(xr[i]){
        vc[i].pb(par[i]);
        vc[par[i]].pb(i);
    }
    memset(used, 0, sizeof(used));
    for1(i, 1, n) if(!used[i]){
        if(dfs_con(i)) --cnt;
    }
    if(cnt) cout << "NO\n" << cnt << endl;
    else safe_game();
}