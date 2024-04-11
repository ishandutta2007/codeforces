#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 100;
const int INF = 1e15;

struct Edge {
    int to, cost;
};

int n, k, m;

int dp[maxn][maxn][2][maxn];
int mat[maxn][maxn];

void chmin(int &x, int value) {
    x = min(x, value);
}

void recalc(int left, int right, int is_left, int cnt) {
    if (right >= n) return;
    if (right - left + 1 < cnt) return;
    if (is_left) {
        chmin(dp[left][right][is_left][cnt], dp[left][right - 1][is_left][cnt]);
        for (int to = left + 1; to <= right; ++to) {
            if (mat[left][to] == INF) continue;
            chmin(dp[left][right][is_left][cnt], mat[left][to] + dp[to][right][is_left][cnt - 1]);
        }
        if (mat[left][right]) {
            chmin(dp[left][right][is_left][cnt], mat[left][right] + dp[left + 1][right][!is_left][cnt - 1]);
        }
    } else {
        chmin(dp[left][right][is_left][cnt], dp[left + 1][right][is_left][cnt]);
        for (int to = left; to <= right - 1; ++to) {
            if (mat[right][to] == INF) continue;
            chmin(dp[left][right][is_left][cnt], mat[right][to] + dp[left][to][is_left][cnt - 1]);
        }
        if (mat[left][right]) {
            chmin(dp[left][right][is_left][cnt], mat[right][left] + dp[left][right - 1][!is_left][cnt - 1]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            mat[i][j] = mat[j][i] = INF;
        }
    }

    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        chmin(mat[a][b], c);
    }

    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int t = 0; t < 2; ++t) {
                for (int l = 0; l < maxn; ++l) {
                    dp[i][j][t][l] = INF;
                }
            }
        }
        dp[i][i][0][1] = dp[i][i][1][1] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int st = 0; st < n; ++st) {
            for (int t = 0; t < 2; ++t) {
                for (int cnt = 2; cnt <= k; ++cnt) {
                    recalc(st, st + len - 1, t, cnt);
                }
            }
        }
    }

    int answer = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            answer = min(answer, dp[i][j][0][k]);
            answer = min(answer, dp[i][j][1][k]);
        }
    }

    if (answer == INF) cout << -1;
    else cout << answer;
    cout << '\n';

}