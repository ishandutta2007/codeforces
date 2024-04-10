#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // check
    bool possible = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx = 0;
            int dy = 1;
            for (int k = 0; k < 4; k++) {
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < n && y >= 0 && y < m && b[i][j] == 'W' && b[x][y] == 'S')
                    possible = false;

                int tmp = dx;
                dx = -dy;
                dy = tmp;
            }
        }
    }

    if (possible) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == '.')
                    cout << 'D';
                else
                    cout << b[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "No" << '\n';
    }
}