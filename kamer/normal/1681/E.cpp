#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    
    int n;
    cin >> n;

    vector<vector<vector<ll>>> d(n - 1, vector<vector<ll>>(2, vector<ll>(2)));

    for (int i = 0; i < n - 1; i++) {
        cin >> d[i][0][0] >> d[i][0][1] >> d[i][1][0] >> d[i][1][1];
        d[i][0][0]--;
        d[i][0][1]--;
        d[i][1][0]--;
        d[i][1][1]--;
    }

    int n_log = 0;
    {
        int d = 1;
        while (d < n) {
            d *= 2;
            n_log++;
        }
    }

    vector<vector<vector<vector<ll>>>> cross_dist(n - 1, vector<vector<vector<ll>>>(n_log + 1, vector<vector<ll>>(2, vector<ll>(2))));
    for (int dist = 1, pow = 0; dist < n; dist *= 2, pow++) {
        for (int level = 0; level + dist < n - 1; level++) {
            if (pow == 0) {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cross_dist[level][pow][i][j] = abs(d[level][i][0] + 1 - i - d[level + 1][j][0]) + abs(d[level][i][1] + i - d[level + 1][j][1]);
                    }
                }
            } else {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cross_dist[level][pow][i][j] = min(cross_dist[level][pow - 1][i][0] + cross_dist[level + dist / 2][pow - 1][0][j],
                                                           cross_dist[level][pow - 1][i][1] + cross_dist[level + dist / 2][pow - 1][1][j]);
                    }
                }
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (max(x1, y1) > max(x2, y2)) {
            swap(x1, x2), swap(y1, y2);
        }

        if (max(x1, y1) == max(x2, y2)) {
            cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
            continue;
        }

        int level_1 = max(x1, y1);
        int level_2 = max(x2, y2);

        ll d_0 = abs(x1 - d[level_1][0][0]) + abs(y1 - d[level_1][0][1]);
        ll d_1 = abs(x1 - d[level_1][1][0]) + abs(y1 - d[level_1][1][1]);

        d_0 = d_0 + level_2 - level_1;
        d_1 = d_1 + level_2 - level_1;

        while (level_1 < level_2 - 1) {
            int d = 1, pow = 0;
            while (level_1 + d < level_2) {
                d *= 2;
                pow++;
            }
            pow--;
            ll d_0_t = min(d_0 + cross_dist[level_1][pow][0][0], d_1 + cross_dist[level_1][pow][1][0]);
            ll d_1_t = min(d_0 + cross_dist[level_1][pow][0][1], d_1 + cross_dist[level_1][pow][1][1]);
            
            d_0 = d_0_t;
            d_1 = d_1_t;

            level_1 = level_1 + d / 2;
        }

        d_0 = d_0 + abs(x2 - d[level_2 - 1][0][0] - 1) + abs(y2 - d[level_2 - 1][0][1]);
        d_1 = d_1 + abs(x2 - d[level_2 - 1][1][0]) + abs(y2 - d[level_2 - 1][1][1] - 1);

        cout << min(d_0, d_1) << "\n";
    }
}