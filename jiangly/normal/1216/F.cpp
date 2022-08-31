#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
const int MAX_N = 200000;
LL lazy[4 * MAX_N];
LL mn[4 * MAX_N];
void pushDown(int p) {
    lazy[p << 1] = min(lazy[p << 1], lazy[p]);
    mn[p << 1] = min(mn[p << 1], lazy[p]);
    lazy[p << 1 | 1] = min(lazy[p << 1 | 1], lazy[p]);
    mn[p << 1 | 1] = min(mn[p << 1 | 1], lazy[p]);
}
LL rangeMin(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x)
        return INFLL;
    if (l >= x && r <= y)
        return mn[p];
    int mid = (l + r) >> 1;
    pushDown(p);
    return min(rangeMin(p << 1, l, mid, x, y), rangeMin(p << 1 | 1, mid, r, x, y));
}
void rangeModify(int p, int l, int r, int x, int y, LL z) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        lazy[p] = min(lazy[p], z);
        mn[p] = min(mn[p], z);
        return;
    }
    int mid = (l + r) >> 1;
    pushDown(p);
    rangeModify(p << 1, l, mid, x, y, z);
    rangeModify(p << 1 | 1, mid, r, x, y, z);
    mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    LL ans = 0;
    memset(mn, 0x3f, sizeof(mn));
    memset(lazy, 0x3f, sizeof(lazy));
    rangeModify(1, 0, n + 1, 0, 1, 0);
    for (int i = 0; i < n; ++i) {
        rangeModify(1, 0, n + 1, i + 1, i + 2, rangeMin(1, 0, n + 1, i, i + 1) + i + 1);
        if (s[i] == '1') {
            rangeModify(1, 0, n + 1, 0, i + k + 2, rangeMin(1, 0, n + 1, i - k, i + 1) + i + 1);
        }
    }
    cout << rangeMin(1, 0, n + 1, n, n + 1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}