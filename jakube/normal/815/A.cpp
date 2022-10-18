#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n);
    for (int i = 0; i < n; i++) {
        board[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<pair<char, int>> res;
    bool changes = true;
    bool notpossible = false;
    while (changes) {
        changes = false;
        for (int i = 0; i < n; i++) {
            int mi = 9999;
            int ma = 0;

            for (int j = 0; j < m; j++) {
                mi = min(mi, board[i][j]);
                ma = max(ma, board[i][j]);
            }

            if (mi < ma) {
                changes = true;

                for (int j = 0; j < m; j++) {
                    int diff = board[i][j] - mi;
                    for (int z = 0; z < diff; z++) {
                        res.push_back({'c', j});
                    }

                    for (int k = 0; k < n; k++) {
                        board[k][j] -= diff;
                        if (board[k][j] < 0) {
                            notpossible = true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int mi = 9999;
            int ma = 0;

            for (int j = 0; j < n; j++) {
                mi = min(mi, board[j][i]);
                ma = max(ma, board[j][i]);
            }

            if (mi < ma) {
                changes = true;

                for (int j = 0; j < n; j++) {
                    int diff = board[j][i] - mi;
                    for (int z = 0; z < diff; z++) {
                        res.push_back({'r', j});
                    }
                    for (int k = 0; k < m; k++) {
                        board[j][k] -= diff;
                        if (board[j][k] < 0) {
                            notpossible = true;
                        }
                    }
                }
            }
        }

        if (notpossible) {
            break;
        }
    }

    if (notpossible) {
        cout << -1 << endl;
        return 0;
    }

    if (board[0][0]) {
        for (int i = 0; i < board[0][0]; i++) {
            if (n < m) {
                for (int j = 0; j < n; j++) {
                    res.push_back({'r', j});
                }
            } else {
                for (int j = 0; j < m; j++) {
                    res.push_back({'c', j});
                }
            }
        }
    }

    // for (auto& r : board) {
    //     for (auto i : r)
    //         cout << i << " ";
    //     cout << endl;
    // }
    cout << res.size() << '\n';
    for (auto p : res) {
        cout << (p.first == 'r' ? "row" : "col") << " " << p.second + 1 << '\n';
    }

}