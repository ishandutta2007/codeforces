#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, x;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        cin >> x;
        vector f(n + 1, vector<int>(3, -n));
        f[0][0] = 0;
        for (int i = 0; i < n; i += 1) {
            f[i + 1][0] = ranges::max(f[i]);
            f[i + 1][1] = f[i][0] + 1;
            if (i and a[i] + a[i - 1] >= 2 * x) f[i + 1][2] = max(f[i + 1][2], f[i][1] + 1);
            if (i >= 1 and a[i] + a[i - 1] + a[i - 2] >= 3 * x and a[i] + a[i - 1] >= 2 * x) f[i + 1][2] = max(f[i + 1][2], f[i][2] + 1);
            //cout << f[i + 1][0] << " " << f[i + 1][1] << " " << f[i + 1][2] << "\n";
        }
        cout << ranges::max(f.back()) << "\n";
    }
    return 0;
}