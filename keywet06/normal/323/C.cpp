#include <bits/stdc++.h>

using namespace std;

#define f(z) ((((z)-1 + X) % n) + 1)
#define rng(v) (v).begin(), (v).end()

const int M = 1 << 20;

int n, X, x, m, a, b, c, d;
int p[M], q[M];

vector<int> s[M * 2];

int qu(int l1, int r1, int l2, int r2, int small = 0, int big = M - 1,
       int index = 1) {
    l1 = max(l1, small);
    r1 = min(r1, big);
    if (l1 > r1) return 0;
    if (small == l1 && big == r1) {
        return upper_bound(rng(s[index]), r2) - lower_bound(rng(s[index]), l2);
    }
    return qu(l1, r1, l2, r2, small, (small + big) / 2, 2 * index) +
           qu(l1, r1, l2, r2, (small + big) / 2 + 1, big, index * 2 + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x, p[x] = i;
    for (int i = 1; i <= n; ++i) cin >> x, q[x] = i;
    for (int i = 1; i <= n; ++i) s[p[i] + M].push_back(q[i]);
    for (int i = M - 1; i >= 0; --i) {
        merge(rng(s[i * 2]), rng(s[i * 2 + 1]), back_inserter(s[i]));
    }
    cin >> m;
    while (m--) {
        cin >> a >> b >> c >> d;
        int l1 = min(f(a), f(b)), r1 = max(f(a), f(b)), l2 = min(f(c), f(d)),
            r2 = max(f(c), f(d));
        X = qu(l1, r1, l2, r2);
        cout << X++ << '\n';
    }
    return 0;
}