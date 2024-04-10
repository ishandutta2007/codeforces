#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int xch[MAXN], ych[MAXN];
int xs, ys, xf, yf, n;

int f(int k) {
    int xn = xs, yn = ys;
    xn += xch[n] * (k / n);
    xn += xch[k % n];
    yn += ych[n] * (k / n);
    yn += ych[k % n];
    if (k == 500 * 1e6) {
        // cout << ych[n] * (k / n) << endl;
        // cout << xn << " " << yn << endl;
    }
    return abs(xn - xf) + abs(yn - yf);
}

main() {
    cin >> xs >> ys >> xf >> yf;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        ych[i + 1] = ych[i];
        xch[i + 1] = xch[i];
        if (s[i] == 'U') {
            ych[i + 1] = ych[i] + 1;
        }
        if (s[i] == 'D') {
            ych[i + 1] = ych[i] - 1;
        }
        if (s[i] == 'L') {
            xch[i + 1] = xch[i] - 1;
        }
        if (s[i] == 'R') {
            xch[i + 1] = xch[i] + 1;
        }
    }
    int l = -1, r = 1e17;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f(m) <= m) {
            r = m;
        } else {
            l = m;
        }
    }
    // cout << f(500e6) << endl;
    if (r == 1e17) {
        cout << -1;
    } else {
        cout << r;
    }
    return 0;
}