#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

const int inf = 2e6;
int n, r;
vector<pii> ps;

int seg[1 << 23];
int add[1 << 23];

void lazy(int i) {
    add[i << 1 | 0] += add[i];
    seg[i << 1 | 0] += add[i];
    add[i << 1 | 1] += add[i];
    seg[i << 1 | 1] += add[i];
    add[i] = 0;
}

void update(int i, int s, int e, int x, int y, int v) {
    if (e < x || y < s) return;
    if (x <= s && e <= y) {
        seg[i] += v;
        add[i] += v;
        return;
    }
    lazy(i);
    int m = s + e >> 1;
    update(i << 1, s, m, x, y, v);
    update(i << 1 | 1, m + 1, e, x, y, v);
    seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ps.emplace_back(x + y, x - y);
    }
    sort(ps.begin(), ps.end());
    int ans = 0;
    for (int i = 0, j = -1; i < ps.size(); ++i) {
        while (j + 1 < ps.size() && ps[j + 1].fs <= ps[i].fs + r + r) {
            ++j;
            update(1, -inf, inf, ps[j].se - r - r, ps[j].se, 1);
        }
        ans = max(ans, seg[1]);
        update(1, -inf, inf, ps[i].se - r - r, ps[i].se, -1);
    }
    printf("%d\n", ans);
    return 0;
}