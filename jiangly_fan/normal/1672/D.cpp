#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ok = 1;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& ai : a) cin >> ai;
        for (int& bi : b) cin >> bi;
        vector<int> c(n + 1);
        for (int i = n - 1, j = n - 1; (i >= 0 or j >= 0) and ok;) {
            if (i < 0) ok = 0;
            else if (j < 0) {
                if (c[a[i]] == 0) ok = 0;
                i -= 1;
            }
            else if (a[i] == b[j]) {
                i -= 1;
                j -= 1;
            }
            else if (j + 1 < n and b[j] == b[j + 1]) {
                c[b[j]] += 1;
                j -= 1;
            }
            else if (c[a[i]]) {
                c[a[i]] -= 1;
                i -= 1;
            }
            else ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}