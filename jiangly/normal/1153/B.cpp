#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            cout << x * min(a[j], b[i]) << " \n"[j == m - 1];
        }
    }
    return 0;
}