#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
const int INF = (1<<30)-1;
#define lson(x) ((x)<<1)
#define rson(x) (((x)<<1)|1)
int lc[maxn << 2], rc[maxn << 2], set[maxn << 2], val[maxn << 2];

inline void maintain (int u, int w) {
    val[u] |= w;
    set[u] |= w;
}

inline void pushup(int u) {
    val[u] = val[lson(u)] & val[rson(u)];
}

inline void pushdown(int u) {
    if (set[u]) {
        maintain(lson(u), set[u]);
        maintain(rson(u), set[u]);
        set[u] = 0;
    }
}

void build (int u, int l, int r) {
    lc[u] = l;
    rc[u] = r;
    set[u] = val[u] = 0;

    if (l == r)
        return;

    int mid = (lc[u] + rc[u]) >> 1;
    build(lson(u), l, mid);
    build(rson(u), mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int w) {
    if (l <= lc[u] && rc[u] <= r) {
        maintain(u, w);
        return;
    }

    pushdown(u);
    int mid = (lc[u] + rc[u]) >> 1;
    if (l <= mid)
        modify(lson(u), l, r, w);
    if (r > mid)
        modify(rson(u), l, r, w);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= lc[u] && rc[u] <= r)
        return val[u];

    pushdown(u);
    int mid = (lc[u] + rc[u]) >> 1, ret = INF;
    if (l <= mid)
        ret &= query(lson(u), l, r);
    if (r > mid)
        ret &= query(rson(u), l, r);
    pushup(u);
    return ret;
}

int N, M, L[maxn], R[maxn], Q[maxn];

bool judge() {
    for (int i = 0; i < M; i++)
        if (query(1, L[i], R[i]) != Q[i])
            return true;

    printf("YES\n");
    for (int i = 1; i <= N; i++)
        printf("%d%c", query(1, i, i), i == N ? '\n' : ' ');
    return false;
}

int main () {
    scanf("%d%d", &N, &M);
    build(1, 1, N);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &L[i], &R[i], &Q[i]);
        modify(1, L[i], R[i], Q[i]);
    }
    if (judge())
        printf("NO\n");
    return 0;
}