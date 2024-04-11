#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 2e5 + 5;

int n;
int a[maxn];

ld f(ld x) {
    ld s = 0;
    ld smin = 0, smax = 0;
    ld result = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] - x;
        result = max(result, max(fabs(s - smin), fabs(s - smax)));
        smin = min(smin, s);
        smax = max(smax, s);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ld EPS = 1e-14;
    ld left = -1e5, right = 1e5;
    for (int times = 0; times < 100; times++) {
        ld mid = (left + right) / 2;
        if (f(mid) > f(mid + EPS)) left = mid;
        else right = mid;
    }

    cout << fixed; cout.precision(12);
    cout << f(left) << '\n';
}