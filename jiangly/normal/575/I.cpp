#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5000, Q = 100000;
int n, q;
int fen[2 * N + 1][N + 1];
int dir[Q], x[Q], y[Q], len[Q], ans[Q];
void add(int x, int y, int v) {
    for (int i = x; i <= 2 * N; i += i & -i)
        for (int j = y; j <= N; j += j & -j)
            fen[i][j] += v;
}
int sum(int x, int y) {
    int result = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            result += fen[i][j];
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> dir[i] >> x[i] >> y[i] >> len[i];
        } else {
            cin >> x[i] >> y[i];
        }
    }
    // (x, y) -> (x, y)
    for (int i = 0; i < q; ++i) {
        if (dir[i] == 1) {
            add(x[i], y[i], 1);
            add(x[i], y[i] + len[i] + 1, -1);
        } else if (dir[i] == 2) {
            add(x[i], y[i] - len[i], 1);
            add(x[i], y[i] + 1, -1);
        } else if (dir[i] == 3) {
            add(x[i] + 1, y[i], -1);
            add(x[i] + 1, y[i] + len[i] + 1, 1);
        } else if (dir[i] == 4) {
            add(x[i] + 1, y[i] - len[i], -1);
            add(x[i] + 1, y[i] + 1, 1);
        } else {
            ans[i] += sum(x[i], y[i]);
        }
    }
    memset(fen, 0, sizeof(fen));
    // (x, y) -> (x - y + n + 1, y)
    for (int i = 0; i < q; ++i) {
        if (dir[i] == 2) {
            add(x[i] - y[i] + len[i] + n + 2, y[i] - len[i], -1);
            add(x[i] - y[i] + len[i] + n + 2, y[i] + 1, 1);
        } else if (dir[i] == 3) {
            add(x[i] - len[i] - y[i] + n + 1, y[i], 1);
            add(x[i] - len[i] - y[i] + n + 1, y[i] + len[i] + 1, -1);
        } else if (dir[i] == 0) {
            ans[i] += sum(x[i] - y[i] + n + 1, y[i]);
        }
    }
    memset(fen, 0, sizeof(fen));
    // (x, y) -> (x + y, n - y + 1)
    for (int i = 0; i < q; ++i) {
        if (dir[i] == 1) {
            add(x[i] + y[i] + len[i] + 1, n - y[i] - len[i] + 1, -1);
            add(x[i] + y[i] + len[i] + 1, n - y[i] + 2, 1);
        } else if (dir[i] == 4) {
            add(x[i] - len[i] + y[i], n - y[i] + 1, 1);
            add(x[i] - len[i] + y[i], n - y[i] + len[i] + 2, -1);
        } else if (dir[i] == 0) {
            ans[i] += sum(x[i] + y[i], n - y[i] + 1);
        }
    }
    for (int i = 0; i < q; ++i)
        if (dir[i] == 0)
            cout << ans[i] << "\n";
    return 0;
}