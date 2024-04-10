#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '.') {
                bool ok = (i + 2 < n && j - 1 >= 0 && j + 1 < n) && (g[i + 1][j] == '.' && g[i + 1][j - 1] == '.' && g[i + 1][j + 1] == '.' && g[i + 2][j] == '.');
                if (ok) {
                    g[i][j] = g[i + 1][j] = g[i + 1][j - 1] = g[i + 1][j + 1] = g[i + 2][j] = '#';
                } else {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES";

    return 0;
}