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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

int lside[maxN];
int rside[maxN];
int cnt = 0;
vector<int> libr;
int addon[maxN];
int sz[maxN];
int egg[maxN];

int ftree[maxN];
void inc(int pos, int val){
    while(pos <= n){
        ftree[pos] += val;
        pos += pos & -pos;
    }
}
int take(int pos){
    int res = 0;
    while(pos){
        res += ftree[pos];
        pos -= pos & -pos;
    }
    return res;
}

struct Snode{
    int l, r;
    int sl = 0, sr = 0; // sum to 2 side
    int trl = 0, trr = 0; // trail to 2 side
    int crew = 0;
    Snode *lchild = nullptr, *rchild = nullptr;
};
Snode tree[maxN * 4];

Snode *segg[maxN];

void merging(Snode& node, Snode& le, Snode& ri){
    node.trl = (le.trl + ri.trl + ri.crew * le.sl) % mod;
    node.trr = (le.trr + ri.trr + le.crew * ri.sr) % mod;
    node.sl = (le.sl + ri.sl) % mod;
    node.sr = (le.sr + ri.sr) % mod;
    node.crew = le.crew + ri.crew;
}


void redate(Snode& node){
    merging(node, *node.lchild, *node.rchild);
}

void build(int b, int node, int left, int right){
    int rn = node + b;
    int rn1 = rn + node;
    int rn2 = rn1 + 1;
    tree[rn].l = left;
    tree[rn].r = right;
    if(left == right) return;
    tree[rn].lchild = &tree[rn1];
    tree[rn].rchild = &tree[rn2];
    int mid = (left + right) >> 1;
    build(b, rn1 - b, left, mid);
    build(b, rn2 - b, mid + 1, right);
}

int ans = 0;

void calc(Snode &node, int left, int right, Snode &targ){
    if(left > right) return;
    if(left == node.l && right == node.r){
        merging(targ, targ, node);
        return;
    }
    int mid = (node.l + node.r) >> 1;
    calc(*node.lchild, left, min(mid, right), targ);
    calc(*node.rchild, max(left, mid + 1), right, targ);
}

int pinnum, adderval;

void dfs(Snode &node, int pin){
    if(node.l == node.r){
        assert(node.l == pin);
        node.crew += adderval;
        node.sl = (node.sl + lside[pinnum] * adderval) % mod;
        node.sr = (node.sr + rside[pinnum] * adderval) % mod;
        return;
    }
    int mid = (node.l + node.r) >> 1;
    if(pin <= mid) dfs(*node.lchild, pin);
    else           dfs(*node.rchild, pin);
    redate(node);
}

void update(int basket, int plc){
    Snode lnode, rnode;
    calc(*segg[basket], 1, plc - 1, lnode);
    calc(*segg[basket], plc + 1, sz[basket], rnode);
    int res = (lnode.sl * rnode.sr) % mod;
    res += lnode.trl * rside[pinnum];
    res += rnode.trr * lside[pinnum];
    // cout << lnode.sl << " " << rnode.sr << " ";
    // cout << lnode.trl * rside[pinnum] << " ";
    // cout << rnode.trr * lside[pinnum] << " ";
    // cout << endl;
    ans = (ans + res * adderval) % mod;
    dfs(*segg[basket], plc);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; libr.pb(-mod);
    for1(i, 1, n){
        cin >> a[i]; libr.pb(a[i]);
    }
    sort(all(libr)); libr.resize(unique(all(libr)) - libr.begin());
    cnt = libr.size() - 1;
    for1(i, 1, n) a[i] = lower_bound(all(libr), a[i]) - libr.begin();
    memset(ftree, 0, sizeof(ftree));
    for1(i, 1, n){
        lside[i] = take(a[i]); inc(a[i], 1);
    }
    memset(ftree, 0, sizeof(ftree));
    for2(i, n, 1){
        rside[i] = take(a[i]); inc(a[i], 1);
    }
    memset(sz, 0, sizeof(sz));
    for1(i, 1, n){
        ++sz[a[i]];
        egg[i] = sz[a[i]];
    }
    x = 0;
    for1(i, 1, cnt){
        build(x, 1, 1, sz[i]);
        segg[i] = &tree[x + 1];
        x += 4 * sz[i];
    }
    for1(i, 1, n){
        pinnum = i; adderval = 1;
        update(a[i], egg[i]);
    }
    int o; cin >> o; while(o--){
        int x, i; cin >> x >> i;
        pinnum = i; adderval = 1;
        if(x == 1) adderval = -1;
        update(a[i], egg[i]);
        cout << (ans % mod + mod) % mod << endl;
    }
}