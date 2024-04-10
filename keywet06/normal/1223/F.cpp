#include <bits/stdc++.h>

using int64 = long long;

const int M = 10000000;

struct Node {
    int val;
    Node *lc, *rc;
};

int cnt;

Node nodes[M];

Node *newNode() { return &nodes[cnt++]; }

Node *build(int l, int r) {
    Node *p = newNode();
    p->val = 0;
    if (r - l == 1) {
        p->lc = p->rc = nullptr;
        return p;
    }
    int mid = (l + r) / 2;
    p->lc = build(l, mid);
    p->rc = build(mid, r);
    return p;
}

Node *modify(Node *p, int l, int r, int x, int y) {
    Node *q = newNode();
    if (r - l == 1) {
        q->lc = q->rc = nullptr;
        q->val = y;
        return q;
    }
    q->val = 0;
    int mid = (l + r) / 2;
    if (x < mid) {
        q->lc = modify(p->lc, l, mid, x, y);
        q->rc = p->rc;
    } else {
        q->lc = p->lc;
        q->rc = modify(p->rc, mid, r, x, y);
    }
    return q;
}

int query(Node *p, int l, int r, int x) {
    if (r - l == 1) return p->val;
    int mid = (l + r) / 2;
    if (x < mid) return query(p->lc, l, mid, x);
    return query(p->rc, mid, r, x);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i], --a[i];
    std::vector<Node *> rt(n + 1);
    std::vector<int> f(n + 1);
    rt[0] = build(0, n);
    int64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = query(rt[i - 1], 0, n, a[i]);
        if (t != 0) {
            --t;
            f[i] = f[t] + 1;
        }
        ans += f[i];
        rt[i] = modify(rt[t], 0, n, a[i], i);
    }
    std::cout << ans << "\n";
    cnt = 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; ++i) solve();
    return 0;
}