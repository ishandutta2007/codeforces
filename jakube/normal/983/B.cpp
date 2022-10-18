#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
     
    vector<vector<int>> pyra(n);
    pyra[0] = v;
    for (int i = 1; i < n; i++) {
        pyra[i].resize(n - i);
        for (int j = 0; j < n-i; j++) {
            pyra[i][j] = pyra[i-1][j] ^ pyra[i-1][j+1];
        }
    }
    auto dp = pyra;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j+1]));
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << dp[r-l][l-1] << '\n';
    }
}