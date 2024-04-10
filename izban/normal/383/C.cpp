#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 19;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, cnt;
int a[maxn], h[maxn], l[maxn][2], r[maxn][2];
vector<int> e[maxn], vct[2];
int t[maxn][2], add[maxn][2];

void dfs(int v, int p, int H) {
    h[v] = H;
    l[v][H] = vct[H].size();
    l[v][H^1] = vct[H ^ 1].size();
    vct[H].push_back(a[v]);
    for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) dfs(e[v][i], v, H ^ 1);
    r[v][H] = (int)vct[H].size() - 1;
    r[v][H^1] = (int)vct[H ^ 1].size() - 1;
}

void build(int k, int v, int tl, int tr) {
    if (tl > tr) return;
    if (tl == tr) {
        t[v][k] = vct[k][tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(k, v * 2, tl, tm);
    build(k, v * 2 + 1, tm + 1, tr);
}

void push(int k, int v, int tl, int tr) {
    if (add[v][k]) {
        if (tl != tr) {
            add[v * 2][k] += add[v][k];
            add[v * 2 + 1][k] += add[v][k];
        }
        t[v][k] += add[v][k];
        add[v][k] = 0;
    }
}

void upd(int k, int v, int tl, int tr, int l, int r, int x) {
    push(k, v, tl, tr);
    if (l > r) return;
    if (tl == l && tr == r) {
        add[v][k] += x;
        push(k, v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(k, v * 2, tl, tm, l, min(r, tm), x);
    upd(k, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

int get(int k, int v, int tl, int tr, int x) {
    push(k, v, tl, tr);
    if (tl == tr) return t[v][k];
    int tm = (tl + tr) >> 1;
    if (x <= tm) return get(k, v * 2, tl, tm, x);
    else return get(k, v * 2 + 1, tm + 1, tr, x);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, 0);
    build(0, 1, 0, (int)vct[0].size() - 1);
    build(1, 1, 0, (int)vct[1].size() - 1);
    for (int i = 0; i < m; i++) {
        int t, v, val;
        cin >> t >> v;
        if (t == 1) {
            cin >> val;
            upd(h[v], 1, 0, (int)vct[h[v]].size() - 1, l[v][h[v]], r[v][h[v]], val);
            upd(h[v]^1, 1, 0, (int)vct[h[v]^1].size() - 1, l[v][h[v]^1], r[v][h[v]^1], -val);
        }
        if (t == 2) {
            cout << get(h[v], 1, 0, (int)vct[h[v]].size() - 1, l[v][h[v]]) << endl;
        }
    }
    return 0;
}