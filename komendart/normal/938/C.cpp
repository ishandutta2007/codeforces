#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 40000;

void solve(int x) {
    for (int n = 1; n <= maxn; ++n) {
        int left = 1, right = n + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (n * n - (n / mid) * (n / mid) <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (n * n - (n / left) * (n / left) == x) {
            cout << n << ' ' << left << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        solve(x);
    }



}