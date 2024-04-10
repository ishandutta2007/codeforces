#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 402;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int sub(int x, int y) { return add(x, -y); }

int mul(int x, int y) { return (x * 1ll * y) % MOD; }

int c[26];
int dp[2][N][N][3][3];
int sumDp[N][N];
int p1[N][N];
int p2[N][N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < 26; i++) cin >> c[i];
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                if (i != k) {
                    multiset<int> s = {i, j, k};
                    dp[1][s.count(0)][s.count(1)][min(2, j)][min(2, k)]++;
                }
    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++) {
                        dp[0][j][k][x][y] = dp[1][j][k][x][y];
                        dp[1][j][k][x][y] = 0;
                    }
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++) {
                        int cur = dp[0][j][k][x][y];
                        if (cur == 0) continue;
                        for (int z = 0; z < 3; z++) {
                            int& nw = dp[1][j + (z == 0 ? 1 : 0)]
                                        [k + (z == 1 ? 1 : 0)][y][z];
                            nw = add(nw, mul(cur, (z == 2 ? 24 : 1) -
                                                      (z == x ? 1 : 0)));
                        }
                    }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                    sumDp[i][j] = add(sumDp[i][j], dp[1][i][j][k][l]);
    for (int i = 0; i < N; i++) {
        p1[i][N - 1] = sumDp[i][N - 1];
        for (int j = N - 2; j >= 0; j--)
            p1[i][j] = add(sumDp[i][j], p1[i][j + 1]);
    }
    for (int j = 0; j < N; j++) {
        p2[N - 1][j] = p1[N - 1][j];
        for (int i = N - 2; i >= 0; i--) p2[i][j] = add(p1[i][j], p2[i + 1][j]);
    }
    int ans = p2[0][0];
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < N; j++)
            for (int k = c[i] + 1; k < N; k++) ans = sub(ans, sumDp[k][j]);
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < i; j++) ans = add(ans, p2[c[i] + 1][c[j] + 1]);
    cout << ans << endl;
}