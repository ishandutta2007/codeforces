#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(10);

    int n, h;
    cin >> n >> h;
    double prev = 0;
    for (int i = 0; i < n - 1; ++i) {
        double tmp = sqrt(1.0 * h * h / n + prev * prev);
        cout << tmp << ' ';
        prev = tmp;
    }


}