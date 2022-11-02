#include <bits/stdc++.h>

using int64 = long long;
using pii = std::pair<int, int>;

const int64 P = 998244353;
const int N = 500;


int n, x, y, s, t;
int a[N * 2 + 5][N + 5], b[N + 5][N + 5], f[N + 5];

std::vector<pii> v;
std::vector<int> c[N + 5][N + 5];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                b[i][j] = 0;
                c[i][j].clear();
            }
        }
        for (int i = 1; i <= n * 2; i++) {
            f[i] = 0;
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                b[j][a[i][j]]++;
                c[j][a[i][j]].push_back(i);
            }
        }
        int top = 0, tail = 0;
        int cnt = 0, idx = 1;
        int64 ans = 1;
        v.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (b[i][j] == 1) {
                    tail++, v.push_back(pii(i, j));
                }
            }
        }
        while (cnt < n) {
            if (top < tail) {
                x = v[top].first, y = v[top].second;
                if (b[x][y] != 1) {
                    top++;
                    continue;
                }
                for (int i = 0; i < c[x][y].size(); i++) {
                    if (f[c[x][y][i]] == 0) {
                        t = c[x][y][i];
                        break;
                    }
                }
            } else {
                while (f[idx] != 0) idx++;
                t = idx;
                ans = ans * 2 % P;
            }
            f[t] = 1;
            cnt++;
            for (int i = 1; i <= n; i++) b[i][a[t][i]] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < c[i][a[t][i]].size(); j++) {
                    s = c[i][a[t][i]][j];
                    if (f[s] == 0) {
                        f[s] = 2;
                        for (int k = 1; k <= n; k++) {
                            b[k][a[s][k]]--;
                            if (b[k][a[s][k]] == 1) {
                                tail++;
                                v.push_back(pii(k, a[s][k]));
                            }
                        }
                    }
                }
            }
            top++;
        }
        s = 0;
        printf("%lld\n", ans);
        for (int i = 1; i <= n * 2; i++) {
            if (f[i] == 1) printf(++s < n ? "%d " : "%d\n", i);
        }
    }
}