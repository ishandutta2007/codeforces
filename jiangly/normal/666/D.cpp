#include <bits/stdc++.h>
using namespace std;
void solve(){
    int px[4], py[4];
    for (int i = 0; i < 4; ++i)
        cin >> px[i] >> py[i];
    // p[2] p[3]
    // p[0] p[1]
    int p[4] = {0, 1, 2, 3};
    int ans = 1E9;
    int toX[4], toY[4];
    set<int> aValues;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            if (px[i] != px[j])
                aValues.insert(abs(px[i] - px[j]));
            if (py[i] != py[j])
                aValues.insert(abs(py[i] - py[j]));
        }
    }
    do {
        // case 1
        int x[4], y[4];
        for (int i = 0; i < 4; ++i) {
            x[i] = px[p[i]];
            y[i] = py[p[i]];
        }
        if (x[0] == x[2] && x[1] == x[3] && x[0] != x[1]) {
            int a = abs(x[0] - x[1]);
            vector<int> values{y[0], y[1], y[2] - a, y[3] - a};
            sort(values.begin(), values.end());
            int mov = (values.back() - values.front() + 1) / 2;
            int tar = (values.front() + values.back()) / 2;
            if (mov < ans) {
                ans = mov;
                for (int i = 0; i < 4; ++i) {
                    toX[p[i]] = x[i];
                    toY[p[i]] = tar + i / 2 * a;
                }
            }
        }
        // Here, points' positions are different, but this doesn't matter.
        if (y[0] == y[2] && y[1] == y[3] && y[0] != y[1]) {
            int a = abs(y[0] - y[1]);
            vector<int> values{x[0], x[1], x[2] - a, x[3] - a};
            sort(values.begin(), values.end());
            int mov = (values.back() - values.front() + 1) / 2;
            int tar = (values.front() + values.back()) / 2;
            if (mov < ans) {
                ans = mov;
                for (int i = 0; i < 4; ++i) {
                    toX[p[i]] = tar + i / 2 * a;
                    toY[p[i]] = y[i];
                }
            }
        }
        // case 2
        for (int a : aValues) {
            for (int fx : x) {
                for (int fy : y) {
                    for (int dx : {0, -a}) {
                        for (int dy : {0, -a}) {
                            bool ok = true;
                            int mov = 0;
                            for (int i = 0; i < 4; ++i) {
                                if (x[i] != fx + dx + i % 2 * a && y[i] != fy + dy + i / 2 * a)
                                    ok = false;
                                mov = max(mov, abs(fx + dx + i % 2 * a - x[i]) + abs(fy + dy + i / 2 * a - y[i]));
                            }
                            if (ok && mov < ans) {
                                ans = mov;
                                for (int i = 0; i < 4; ++i) {
                                    toX[p[i]] = fx + dx + i % 2 * a;
                                    toY[p[i]] = fy + dy + i / 2 * a;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (next_permutation(p, p + 4));
    if (ans == 1E9) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
        for (int i = 0; i < 4; ++i)
            cout << toX[i] << " " << toY[i] << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}