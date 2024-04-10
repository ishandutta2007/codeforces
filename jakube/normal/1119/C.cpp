#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));
    for (auto& row : A)
        for (auto& x : row)
            cin >> x;
    for (auto& row : B)
        for (auto& x : row)
            cin >> x;
    
    for (int i = 0; i + 1 < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                cnt++;
                A[i][j] ^= 1;
                A[i+1][j] ^= 1;
            }
        }
        if (cnt % 2) {
            cout << "No" << '\n';
            return 0;
        }
    }
    
    if (A == B)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}