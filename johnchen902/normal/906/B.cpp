#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool solve(int n, int m, vector<vector<int>> &v) {
    if (n > m) {
        vector<vector<int>> vv(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vv[j][i] = v[i][j];
        if (solve(m, n, vv)) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                     v[i][j] = vv[j][i];
            return true;
        } else {
            return false;
        }
    }
    // n <= m
    if (n == 1) {
        if (m == 1)
            return true;
        if (m < 4)
            return false;
        vector<int> vi = v[0];
        vector<int> &vo = v[0];
        int i = (m - 4) / 2;
        vo[i + 2] = vi[0];
        vo[i] = vi[1];
        vo[i + 3] = vi[2];
        vo[i + 1] = vi[3];
        for (int j = 4; j < m; j++) {
            if (j % 2 == 0) {
                vo[i + 4 + (j - 4) / 2] = vi[j];
            } else {
                vo[i - (j - 4) / 2 - 1] = vi[j];
            }
        }
        return true;
    }
    if (n == 2)
        if (m < 4)
            return false;
    if (n == 3) {
        if (m == 3) {
            auto vv = v;
            v[0][0] = vv[1][1];
            v[0][1] = vv[2][2];
            v[0][2] = vv[1][0];
            v[1][0] = vv[2][0];
            v[1][1] = vv[0][0];
            v[1][2] = vv[0][2];
            v[2][0] = vv[0][1];
            v[2][1] = vv[1][2];
            v[2][2] = vv[2][1];
            return true;
        }
    }
    // generic version
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0)
            continue;
        int a = v[0][j];
        for (int i = 0; i + 1 < n; i++)
            v[i][j] = v[i + 1][j];
        v[n - 1][j] = a;
    }
    for (int i = 0; i < n; i++)
        if (i % 2)
            rotate(v[i].begin(), v[i].begin() + 2, v[i].end());
    return true;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v[i][j] = i * m + j + 1;
    if (solve(n, m, v)) {
        puts("YES");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                printf("%d%c", v[i][j], j == m - 1 ? '\n' : ' ');
    } else {
        puts("NO");
    }
}