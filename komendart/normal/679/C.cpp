#include <bits/stdc++.h>

using namespace std;

const int maxn = 502;

int a[maxn][maxn];

int cc = 1;
int color[maxn][maxn];
char used[maxn][maxn];
int sz[maxn * maxn];

int cnt[maxn * maxn];

void dfs(int r, int c) {
    if (!a[r][c] || used[r][c]) return;
    used[r][c] = true;
    color[r][c] = cc;
    sz[cc]++;
    dfs(r + 1, c); dfs(r - 1, c);
    dfs(r, c + 1); dfs(r, c - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '.') {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!used[i][j] && a[i][j]) {
                dfs(i, j);
                cc++;
            }
        }
    }

    int result = 0;
    for (int r = 1; r + k - 1 <= n; r++) {
        int ans = 0;
        for (int i = r; i <= r + k - 1; i++) {
            for (int j = 1; j <= k; j++) {
                if (!a[i][j]) ans++;
                else {
                    int col = color[i][j];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }
        }

        for (int c = 1; c + k - 1 <= n; c++) {
            for (int i = 0; i < k; i++) {
                if (a[r - 1][c + i]) {
                    int col = color[r - 1][c + i];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + k][c + i]) {
                    int col = color[r + k][c + i];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + i][c - 1]) {
                    int col = color[r + i][c - 1];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + i][c + k]) {
                    int col = color[r + i][c + k];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }

            result = max(result, ans);

            for (int i = 0; i < k; i++) {
                if (a[r - 1][c + i]) {
                    int col = color[r - 1][c + i];
                    if (cnt[col] == 1) ans -= sz[col];
                    cnt[col]--;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + k][c + i]) {
                    int col = color[r + k][c + i];
                    if (cnt[col] == 1) ans -= sz[col];
                    cnt[col]--;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + i][c - 1]) {
                    int col = color[r + i][c - 1];
                    if (cnt[col] == 1) ans -= sz[col];
                    cnt[col]--;
                }
            }
            for (int i = 0; i < k; i++) {
                if (a[r + i][c + k]) {
                    int col = color[r + i][c + k];
                    if (cnt[col] == 1) ans -= sz[col];
                    cnt[col]--;
                }
            }

            for (int i = r; i <= r + k - 1; i++) {
                if (!a[i][c]) ans--;
                else {
                    int col = color[i][c];
                    cnt[col]--;
                    if (cnt[col] == 0) ans -= sz[col];
                }
                if (!a[i][c + k]) ans++;
                else {
                    int col = color[i][c + k];
                    if (cnt[col] == 0) ans += sz[col];
                    cnt[col]++;
                }
            }
        }


        for (int i = r; i <= r + k - 1; i++) {
            for (int j = n - k + 1; j <= n; j++) {
                if (a[i][j]) {
                    int col = color[i][j];
                    cnt[col] = 0;
                }
            }
        }
    }

    cout << result << endl;
}