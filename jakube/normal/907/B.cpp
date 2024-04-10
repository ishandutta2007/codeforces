#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> m(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> m[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    int bx = x % 3;
    int by = y % 3;

    bool test = false;
    for (int i = bx * 3; i < bx * 3 + 3; i++) {
        for (int j = by * 3; j < by * 3 + 3; j++) {
            if (m[i][j] == '.') {
                m[i][j] = '!';
                test = true;
            }
        }
    }

    if (!test) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (m[i][j] == '.') {
                    m[i][j] = '!';
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << m[i][j];
            if (j % 3 == 2)
                cout << ' ';
        }
        if (i % 3 == 2)
            cout << endl;
        cout << endl;
    }
}