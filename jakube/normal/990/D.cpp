#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    
    if (min(a, b) == 1) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int M = max(a, b);
        if (M == 1) {
            if (n > 1 && n < 4) {
                cout << "NO" << '\n';
                return 0;
            } else {
                for (int i = 0; i + 1 < n; i++) {
                    m[i][i+1] = 1;
                    m[i+1][i] = 1;
                }
            }
        } else {
            for (int i = 0; i < n - M + 1; i++) {
                for (int j = 0; j < n - M + 1; j++) {
                    m[i][j] = 1;
                }
            }
        }


        if (b > 1) {
            for (auto& row : m) {
                for (auto& x : row)
                    x = 1 - x;
            }
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
            m[i][i] = 0;
        for (auto row : m){
            for (auto x : row) {
                cout << x;
            }
            cout << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
}