#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 1;

bool inp[N], dp[N][2 * N], dz[2 * N], dh[2 * N];
vector <int> e[N];
int f[N], p[N];

void dfs(int u) {
    int i, j;
    if (e[u].size() == 0)
        f[u] = 1;
    if (e[u].size() == 0 && inp[u]) {
        dp[u][N] = true;
        return;
    }
    for (int i = 0; i < e[u].size(); ++i) {
        dfs(e[u][i]);
        f[u] += f[e[u][i]];
    }
    if (inp[u]) {
        int k = -1;
        for (i = 0; i< e[u].size(); ++i)
        if (inp[e[u][i]])
            k = e[u][i];
        for (i = 0; i < 2 * N; ++i) {
            dp[u][i] = dp[k][i];
            dh[i] = false;
        }
        for (i = 0; i < e[u].size(); ++i)
        if (e[u][i] != k) {
            for (j = 0; j < 2 * N; ++j)
            if (dp[u][j]) {
                if (j >= f[e[u][i]])
                    dh[j - f[e[u][i]]] = true;
                if (j + f[e[u][i]] < 2 * N)
                    dh[j + f[e[u][i]]] = true;
            }
            for (j = 0; j < 2 * N; ++j) {
                dp[u][j] = dh[j];
                dh[j] = false;
            }
        }
    }
}

int ct_cup(int a) {
    while (p[a] != 1) {
        inp[a] = true;
        a = p[a];
    }
    inp[a] = true;
    return a;
}

int main() {
    int i, j, a, b, c, d, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> a >> b >> c >> d;
    for (i = 2; i <= n; ++i) {
        cin >> p[i];
        e[p[i]].push_back(i);
    }
    a =ct_cup(a), b = ct_cup(b), c = ct_cup(c), d = ct_cup(d);
    dfs(1);
    for (i = 0; i < 2 * N; ++i) {
        dh[i] = false;
        dz[i] = false;
    }
    dz[N] = true;
    for (i = 0; i < e[1].size(); ++i)
    if (e[1][i] != a && e[1][i] != b) {
        for (j = 0; j < 2 * N; ++j)
        if (dz[j]) {
            if (j >= f[e[1][i]])
                dh[j - f[e[1][i]]] = true;
            if (j + f[e[1][i]] < 2 * N)
                dh[j + f[e[1][i]]] = true;
        }
        for (j = 0; j < 2 * N; ++j) {
            dz[j] = dh[j];
            dh[j] = false;
        }
    }
    bool can1 = false, can2 = false;
    for (i = 0; i < 2 * N; ++i)
    if (dp[a][i])
    for (j = 0; j < 2 * N; ++j)
    if (dp[b][j] && ((i + j >= N && i + j < 3 * N && dz[i + j - N]) || (i - j + N >= 0 && i - j < N && dz[N + i - j])))
        can1 = true;
    for (i = 0; i < 2 * N; ++i) {
        dh[i] = false;
        dz[i] = false;
    }
    dz[N] = true;
    for (i = 0; i < e[1].size(); ++i)
    if (e[1][i] != c && e[1][i] != d) {
        for (j = 0; j < 2 * N; ++j)
        if (dz[j]) {
            if (j >= f[e[1][i]])
                dh[j - f[e[1][i]]] = true;
            if (j + f[e[1][i]] < 2 * N)
                dh[j + f[e[1][i]]] = true;
        }
        for (j = 0; j < 2 * N; ++j) {
            dz[j] = dh[j];
            if (j < N && dh[j] && !dh[2*N - j])
                exit(1);
            dh[j] = false;
        }
    }
    for (i = 0; i < 2 * N; ++i)
    if (dp[c][i])
    for (j = 0; j < 2 * N; ++j)
    if (dp[d][j] && ((i + j >= N && i + j < 3 * N && dz[i + j - N]) || (i - j + N >= 0 && i - j < N && dz[N + i - j])))
        can2 = true;
    if (can1 && can2)
        cout << "YES";
    else
        cout << "NO";
}