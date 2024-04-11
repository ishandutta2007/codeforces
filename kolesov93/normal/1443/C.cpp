#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a, b;
        a.resize(n); b.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }

        int L = 1, R = 1e9;
        while (L < R) {
            int m = (L + R) >> 1;
            ll sum = 0;

            for (int i = 0; i < n; ++i) {
                if (a[i] > m) {
                    sum += b[i];
                    if (sum > m) continue;
                }
            }
            if (sum <= m) {
                R = m;
            } else {
                L = m + 1;
            }
        }
        printf("%d\n", L);
    }

    return 0;
}