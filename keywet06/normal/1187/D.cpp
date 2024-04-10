#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;
const int N = 300005;
const int M = N << 2;

int T, n;
int a[N], b[N], pos[N], minn[M];

queue<int> q[N];

inline void pushup(int now) {
    minn[now] = min(minn[now << 1], minn[now << 1 | 1]);
}

void build(int l, int r, int now) {
    if (l == r) {
        minn[now] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, now << 1), build(mid + 1, r, now << 1 | 1);
    pushup(now);
}

void modify(int l, int r, int now, int pos) {
    if (l == r) {
        minn[now] = inf;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(l, mid, now << 1, pos);
    else
        modify(mid + 1, r, now << 1 | 1, pos);
    pushup(now);
}

int query(int l, int r, int now, int L, int R) {
    if (L <= l && r <= R) return minn[now];
    int mid = (l + r) >> 1, res = inf;
    if (L <= mid) res = min(res, query(l, mid, now << 1, L, R));
    if (mid < R) res = min(res, query(mid + 1, r, now << 1 | 1, L, R));
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        int flg = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            while (!q[i].empty()) q[i].pop();
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), q[a[i]].push(i);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]), flg |= (q[b[i]].empty());
            if (flg == 0) pos[i] = q[b[i]].front(), q[b[i]].pop();
        }
        if (flg == 1) {
            puts("NO");
            continue;
        }
        build(1, n, 1);
        for (int i = 1; i <= n; i++) {
            if (query(1, n, 1, 1, pos[i]) != b[i]) {
                flg = 1;
                break;
            }
            modify(1, n, 1, pos[i]);
        }
        puts(flg == 0 ? "YES" : "NO");
    }
    return 0;
}