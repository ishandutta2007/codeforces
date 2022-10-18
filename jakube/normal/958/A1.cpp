#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    auto rotate = [n](auto v) {
        vector<string> w(n, string(n, '0'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = v[j][n-1-i];
            }
        }
        return w;
    };

    using vs = vector<string>;
    vs v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vs> others(16);
    others[0] = v;
    for (int i = 1; i < 4; i++) {
        others[i] = rotate(others[i-1]);
    }
    for (int i = 4; i < 8; i++) {
        others[i] = others[i-4];
        for (int j = 0; j < n - 1 - j; j++)
            swap(others[i][j], others[i][n-1-j]);
    }
    for (int i = 8; i < 16; i++) {
        others[i] = others[i-8];
        for (int row = 0; row < n; row++) {
            for (int j = 0; j < n - 1 - j; j++)
                swap(others[i][row][j], others[i][row][n-1-j]);
        }
    }

    vs w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (auto x : others) {
        if (x == w) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}