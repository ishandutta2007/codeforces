#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long llong;

int n;
int tr[256];
char in[200002];

struct node {
    int mx, my, x1, y1, x2, y2;
    node() : mx(0), my(0), x1(0), y1(0), x2(0), y2(0) {}
    node(int mode) : mx(0), my(0), x1(0), y1(0), x2(0), y2(0) {
        if (mode == 0) {
            my = -1;
            y1 = -1;
        }
        if (mode == 1) {
            mx = -1;
            x1 = -1;
        }
        if (mode == 2) {
            my = 1;
            y2 = 1;
        }
        if (mode == 3) {
            mx = 1;
            x2 = 1;
        }
    }
    node operator+(const node &p) const {
        node ret = *this;
        ret.mx += p.mx;
        ret.my += p.my;
        ret.x1 = min(ret.x1, mx + p.x1);
        ret.y1 = min(ret.y1, my + p.y1);
        ret.x2 = max(ret.x2, mx + p.x2);
        ret.y2 = max(ret.y2, my + p.y2);
        return ret;
    }
    llong get() const {
        return (x2 - x1 + 1ll) * (y2 - y1 + 1ll);
    }
} L[200002], R[200002];

void solve() {
    cin >> in + 1;
    n = strlen(in + 1);
    L[0] = R[n + 1] = node();
    for (int i = 1; i <= n; ++i) {
        L[i] = L[i - 1] + node(tr[in[i]]);
    }
    for (int i = n; i > 0; --i) {
        R[i] = node(tr[in[i]]) + R[i + 1];
    }
    llong ret = L[n].get();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            ret = min(ret, (L[i] + node(j) + R[i + 1]).get());
        }
    }
    printf("%lld\n", ret);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    tr['W'] = 0;
    tr['A'] = 1;
    tr['S'] = 2;
    tr['D'] = 3;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}