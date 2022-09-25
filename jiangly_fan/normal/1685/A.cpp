#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a)
            cin >> ai;
        if (n & 1) {
            cout << "NO\n";
            continue;
        }
        ranges::sort(a);
        vector<int> b(n);
        for (int i = 0; i < n; i += 1) {
            if (i < n / 2) b[i * 2] = a[i];
            else b[(i - n / 2) * 2 + 1] = a[i];
        }
        int ok = 1;
        for (int i = 0; i < n; i += 1) {
            int p = b[(i + n - 1) % n], s = b[(i + 1) % n];
            if ((LL)(p - b[i]) * (s - b[i]) <= 0)
                ok = 0;
        }
        if (not ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int bi : b) cout << bi << " ";
        cout << "\n";
    }
    return 0;
}