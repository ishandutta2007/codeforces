#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

void output(int l, int len) {
    for (int i = 0; i < len; ++i) {
        cout << l + (i + 1) % len << ' ';
    }
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0;
    for (; x * a <= n; ++x) {
        if ((n - x * a) % b == 0) {
            y = (n - x * a) / b;
            break;
        }
    }
    if (x * a + y * b != n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < x; ++i) {
        output(1 + i * a, a);
    }
    for (int i = 0; i < y; ++i) {
        output(1 + x * a + i * b, b);
    }
}