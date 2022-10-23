#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<int> r(3), c(3);
        int n, x, y;
        cin >> n;
        for (int i = 0; i < 3; i += 1)
            cin >> r[i] >> c[i];
        cin >> x >> y;
        int ct = 0;
        auto d = [&](int x, int y) {
            return abs(r[x] - r[y]) + abs(c[x] - c[y]);
        };
        for (int j = 0; j < 3; j += 1)
            if (d(0, j) + d(1, j) + d(2, j) == 2)
                ct = j;
        if ((r[ct] == 1 or r[ct] == n) and (c[ct] == 1 or c[ct] == n))
            cout << (x == r[ct] or y == c[ct] ? "YES\n" : "NO\n");
        else cout << (x % 2 == r[ct] % 2 or y % 2 == c[ct] % 2 ? "YES\n" : "NO\n");
    }
}