#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char out[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out[i][j] = 'I';
        }
    }

    pair<int, int> inp[n][n];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> inp[i][j].first >> inp[i][j].second;
            if (inp[i][j].first != -1) {
                inp[i][j].first--;
                inp[i][j].second--;
                if (out[inp[i][j].first][inp[i][j].second] == 'I') {
                    out[inp[i][j].first][inp[i][j].second] = 'X';
                    q.emplace(inp[i][j].first, inp[i][j].second);
                    //cout << "placing " << inp[i][j].first << ' ' << inp[i][j].second << endl;
                }
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> top = q.front(); q.pop();
        //cout << "processing " << top.first << ' ' << top.second << endl;

        if (top.first > 0 && out[top.first-1][top.second] == 'I' && inp[top.first-1][top.second] == inp[top.first][top.second]) {
            out[top.first-1][top.second] = 'D';
            q.emplace(top.first-1, top.second);
        } if (top.second > 0 && out[top.first][top.second-1] == 'I' && inp[top.first][top.second - 1] == inp[top.first][top.second]) {
            out[top.first][top.second-1] = 'R';
            q.emplace(top.first, top.second-1);
        } if (top.first < n-1 && out[top.first+1][top.second] == 'I' && inp[top.first+1][top.second] == inp[top.first][top.second]) {
            out[top.first+1][top.second] = 'U';
            q.emplace(top.first+1, top.second);
        } if (top.second < n-1 && out[top.first][top.second+1] == 'I' && inp[top.first][top.second + 1] == inp[top.first][top.second]) {
            out[top.first][top.second+1] = 'L';
            q.emplace(top.first, top.second+1);
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //if (out[i][j] != 'I') continue;

            if (inp[i][j].first == -1) {
                //cout << "setting " << i << ' ' << j << endl;
                if (i > 0 && inp[i-1][j].first == -1) {
                    out[i][j] = 'U';
                } else if (i < n-1 && inp[i+1][j].first == -1) {
                    out[i][j] = 'D';
                } else if (j > 0 && inp[i][j-1].first == -1) {
                    out[i][j] = 'L';
                } else if (j < n-1 && inp[i][j+1].first == -1) {
                    out[i][j] = 'R';
                } else {
                    //cout << "Bad cycle" << endl;
                    cout << "INVALID" << endl;
                    return 0;
                }
            } else {
                if (out[i][j] == 'I') {
                    //cout << "unset thing" << endl;
                    //cout << i << ' ' << j << endl;
                    cout << "INVALID" << endl;
                    return 0;
                }
                if (out[i][j] == 'X' && (inp[i][j].first != i || inp[i][j].second != j)) {
                    cout << "INVALID" << endl;
                    return 0;
                }
            }
        }
    }



    cout << "VALID" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << out[i][j];
        }
        cout << endl;
    }
}