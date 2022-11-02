#include <bits/stdc++.h>

using int64 = long long;

const int64 N = 1e6 + 6;

int64 n, len, a[N], b[N], sum[N];

int64 check(int64 lim) {
    memset(sum, 0, sizeof sum);
    for (int64 j = 0; j < n; ++j) {
        int64 xl = a[j] + len - lim, xr = a[j] + len + lim + 1;
        xl = std::lower_bound(b, b + n + n + n, xl) - b;
        xr = std::lower_bound(b, b + n + n + n, xr) - b;
        xl -= j, xr -= j;
        xl += n, xr += n;
        xr = std::min(xr, xl + n);
        --sum[xr];
        ++sum[xl];
    }
    for (int64 j = 1; j < N; ++j) sum[j] += sum[j - 1];
    for (int64 j = n; j < N; ++j) sum[j] += sum[j - n];
    for (int64 j = 0; j < N; ++j) {
        if (sum[j] > n) assert(0);
    }
    for (int64 j = 0; j < N; ++j) {
        if (sum[j] == n) return 1;
    }
    return 0;
}

int main() {
    std::cin >> n >> len;
    for (int64 j = 0; j < n; ++j) std::cin >> a[j];
    for (int64 j = 0; j < n; ++j) std::cin >> b[j];
    std::sort(a, a + n);
    std::sort(b, b + n);
    for (int64 j = n; j < n + n + n; ++j) b[j] = b[j - n] + len;
    int64 bl = -1, br = len;
    while (bl < br - 1) {
        int64 bm = bl + br >> 1;
        if (check(bm)) {
            br = bm;
        } else {
            bl = bm;
        }
    }
    std::cout << br << std::endl;
    return 0;
}