#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int p[N];

int main() {
    long long n;
    cin >> n;
    int ans = 0;
    if (n % 3 == 0) {
        n /= 3;
        int kp = 0;
        for (int d = 1; d <= 50000; ++d) {
            if ((4 * n) % d == 0) p[kp++] = d;
        }
        for (int a = 1; 8LL * a * a * a <= n; ++a) {
            for (int id = 0; id < kp; ++id) {
                int b = p[id] - a;
                if (b < a) continue;
                if (2LL * b * (a + b) * (a + b) > n) continue;
                long long d = (long long)(a + b) * (a + b) * (a - b) * (a - b) +
                              4LL * (a + b) * n;
                long long dd = sqrt(1.0 * d);
                while (dd * dd < d) ++dd;
                while (dd * dd > d) --dd;
                if (dd * dd == d) {
                    long long c = -a - b + dd / (a + b);
                    if (c < 2 * b || (c & 1)) continue;
                    c >>= 1;
                    if (a < b && b < c) {
                        ans += 6;
                    } else if (a == b && b == c) {
                        ans += 1;
                    } else {
                        ans += 3;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}