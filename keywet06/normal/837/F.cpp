#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 O = 8e18;

int n;

int64 k;
int64 a[220000];

int check() {
    for (int i = 0; i < n; ++i)
        if (a[i] >= k) return 1;
    return 0;
}

int64 add(int64 a, int64 b) {
    if (O - a <= b) return O;
    return a + b;
}

int64 mult(int64 a, int64 b) {
    if (O / a < b) return O;
    return a * b;
}

int check2(int64 x) {
    int64 cur = 0;
    int64 now = 1;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            now = mult(now, x + i);
            now /= i;
        }
        cur = add(cur, mult(now, a[i]));
    }
    if (cur >= k) return 1;
    return 0;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%lld", a + i);
    int st = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != 0) {
            st = i;
            break;
        }
    rotate(a, a + st, a + n);
    n -= st;
    if (check()) {
        cout << 0 << "\n";
        return 0;
    }
    if (n >= 5) {
        for (int i = 0;; ++i) {
            if (check()) {
                cout << i << "\n";
                return 0;
            }
            for (int i = 0; i < n - 1; ++i) a[i + 1] += a[i];
        }
    } else {
        reverse(a, a + n);
        int64 r = 2e18;
        int64 l = -1;
        while (r - l > 1) {
            int64 mid = (l + r) >> 1;
            if (check2(mid))
                r = mid;
            else
                l = mid;
        }
        cout << r + 1 << "\n";
    }
    return 0;
}