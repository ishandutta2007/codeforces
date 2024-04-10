#include <bits/stdc++.h>
using namespace std;
const int N = 200;

int a[N][N];

int f(int li, int lj, int ri, int rj) {
    return a[ri][rj] - a[li - 1][rj] - a[ri][lj - 1] + a[li - 1][lj - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int li, lj, ri, rj, i, j, n, m, k, x;
    char c[N][N];
    cin >> n >> m;
    li = n + 1;
    ri = 0;
    lj = m + 1;
    rj = 0;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
        cin >> c[i][j];
        a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        if (c[i][j] == 'W')
            a[i][j]++;
        if (c[i][j] == 'B') {
            if (i > ri)
                ri = i;
            if (j > rj)
                rj = j;
            if (i < li)
                li = i;
            if (j < lj)
                lj = j;
        }
    }
    if (rj == 0) {
        cout << 1 << endl;
        return 0;
    }
    x = max(ri - li, rj - lj);
    k = 1000000;
    for (i = ri; i <= n; ++i)
    for (j = rj; j <= m; ++j)
    if ((x < i) && (x < j))
        if (f(i - x, j - x, i, j) < k)
            k = f(i - x, j - x, i, j);
    if (k != 1000000)
        cout << k << endl;
    else
        cout << -1 << endl;
}