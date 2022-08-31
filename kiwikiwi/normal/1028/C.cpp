#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct rect {
    int l, r, u, d;

    void read() {
        scanf("%d%d%d%d", &l, &d, &r, &u);
    }

    int val() {
        return l <= r && d <= u;
    }
};

rect operator+(rect a, rect b) {
    return (rect) {max(a.l, b.l), min(a.r, b.r), min(a.u, b.u), max(a.d, b.d)};
}

const int N = 210000, Inf = 2e9;
rect x[N], y[N], z[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        x[i].read();
    }
    y[0] = (rect) {-Inf, Inf, Inf, -Inf};
    z[n + 1] = y[0];
    for (int i = 1; i <= n; i++) {
        y[i] = y[i - 1] + x[i];
    }
    for (int i = n; i; i--) {
        z[i] = z[i + 1] + x[i];
    }
    for (int i = 1; i <= n; i++) {
        rect res = y[i - 1] + z[i + 1];
        if (res.val()) {
            printf("%d %d\n", res.l, res.d);
            return 0;
        }
    }
    return 0;
}