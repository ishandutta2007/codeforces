#include <bits/stdc++.h>
using namespace std;
constexpr int N = 150, M = 150;
using Matrix = bitset<N>[N];
int n, m;
tuple<int, int, int> e[M];
bitset<N> able, tmp;
Matrix mat;
int dis[N];
void matrixMul(Matrix lhs, Matrix rhs, Matrix result) {
    Matrix c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (lhs[i][j] == 1)
                c[i] |= rhs[j];
    copy(c, c + n, result);
}
void matrixPow(Matrix mat, int x, Matrix result) {
    Matrix base;
    copy(mat, mat + n, base);
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        result[i][i] = 1;
    }
    while (x > 0) {
        if (x & 1)
            matrixMul(result, base, result);
        matrixMul(base, base, base);
        x >>= 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        --u;
        --v;
        e[i] = {d, u, v};
    }
    sort(e, e + m);
    int lst = 0, ans = -1;
    able[0] = 1;
    for (int i = 0; i < m; ++i) {
        int d, u, v;
        tie(d, u, v) = e[i];
        Matrix trans;
        matrixPow(mat, d - lst, trans);
        mat[u][v] = 1;
        tmp = 0;
        for (int j = 0; j < n; ++j)
            if (able[j] == 1)
                tmp |= trans[j];
        able = tmp;
        queue<int> que;
        fill(dis, dis + n, -1);
        for (int j = 0; j < n; ++j)
            if (able[j] == 1) {
                dis[j] = 0;
                que.push(j);
            }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v = 0; v < n; ++v)
                if (mat[u][v] == 1 && dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    que.push(v);
                }
        }
        if (dis[n - 1] != -1 && (ans == -1 || dis[n - 1] + d < ans))
            ans = dis[n - 1] + d;
        lst = d;
    }
    if (ans == -1)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}