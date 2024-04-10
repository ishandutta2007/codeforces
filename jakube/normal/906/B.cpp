#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = i * m + j + 1;
        }
    }
    auto res = c;

    vector<vector<int>> perm4 = {{2, 0, 3, 1}, {1, 3, 0, 2}};
    vector<vector<int>> perm5 = {{0, 2, 4, 1, 3}, {2, 4, 1, 3, 0}};
    vector<vector<int>> perm6 = {{0, 2, 4, 1, 3, 5}, {2, 4, 1, 3, 5, 0}};
    vector<vector<int>> perm7 = {{0, 2, 4, 6, 1, 3, 5}, {2, 4, 6, 1, 3, 5, 0}};

    auto apply = [&](auto& perm, int row, int col) {
        for (int i = 0; i < (int)perm.size(); i++) {
            res[row][col + i] = c[row][col + perm[i]];
        }
    };

    if (m < 4 && n < 4) {
        if (m == 1 && n == 1) {
            cout << "YES" << endl;
            cout << 1 << endl;
            return 0;
        }

        if (m == 3 && n == 3) {
            cout << "YES" << endl;
            cout << "3 9 2" << endl;
            cout << "5 1 8" << endl;
            cout << "7 6 4" << '\n';
            return 0;
        }

        cout << "NO" << '\n';
        return 0;
    }

    auto transpose = [](auto v) {
        vector<vector<int>> t(v[0].size(), vector<int>(v.size()));
        for (int i = 0; i < (int)v.size(); i++) {
            for (int j = 0; j < (int)v[0].size(); j++) {
                t[j][i] = v[i][j];
            }
        }
        return t;
    };

    bool transposed = false;
    if (m < 4) {
        c = transpose(c);
        res = transpose(res);
        transposed = true;
        int tmp = m;
        m = n;
        n = tmp;
    }

    int blocks = m / 4 - 1;
    int others = m - blocks * 4;
    for (int row = 0; row < n; row++) {
        for (int j = 0; j < blocks; j++) {
            apply(perm4[row % 2], row, j * 4);
        }
        if (others == 4)
            apply(perm4[row % 2], row, blocks * 4);
        if (others == 5)
            apply(perm5[row % 2], row, blocks * 4);
        if (others == 6)
            apply(perm6[row % 2], row, blocks * 4);
        if (others == 7)
            apply(perm7[row % 2], row, blocks * 4);
    }

    if (transposed) {
        res = transpose(res);
        transposed = true;
        int tmp = m;
        m = n;
        n = tmp;
    }

    cout << "YES" << endl;
    for (auto& row : res) {
        for (auto v : row) 
            cout << v << ' ';
        cout << '\n';
    }
}