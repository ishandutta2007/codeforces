#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(k, vector<int>(n)), pos(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
           int tmp;
           cin >> tmp;
           tmp--;
           v[i][j] = tmp;
           pos[i][tmp] = j;
        }
    }

    vector<int> dp(n, 0);
    dp[v[0][0]] = 1;
    for (int first = 1; first < n; ++first) {
        int neww = v[0][first];
        int maxx = 0;
        for (int old = 0; old < n; ++old) {
            bool b = true;
            for (int idx = 1; idx < k; ++idx) {
                if (pos[idx][old] >= pos[idx][neww])
                {
                    b = false;
                    break;
                }
            }
            if (b) {
                maxx = max(maxx, dp[old]);
            }
        }
        dp[neww] = maxx + 1;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}