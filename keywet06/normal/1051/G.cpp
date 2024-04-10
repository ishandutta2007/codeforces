#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 7;

using pi5 = pair<int, int>;
using int64 = long long;

int n;

pi5 A[N];

struct Disjoint_Set_Union {
    int fa[N], sz[N];
    void clear() {
        for (int i = 1; i < N; ++i) fa[i] = i, sz[i] = 0;
    }
    int findx(int x) { return x == fa[x] ? x : fa[x] = findx(fa[x]); }
    void merge(int x, int y) {
        x = findx(x), y = findx(y);
        if (x != y) sz[y] += sz[x], fa[x] = y;
    }
} dsu;

struct SegmentTree {
    int root[N], sz[N << 4], tot, ls[N << 4], rs[N << 4];
    int64 sig[N << 4], sum[N << 4];
    void pushup(int rt) {
        sz[rt] = sz[ls[rt]] + sz[rs[rt]];
        sig[rt] = sig[ls[rt]] + sig[rs[rt]];
        sum[rt] = sig[ls[rt]] * sz[rs[rt]] + sum[ls[rt]] + sum[rs[rt]];
    }
    void modify(int &rt, int pos, int L, int R) {
        rt = ++tot;
        if (L + 1 == R) {
            ++sz[rt];
            sig[rt] += pos;
            return;
        }
        int mid = (L + R) >> 1;
        if (pos < mid) {
            modify(ls[rt], pos, L, mid);
        } else {
            modify(rs[rt], pos, mid, R);
        }
        pushup(rt);
    }
    int merge(int u, int v, int L, int R) {
        if (!u or !v) return u ^ v;
        if (L + 1 == R) {
            sz[u] += sz[v];
            sig[u] += sig[v];
            return u;
        }
        int mid = (L + R) >> 1;
        ls[u] = merge(ls[u], ls[v], L, mid);
        rs[u] = merge(rs[u], rs[v], mid, R);
        pushup(u);
        return u;
    }
} seg;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d %d", &A[i].first, &A[i].second);
    dsu.clear();
    int64 ret = 0;
    for (int i = 1; i <= n; ++i) {
        int a = A[i].first, b = A[i].second;
        ret -= 1ll * a * b;
        int rt = dsu.findx(a);
        int pos = rt + dsu.sz[rt];
        dsu.sz[pos] = 1;
        seg.modify(seg.root[pos], b, 1, n + 1);
        if (pos == rt and pos != 1 and dsu.sz[pos - 1]) rt = dsu.findx(rt - 1);
        if (pos != rt) {
            ret -= seg.sum[seg.root[rt]];
            ret -= rt * seg.sig[seg.root[rt]];
            dsu.merge(pos, rt);
            seg.root[rt] = seg.merge(seg.root[rt], seg.root[pos], 1, n + 1);
        }
        if (dsu.sz[pos + 1]) {
            ret -= seg.sum[seg.root[pos + 1]];
            ret -= (pos + 1) * seg.sig[seg.root[pos + 1]];
            dsu.merge(pos + 1, rt);
            seg.root[rt] = seg.merge(seg.root[rt], seg.root[pos + 1], 1, n + 1);
        }
        ret += seg.sum[seg.root[rt]];
        ret += rt * seg.sig[seg.root[rt]];
        cout << ret << "\n";
    }
    return 0;
}