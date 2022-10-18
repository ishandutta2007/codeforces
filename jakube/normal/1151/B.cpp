#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (auto& row : A)
        for (auto& x : row)
            cin >> x;
    
    vector<int> ans(n, 0);
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= A[i][0];

    if (x == 0) {
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 1; j < m; j++) {
                if (A[i][j] != A[i][0]) {
                    ans[i] = j;
                    x ^= A[i][j] ^ A[i][0];
                    found = true;
                    break;
                }
            }
        }
    }

    if (x == 0) {
        cout << "NIE" << '\n';
    } else {
        cout << "TAK" << endl;
        for (auto x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}