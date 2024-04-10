#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 1000600;
const int M = 1000200;

int s[8 * M], t[8 * M];

void push(int v) {
    t[v] += s[v];
    s[2 * v] += s[v];
    s[2 * v + 1] += s[v];
    s[v] = 0;
}

void add(int v, int l, int r, int le, int re, int val) {
    if (l == le && r == re) {
        s[v] += val;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    if (le < m)
        add(2 * v, l, m, le, min(m, re), val);
    if (m < re)
        add(2 * v + 1, m, r, max(m, le), re, val);
    t[v] = min(t[2 * v] + s[2 * v], t[2 * v + 1] + s[2 * v + 1]);
}

void add(int l, int r, int val) { // add val on [l, r)
//     cout << "adding " << l << " " << r-1 << "  " << val << endl;
    add(1, 0, M, l, r, val);
}

int getMin() {
    push(1);
    return t[1];
}

int n, m;
int w[maxn];
int h[maxn];
vi e[maxn];
int shr[maxn], k;
int b[maxn];

void scan() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &h[i]), shr[i] = h[i];
    forn(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[--u].pb(--v);
        e[v].pb(u);
    }
    scanf("%d", &m);
    forn(i, m) scanf("%d", &w[i]), shr[i+n] = w[i];
}

void shrink() {
    sort(shr, shr+n*2);
    k = unique(shr, shr+n*2) - shr;
    forn(i, n) {
        w[i] = lower_bound(shr, shr+k, w[i]) - shr;
        h[i] = lower_bound(shr, shr+k, h[i]) - shr;
    }
}


vector<pii> cands;
int getCands() {
    set<pii> avail; // (h, v)
    avail.insert(mp(h[0], 0));
    b[0] = 1;
    sort(w, w+n);
    reverse(w, w+n);
    int ptr = 0;
    while (ptr < n) {
        int cw = w[ptr];
        auto it = --avail.end();
        int ch = it->fi, v = it->se;
        if (ch >= cw) {
            avail.erase(it);
            ++ptr;
            for (auto to: e[v]) if (!b[to]) {
                avail.insert(mp(min(ch, h[to]), to));
                b[to] = 1;
            }
        } else {
            for (auto t: avail) {
                cands.pb(t);
            }
            return w[ptr];
        }
    }
//     cout << "ok" << endl;
    cout << 0 << endl;
    return -1;
}

void dfs1(int v, int anc, int ch) {
    ch = min(ch, h[v]);
    add(0, ch+1, 1);
    for (auto to: e[v]) if (!b[to] && to != anc) {
        dfs1(to, v, ch);
    }
}

void dfs(int v, int anc, int h1, int h2, int delta) {
    if (anc != -1) {
        h1 = min(h1, h[v]);
        h2 = min(h2, h[v]);
    }
    if (h1 == h2) return;
    add(h1+1, h2+1, delta);
//     cout << "change " << v << ": " << h1 << " " << h2 << endl;
    for (auto to: e[v]) if (!b[to] && to != anc) {
        dfs(to, v, h1, h2, delta);
    }
}

void solve() {
    dfs1(0, -1, h[0]);
    int ch = getCands();
    if (ch == -1) {
        return;
    }

    forn(i, n) {
        add(0, w[i]+1, -1);
    }

    sort(all(cands));
    reverse(all(cands));

//     cout << "s: " << cands.size() << endl;
//     cout << shr[cands[0].fi] << " " << cands[0].se << endl;
//     cout << shr[ch] << endl;

    for (auto cand: cands) {
        int v = cand.se;
//         cout << v << ": " << shr[h[v]] << endl;
        assert(h[v] == cand.fi);
        dfs(v, -1, h[v], ch, 1);
        if (getMin() >= 0) {
            cout << shr[ch] - shr[cand.fi] << endl;
            return;
        }
        dfs(v, -1, h[v], ch, -1);
    }
    cout << -1 << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    shrink();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}