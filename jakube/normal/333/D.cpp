#include <bits/stdc++.h>
using namespace std;

bool check(int M, vector<vector<int>>& a, int n, int m) {
    vector<vector<bool>> good_pair(m, vector<bool>(m, false));

    for (int row = 0; row < n; row++) {
        vector<int> good;
        for (int col = 0; col < m; col++) {
            if (a[row][col] >= M) good.push_back(col);
        }

        for (int i = 0; i < good.size(); i++) {
            for (int j = i + 1; j < good.size(); j++) {
                if (good_pair[good[i]][good[j]])
                    return true;
                good_pair[good[i]][good[j]] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int L = 0; 
    int R = 1e9 + 1;

    while (L + 1 < R) {
        int M = (L + R) / 2;
        if (check(M, a, n, m))
            L = M;
        else 
            R = M;
    }

    cout << L << endl;
}