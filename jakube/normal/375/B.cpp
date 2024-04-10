#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int>> right(m, vector<int>(n, 0));
    for (int col = m-1; col >= 0; col--) {
        for (int row = 0; row < n; row++) {
            if (v[row][col] == '0') {
                right[col][row] = 0; 
            } else {
                right[col][row] = 1 + (col < m-1 ? right[col+1][row] : 0);
            }
        }
    }

    int ma = 0;
    for (auto col : right) {
        sort(col.rbegin(), col.rend());
        for (int i = 0; i < n; i++) {
            ma = max(ma, col[i]*(i+1));
        }
    }

    cout << ma << endl;

    return 0;
}