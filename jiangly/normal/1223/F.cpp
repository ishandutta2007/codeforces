#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using Uint = uint32_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
constexpr int MAX_N = 300000;
constexpr int MAX_NODES = 10000000;
struct Node {
    int val;
    Node *lc, *rc;
};
int cnt;
Node nodes[MAX_NODES];
void init() {
    
}
Node *newNode() {
    return &nodes[cnt++];
}
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
    if (r - l == 1)
        return p->val;
    int mid = (l + r) / 2;
    if (x < mid)
        return query(p->lc, l, mid, x);
    return query(p->rc, mid, r, x);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<Node *> rt(n + 1);
    vector<int> f(n + 1);
    rt[0] = build(0, n);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = query(rt[i - 1], 0, n, a[i]);
        if (t != 0) {
            --t;
            f[i] = f[t] + 1;
        }
        ans += f[i];
        rt[i] = modify(rt[t], 0, n, a[i], i);
    }
    cout << ans << "\n";
    cnt = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        solve();
    return 0;
}