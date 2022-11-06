#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e16;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int left = -INF;
    int right = INF;

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;
        if (d == 1) {
            left = max(left, 1900 - sum);
        } else {
            right = min(right, 1899 - sum);
        }
        sum += c;
    }

    if (left > right) {
        cout << "Impossible\n";
    } else if (right == INF) {
        cout << "Infinity\n";
    } else {
        cout << right + sum << '\n';
    }
}