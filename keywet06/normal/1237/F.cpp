#include <bits/stdc++.h>

using namespace std;

const int N = 3600;
const int P = 998244353;

int A[N + 1][N + 1], F[N + 1][N / 2 + 1], dpv[2][N / 2 + 1], dph[2][N / 2 + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i <= N; ++i) {
        A[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            A[i][j] = 1LL * A[i][j - 1] * (i - j + 1) % P;
    }
    F[0][0] = 1;
    F[1][0] = 1;
    for (int i = 2; i <= N; ++i)
        for (int j = 0; j <= i / 2; ++j)
            F[i][j] = (F[i - 1][j] + F[i - 2][j - 1]) % P;
    int n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int>> x{{0, 0}, {n, n}}, y{{0, 0}, {m, m}};
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.emplace(x1 - 1, x2);
        y.emplace(y1 - 1, y2);
    }
    vector<int> r, c;
    for (auto i = ++x.begin(), j = x.begin(); i != x.end(); j = i++)
        if (i->first != j->second) r.push_back(i->first - j->second);
    for (auto i = ++y.begin(), j = y.begin(); i != y.end(); j = i++)
        if (i->first != j->second) c.push_back(i->first - j->second);
    int cv = 0, ch = 0;
    dpv[0][0] = 1;
    int sv = 0, sh = 0;
    for (int i = 0; i < r.size(); ++i) {
        cv ^= 1;
        memset(dpv[cv], 0, (sv / 2 + 1) * sizeof(int));
        for (int j = 0; j <= sv / 2; ++j)
            for (int k = 0; k <= r[i] / 2; ++k)
                dpv[cv][j + k] =
                    (dpv[cv][j + k] + 1LL * dpv[cv ^ 1][j] * F[r[i]][k]) % P;
        sv += r[i];
    }
    dph[0][0] = 1;
    for (int i = 0; i < c.size(); ++i) {
        ch ^= 1;
        memset(dph[ch], 0, (sh / 2 + 1) * sizeof(int));
        for (int j = 0; j <= sh / 2; ++j)
            for (int k = 0; k <= c[i] / 2; ++k)
                dph[ch][j + k] =
                    (dph[ch][j + k] + 1LL * dph[ch ^ 1][j] * F[c[i]][k]) % P;
        sh += c[i];
    }
    int ans = 0;
    for (int v = 0; 2 * v <= sv; ++v)
        for (int h = 0; 2 * h + v <= sh && 2 * v + h <= sv; ++h)
            ans = (ans + 1LL * dpv[cv][v] * dph[ch][h] % P * A[sv - 2 * v][h] %
                             P * A[sh - 2 * h][v]) %
                  P;
    cout << ans << "\n";
    return 0;
}