#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        if (n % 2) {
            cout << "-1\n";
            continue;
        }
        int m = ranges::count(a, 1) >= n / 2 ? 1 : -1;
        int c = ranges::count(a, m);
        vector<int> v(n);
        for (int i = 1, k = c - n / 2; i < n and k; i += 1)
            if (a[i] == m and not v[i - 1]) {
                k -= 1;
                v[i] = 1;
            }
        cout << n / 2 * 3 - c << "\n";
        for (int i = 0; i < n; i += 1)
            if (not v[i])
                cout << i + 1 << " " << i + 1 + (i + 1 < n and v[i + 1]) << "\n";
    }
}