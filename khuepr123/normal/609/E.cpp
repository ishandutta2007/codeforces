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
int m;

map<ii, int> mop;

struct Edge{
    int x, y, z, id;
    Edge(int x, int y, int z, int id): x(x), y(y), z(z), id(id){}
    bool operator < (const Edge &oth){
        return z < oth.z;
    }
};
int total = 0;
int pare[maxN];
int find(int i){
    if(i == pare[i]) return i;
    return pare[i] = find(pare[i]);
}

int ans[maxN];
vector<Edge> fs;
vector<int> vc[maxN];

void unite(int i, int j, int ww, int id){
    if(find(i) == find(j)){
        ans[id] = id;
        fs[id] = {i, j, ww, id};
        return;
    }
    pare[find(i)] = find(j);
    vc[i].pb(j);
    vc[j].pb(i);
    total += ww;
}
vector<Edge> qrord;

int h[maxN];
int sparse[maxN][25];
int par[maxN][25];

void dfs(int node){
    for(int child : vc[node]){
        if(child == par[node][0]) continue;
        par[child][0] = node;
        h[child] = h[node] + 1;
        sparse[child][0] = mop[ii(child, node)];
        dfs(child);
    }
}

void inc(int &res, int &xx, int ic){
    res = max(res, sparse[xx][ic]);
    xx = par[xx][ic];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for1(i, 1, n){
        pare[i] = i;
    }
    fs.resize(maxN, {0, 0, 0, 0});
    for1(i, 1, m){
        cin >> x >> y >> z;
        qrord.pb({x, y, z, i});
        mop[ii(x, y)] = z;
        mop[ii(y, x)] = z;
    }
    sort(qrord.begin(), qrord.end());
    memset(ans, 0, sizeof(ans));
    for(Edge cc : qrord){
        unite(cc.x, cc.y, cc.z, cc.id);
    }
    h[1] = 0;
    par[1][0] = 1;
    dfs(1);
    for1(ds, 0, 20){
        for1(i, 1, n){
            int vx = par[i][ds];
            sparse[i][ds + 1] = max(sparse[i][ds], sparse[vx][ds]);
            par[i][ds + 1] = par[vx][ds];
            // if(sparse[2][0] != 2) cout << ds << " " << i << endl;
        }
    }
    for(Edge cc : qrord){
        x = cc.x;
        y = cc.y;
        int res = 0;
        if(h[x] != h[y]){
            if(h[x] < h[y]) swap(x, y);
            int targ = h[x] - h[y] - 1;

            for1(i, 0, 20){
                if(targ & (1 << i)){
                    inc(res, x, i);
                }
            }
            inc(res, x, 0);
            if(x == y){
                ans[cc.id] = total + cc.z - res; continue;
            }
        }
        for2(i, 20, 0){
            if(par[x][i] == par[y][i]) continue;
            inc(res, x, i);
            inc(res, y, i);
        }
        inc(res, x, 0);
        inc(res, y, 0);
        ans[cc.id] = total + cc.z - res;
    }
    for1(i, 1, m){
        cout << ans[i] << endl;
    }
}