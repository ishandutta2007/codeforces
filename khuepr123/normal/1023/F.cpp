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
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 500005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int par[maxN];
int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

vector<int> vc[maxN];

vector<iii> qry;

int sz[maxN];
int in[maxN], out[maxN], nxt[maxN];
int h[maxN];
int cnt = 0;

void dfs_sz(int node, int pare){
    h[node] = h[pare] + 1;
    sz[node] = 1;
    par[node] = pare;
    for(int &cc : vc[node]) if(cc == pare) swap(cc, vc[node].back());
    if(vc[node].back() == pare) vc[node].pop_back();
    for(int &cc : vc[node]){
        dfs_sz(cc, node);
        sz[node] += sz[cc];
        if(sz[cc] > sz[vc[node][0]]) swap(cc, vc[node][0]);
    }
}

void dfs_hld(int node){
    in[node] = ++cnt;
    for(int cc : vc[node]){
        nxt[cc] = (cc == vc[node][0] ? nxt[node] : cc);
        dfs_hld(cc);
    }
    out[node] = cnt;
}

int tree[maxN * 4];
int l[maxN * 4], r[maxN * 4];

void build(int node, int left, int right){
    l[node] = left;
    r[node] = right;
    tree[node] = oo;
    if(left == right) return; int mid = (left + right) >> 1;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

int truetag;

void label(int node, int left, int right){
    if(left > right) return;
    if(left == l[node] && right == r[node]){
        tree[node] = truetag; return;
    }
    int mid = r[node * 2];
    label(node * 2, left, min(mid, right));
    label(node * 2 + 1, max(left, mid + 1), right);
}

int ans = 0;
void spat(int node){
    if(l[node] == r[node]){
        if(l[node] == 1) return;
        if(tree[node] == oo) ans = -oo;
        else ans += tree[node];
        // cout << tree[node] << endl;
        return;
    }
    tree[node * 2] = min(tree[node * 2], tree[node]);
    tree[node * 2 + 1] = min(tree[node * 2 + 1], tree[node]);
    spat(node * 2);
    spat(node * 2 + 1);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> z;
    for1(i, 1, n) par[i] = i;
    while(k--){
        cin >> x >> y;
        vc[x].pb(y); vc[y].pb(x);
        par[find(x)] = find(y);
    }
    k = z;
    while(k--){
        cin >> x >> y >> z;
        if(find(x) != find(y)){
            par[find(x)] = find(y); ans -= z;
            vc[x].pb(y);
            vc[y].pb(x);
        }
        qry.pb({z, ii(x, y)});
    }
    h[0] = 0;
    nxt[1] = 1;
    dfs_sz(1, 0);
    dfs_hld(1);
    reverse(all(qry));
    build(1, 1, n);
    for(iii cc : qry){
        truetag = cc.fi;
        x = cc.se.fi; y = cc.se.se;
        // cout << x << " " << y << endl;
        while(nxt[x] != nxt[y]){
            if(h[nxt[x]] < h[nxt[y]]) swap(x, y); // x lower;
            // cout << x << " " << nxt[x] << endl;
            label(1, in[nxt[x]], in[x]); x = par[nxt[x]];
        }
        if(h[x] < h[y]) swap(x, y); // x lower
        // cout << y << " " << x << endl;
        // cout << in[y] << " " << in[x] << endl;
        label(1, in[y] + 1, in[x]);
    }
    spat(1);
    cout << max(ans, -1ll) << endl;
}