#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int ok = 0;
        for (int x = 0; x < 3 && !ok; x++) {
            for (int y = 0; y < 3 && !ok; y++) {
                if (x == y) {
                    continue;
                }
                int cnt[3] = {0, 0, 0}, cnt2[3] = {0, 0, 0}, all = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] != '.') {
                            all++;
                            if (a[i][j] == 'X') {
                                cnt[(i + j) % 3]++;
                            } else {
                                cnt2[(i + j) % 3]++;
                            }
                        }
                    }
                }
                if (cnt[x] + cnt2[y] <= all / 3) {
                    ok = 1;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((i + j) % 3 == x && a[i][j] != '.') {
                                a[i][j] = 'O';
                            }
                            if ((i + j) % 3 == y && a[i][j] != '.') {
                                a[i][j] = 'X';
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}