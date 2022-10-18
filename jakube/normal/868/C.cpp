#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> M(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> M[i][j];
        }
    }

    set<vector<int>> s(M.begin(), M.end());
    vector<vector<int>> v(s.begin(), s.end());

    for (int i = 1; i < (1 << v.size()); i++) {
        vector<int> sum(k, 0);
        int j = i;
        int problems = 0;
        for (int a = 0; a < (int)v.size(); a++) {
            if (j % 2) {
                for (int b = 0; b < k; b++) {
                    sum[b] += v[a][b];
                }
                problems++;
            }
            j /= 2;
        }

        bool xxx = true;
        for (int b = 0; b < k; b++) {
            xxx &= sum[b] * 2 <= problems;
        }
        if (xxx) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}