#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << "\n";
    } else if (m == 1) {
        for (int i = 1; i <= n; ++i)
            cout << i + 1 << "\n";
    } else {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cout << i * (n + j) << " \n"[j == m];
    }
    return 0;
}