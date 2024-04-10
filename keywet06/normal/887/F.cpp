#include <bits/stdc++.h>

const int N = 500005;

int d[N];

std::pair<int, int> a[N];

void Add(int x, int y) {
    while (x < N) d[x] += y, x += x & -x;
}

int Sum(int x) {
    int r = 0;
    while (x) r += d[x], x &= x - 1;
    return r;
}

int main() {
    int L, R, i, j, n, m;
    std::cin >> n >> m;
    for (i = 0; i < n; ++i) std::cin >> a[i].first, a[i].second = i;
    std::sort(a, a + n);
    Add(1, 1), Add(m + 1, -1);
    L = -1e9, R = 1e9, j = n;
    for (i = 0; i < n; ++i) {
        a[i].second = n - a[i].second;
        if (!Sum(a[i].second)) {
            if (j == n) j = i;
            if (L < a[i].second - m) L = a[i].second - m;
            if (R > a[i].second) R = a[i].second;
        }
        Add(a[i].second, 1);
        Add(a[i].second + m + 1, -1);
    }
    if (L > R) return puts("NO"), 0;
    if (j == n) return puts("YES"), 0;
    for (i = 0; i <= 500000; ++i) d[i] = 0;
    Add(1, 1), Add(m + 1, -1);
    for (i = 0; i < j; ++i) {
        if (a[i].second < L && Sum(L)) return puts("YES"), 0;
        Add(a[i].second, 1);
        Add(a[i].second + m + 1, -1);
    }
    puts("NO");
    return 0;
}