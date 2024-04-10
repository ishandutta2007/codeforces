#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<vector<bool>> visited(310, vector<bool>(310, false));

    map<pair<int, int>, int> m;
    m.insert({{155, 154}, 1});
    // visited[155][155] = true;

    vector<int> dir_xs(129, 0);
    dir_xs[2] = 1;
    dir_xs[4] = 1;
    dir_xs[8] = 1;
    dir_xs[32] = -1;
    dir_xs[64] = -1;
    dir_xs[128] = -1;
    vector<int> dir_ys(129, 0);
    dir_ys[1] = 1;
    dir_ys[2] = 1;
    dir_ys[128] = 1;
    dir_ys[32] = -1;
    dir_ys[16] = -1;
    dir_ys[8] = -1;

    vector<int> powers = {1, 2, 4, 8, 16, 32, 64, 128};
    vector<int> powers_a = {2, 4, 8, 16, 32, 64, 128, 1};
    vector<int> powers_b = {128, 1, 2, 4, 8, 16, 32, 64};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        map<pair<int, int>, int> new_m;
        for (auto p : m) {
            for (int idx = 0; idx < powers.size(); idx++) {
               int power = powers[idx];
                if (p.second & power) {
                    int x = p.first.first;
                    int y = p.first.second;
                    int dir_x = dir_xs[power];
                    int dir_y = dir_ys[power];

                    for (int j = 0; j < t; j++) {
                        x += dir_x;
                        y += dir_y;
                        visited[x][y] = true;
                    }

                    new_m[{x, y}] |= powers_a[idx] | powers_b[idx];
                }
            }
        }
        m = new_m;
    }

    int cnt = 0;
    for (auto v : visited) for (auto b : v) if (b) cnt++;
    // for (int i = 0; i < 310; i++) for (int j = 0; j < 310; j++) {
    //     if (visited[i][j]) cout << i << ", " << j << endl;
    // }
    cout << cnt << endl;

    return 0;
}