#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    int needed = 0;
    for (int i = 0; i < m; i++) {
        int best_sum = 0;
        int best_needed = 0;
        int need = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] == 1) {
                int s = 0;
                for (int K = 0; K < min(k, n - j); K++) {
                    s += matrix[j+K][i];
                }
                if (s > best_sum) {
                    best_sum = s;
                    best_needed = need;
                }
                need++;
            }
        }
        sum += best_sum;
        needed += best_needed;
    }
    cout << sum << " " << needed << endl;
}