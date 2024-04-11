#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                x = i; y = j;
            }
        }
    }

    while (true) {
        if (a[x][y] != 'S') a[x][y] = '.';
        if (x > 0 && a[x - 1][y] == '*') {
            cout << 'U';
            x--;
        } else if (x < n - 1 && a[x + 1][y] == '*') {
            cout << 'D';
            x++;
        } else if (y > 0 && a[x][y - 1] == '*') {
            cout << 'L';
            y--;
        } else if (y < m - 1 && a[x][y + 1] == '*') {
            cout << 'R';
            y++;
        } else {
            if (x > 0 && a[x - 1][y] == 'S') {
                cout << 'U';
                x--;
            } else if (x < n - 1 && a[x + 1][y] == 'S') {
                cout << 'D';
                x++;
            } else if (y > 0 && a[x][y - 1] == 'S') {
                cout << 'L';
                y--;
            } else if (y < m - 1 && a[x][y + 1] == 'S') {
                cout << 'R';
                y++;
            }
            break;
        }
    }
}