#include <bits/stdc++.h>
using namespace std;

struct Move {
    Move (int v, int x, int y) : v(v), x(x), y(y) {}
    int v, x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(4, vector<int>(n));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<Move> moves;

    // try to park at least one car
    for (int i = 0; i < n; i++) {
        if (v[1][i] && v[1][i] == v[0][i]) {
            moves.emplace_back(v[1][i], 0, i);
            k--;
            v[1][i] = 0;
        }
        if (v[2][i] && v[2][i] == v[3][i]) {
            moves.emplace_back(v[2][i], 3, i);
            k--;
            v[2][i] = 0;
        }
    }

    if (k == 2 * n) {
        cout << -1 << '\n';
        return 0;
    }
    

    // find empty
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({1, i});
    }
    for (int i = n-1; i >= 0; i--) {
        vp.push_back({2, i});
    }
    int idx = 0;
    for (int i = 0; i < 2*n; i++) {
        auto [x, y] = vp[i];
        if (v[x][y] == 0) {
            idx = i;
            break;
        }
    }

    while (k) {
        for (int i = 0; i < 2*n - 1; i++) {
            // swap idx + i, idx + i + 1
            auto [x, y] = vp[(idx + i) % (2*n)];
            auto [x2, y2] = vp[(idx + i + 1) % (2*n)];
            if (v[x2][y2]) {
                moves.emplace_back(v[x2][y2], x, y);
                swap(v[x2][y2], v[x][y]);
            }
        }
        idx = (idx + 2*n - 1) % (2*n);

        // try to park cars
        for (int i = 0; i < n; i++) {
            if (v[1][i] && v[1][i] == v[0][i]) {
                moves.emplace_back(v[1][i], 0, i);
                k--;
                v[1][i] = 0;
            }
            if (v[2][i] && v[2][i] == v[3][i]) {
                moves.emplace_back(v[2][i], 3, i);
                k--;
                v[2][i] = 0;
            }
        }
    }

    cout << moves.size() << '\n';
    for (auto move : moves) {
        cout << move.v << " " << move.x + 1 << " " << move.y + 1 << endl;
    }
}