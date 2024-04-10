#include <bits/stdc++.h>
using namespace std;

int solve(int r, int c, vector<string> grid) {
    vector<int> rows(r), cols(c);
    int total = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'A') rows[i]++, cols[j]++, total++;
        }
    }
    if (total == r * c) return 0;
    if (total == 0) return -1;

    if (rows[0] == c || rows.back() == c || cols[0] == r || cols.back() == r) return 1;
    if (grid[0][0] == 'A' || grid[0].back() == 'A' || grid.back()[0] == 'A' || grid.back().back() == 'A') return 2;
    if (*max_element(rows.begin(), rows.end()) == c || *max_element(cols.begin(), cols.end()) == r) return 2;
    if (rows[0] || rows.back() || cols[0] || cols.back()) return 3;
    return 4;
}

int main() {
    int z;
    for (cin >> z; z--;) {
        int r, c;
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++) cin >> grid[i];
        int res = solve(r, c, grid);
        (~res ? cout << res : cout << "MORTAL") << '\n';
    }
}