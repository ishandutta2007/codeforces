#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const int M1 = 1000000009;
const int M2 = 1000000021;

int n, m;
vector <string> v;
vector <int> dp[2][2][MAXN];

void calc () {
    for (int i=0; i<n; i++) {
        dp[0][0][i].resize(m);
        dp[0][1][i].resize(m);
        dp[1][0][i].resize(m);
        dp[1][1][i].resize(m);
    }
    dp[0][0][0][0] = 1; dp[0][1][0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 && j == 0 || v[i][j] == '#') continue;
            int res = 0;
            if (i > 0 && v[i-1][j] == '.') res += dp[0][0][i-1][j];
            if (j > 0 && v[i][j-1] == '.') res += dp[0][0][i][j-1];
            dp[0][0][i][j] = res % M1;
            res = 0;
            if (i > 0 && v[i-1][j] == '.') res += dp[0][1][i-1][j];
            if (j > 0 && v[i][j-1] == '.') res += dp[0][1][i][j-1];
            dp[0][1][i][j] = res % M2;
        }
    }
    dp[1][0][n-1][m-1] = 1; dp[1][1][n-1][m-1] = 1;
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if (i == n-1 && j == m-1 || v[i][j] == '#') continue;
            int res = 0;
            if (i < n-1 && v[i+1][j] == '.') res += dp[1][0][i+1][j];
            if (j < m-1 && v[i][j+1] == '.') res += dp[1][0][i][j+1];
            dp[1][0][i][j] = res % M1;
            res = 0;
            if (i < n-1 && v[i+1][j] == '.') res += dp[1][1][i+1][j];
            if (j < m-1 && v[i][j+1] == '.') res += dp[1][1][i][j+1];
            dp[1][1][i][j] = res % M2;
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    calc();
    if (dp[0][0][n-1][m-1] == 0 && dp[0][1][n-1][m-1] == 0) {
        cout << 0;
        return 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 && j == 0 || i == n-1 && j == m-1 || v[i][j] == '#') continue;
            if ((dp[0][0][i][j] > 0 || dp[0][1][i][j] > 0) && (dp[1][0][i][j] > 0 || dp[1][1][i][j] > 0)) {
                if (1LL * dp[0][0][i][j] * dp[1][0][i][j] % M1 == dp[0][0][n-1][m-1]) {
                    if (1LL * dp[0][1][i][j] * dp[1][1][i][j] % M2 == dp[0][1][n-1][m-1]) {
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 2;
    return 0;
}