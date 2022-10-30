// Hydro submission #6195d5751f2c1185421a02db@1637209461330
#include <bits/stdc++.h>
using namespace std;

int op = 0;
namespace io {
    const int n = 1e6;
    char c, b[n], *i, *j;

    inline char gc() {
        if (i == j) j = (i = b) + fread(b, 1, n, stdin);
        return i == j ? EOF : *i ++;
    }
    // #define gc getchar

    template <typename T> inline T read() {
        T x = 0; int f = 0;
        while (!isdigit(c = gc())) f |= c == '-';
        while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = gc();
        if (c == ' ') op ++;
        return f ? -x : x;
    }

    template <> inline string read() {
        string s = "";
        while (!isgraph(c = gc()));
        while (isgraph(c)) s += c, c = gc();
        return s;
    }
}

#define int long long
#define INF (1e9)
#define N 200010

int n, a[N];

struct Segtree {
    int l, r, Mn, p;
    #define lid (id << 1)
    #define rid (id << 1 | 1)
}tr[N * 4];
void pushup(int id) {
    tr[id].Mn = min(tr[lid].Mn, tr[rid].Mn);
}
void build(int id, int l, int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) {
        return tr[id].Mn = a[l], void();
    }
    int mid = tr[id].l + tr[id].r >> 1;
    build(lid, l, mid), build(rid, mid + 1, r);
    pushup(id);
}
void pushdown(int id) {
    if (tr[id].l == tr[id].r) return;
    tr[lid].Mn += tr[id].p, tr[lid].p += tr[id].p;
    tr[rid].Mn += tr[id].p, tr[rid].p += tr[id].p;
    tr[id].p = 0;
}
void add(int id, int l, int r, int v) {
    pushdown(id);
    if (l <= tr[id].l && tr[id].r <= r) {
        tr[id].Mn += v, tr[id].p += v;
        return;
    }
    int mid = tr[id].l + tr[id].r >> 1;
    if (l <= mid) add(lid, l, r, v);
    if (r > mid) add(rid, l, r, v);
    pushup(id);
}
int ask(int id, int l, int r) {
    pushdown(id);
    if (l <= tr[id].l && tr[id].r <= r) {
        return tr[id].Mn;
    }
    int mid = tr[id].l + tr[id].r >> 1, val = INF;
    if (l <= mid) val = min(val, ask(lid, l, r));
    if (r > mid) val = min(val, ask(rid, l, r));
    return val;
}

signed main() {
    n = io::read<int>();
    for (int i = 1; i <= n; i ++) {
        a[i] = io::read<int>();
    }

    build(1, 1, n);

    for (int T = io::read<int>(); T --;) {
        op = 0;
        int l = io::read<int>() + 1, r = io::read<int>() + 1;
        if (op == 2) {
            int v = io::read<int>();
            if (l <= r) add(1, l, r, v);
            else add(1, l, n, v), add(1, 1, r, v);
        } else {
            if (l <= r) printf("%lld\n", ask(1, l, r));
            else printf("%lld\n", min(ask(1, l, n), ask(1, 1, r)));
        }
    }
    return 0;
}