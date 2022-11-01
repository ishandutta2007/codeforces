#include <cstdio>
#include <algorithm>

using namespace std;

// best[l, r) = max(best[l, m), best[m, r), maxA[m, r) + maxB[l, m))

constexpr int size = 256 * 1024;

int d[200000];
int h[200000];
long long dd[200000];

long long best[size * 2 - 1];
long long maxa[size * 2 - 1];
long long maxb[size * 2 - 1];

template<typename T>
T max(T a, T b, T c) { return max(a, max(b, c)); }

void build(int l, int r, int nl = 0, int nr = size, int k = 0) {
    if(nr <= l || r <= nl) {
        best[k] = maxa[k] = maxb[k] = -(1LL << 60);
    } else if(nr - nl == 1) {
        best[k] = -(1LL << 60);
        maxa[k] = 2 * h[nl] - dd[nl];
        maxb[k] = 2 * h[nl] + dd[nl];
    } else {
        build(l, r, nl, (nl + nr) / 2, 2 * k + 1);
        build(l, r, (nl + nr) / 2, nr, 2 * k + 2);
        best[k] = max(best[2 * k + 1], best[2 * k + 2], maxa[2 * k + 1] + maxb[2 * k + 2]);
        maxa[k] = max(maxa[2 * k + 1], maxa[2 * k + 2]);
        maxb[k] = max(maxb[2 * k + 1], maxb[2 * k + 2]);
    }
}

using P = pair<long long, long long>;
using Q = pair<long long, P>;

Q query(int l, int r, int nl = 0, int nr = size, int k = 0) {
    if(l <= nl && nr <= r) {
        return {best[k], {maxa[k], maxb[k]}};
    } else if(!(nr <= l || r <= nl)) {
        Q q1 = query(l, r, nl, (nl + nr) / 2, 2 * k + 1);
        Q q2 = query(l, r, (nl + nr) / 2, nr, 2 * k + 2);
        return {max(q1.first, q2.first, q1.second.first + q2.second.second),
                {max(q1.second.first, q2.second.first), max(q1.second.second, q2.second.second)}};
    } else {
        return { -(1LL << 60), {-(1LL << 60), -(1LL << 60)} };
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", d + i);
        d[n + i] = d[i];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", h + i);
        h[n + i] = h[i];
    }
    for(int i = 0; i + 1 < 2 * n; i++)
        dd[i + 1] = dd[i] + d[i];
    build(0, 2 * n);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        printf("%I64d\n", query(b + 1, a <= b ? n + a : a).first);
    }
}