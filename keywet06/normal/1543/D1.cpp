#include <bits/stdc++.h>

const int N = 20;

int T, n, k, c, d;
int a[N], b[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = -1;
        while (n--) {
            ++a[d = c = 0];
            while (a[c] == k) a[c] = 0, ++a[++c];
            for (int i = N - 1; ~i; --i) d = d * k + ((b[i] += a[i]) %= k);
            std::cout << d << std::endl;
            for (int i = N - 1; ~i; --i) b[i] = a[i];
            std::cin >> d;
            if (d == 1) break;
        }
    }
    return 0;
}