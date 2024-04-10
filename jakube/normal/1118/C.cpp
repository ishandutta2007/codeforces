#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n*n);
    for (auto& x : v)
        cin >> x;
    map<int, int> cnt;
    for (auto x : v)
        cnt[x]++;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            for (auto& [x, c] : cnt) {
                if (c >= 4) {
                    matrix[i][j] = matrix[n-1-i][j] = 
                        matrix[i][n-1-j] = matrix[n-1-i][n-1-j] = x;
                    c -= 4;
                    break;
                }
            }
        }
    }

    if (n % 2) {
        int i = n / 2;
        for (int j = 0; j < n / 2; j++) {
            for (auto& [x, c] : cnt) {
                if (c >= 2) {
                    matrix[i][j] = matrix[i][n-1-j] = x;
                    c -= 2;
                    break;
                }
            }
            for (auto& [x, c] : cnt) {
                if (c >= 2) {
                    matrix[j][i] = matrix[n-1-j][i] = x;
                    c -= 2;
                    break;
                }
            }
        }

        for (auto& [x, c] : cnt) {
            if (c) {
                matrix[i][i] = x;
                break;
            }
        }
    }

    for (auto row : matrix) {
        for (auto x : row) {
            if (x == 0) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    for (auto row : matrix) {
        for (auto x : row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}