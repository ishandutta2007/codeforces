#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int LogN = 20;


int deep[N], t[LogN], m[LogN][N];

vector <int> e[N];

void dfs(int u, int pr, int de) {
    m[0][u] = pr;
    deep[u] = de;
    int i;
    for (i = 1; i < LogN; ++i)
        m[i][u] = m[i - 1][m[i - 1][u]];
    for (i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u, de + 1);
}

int LCA(int a, int b) {
    if (deep[a] > deep[b])
        swap(a, b);
    int i;
    for (i = LogN - 1; i >= 0; --i)
    if (deep[b] - deep[a] >= t[i])
         b = m[i][b];
    if (a == b)
        return a;
    for (i = LogN - 1; i >= 0; --i)
    if (m[i][a] != m[i][b]) {
        a = m[i][a];
        b = m[i][b];
    }
    return m[0][a];
}

int cnt(int s, int t, int f) {
    int p = LCA(s, t);
    int y = LCA(t, f);
    if (y == p) {
         int j = LCA(s, f);
         return deep[j] - deep[y] + deep[t] - deep[y] + 1;
    } else
        return min(deep[t] - deep[p] + 1, deep[t] - deep[y] + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int i, n, k, j, a, b, c;
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    cin >> n >> k;
    for (i = 2;  i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
        e[i].push_back(j);
    }
    dfs(1, 1, 0);
    for (i = 1; i <= k; ++i) {
        cin >> a >> b >> c;
        cout << max(cnt(a, b, c), max(max(max(max(cnt(a, c, b), cnt(b, a, c)), cnt(b, c, a)), cnt(c, a, b)), cnt(c, b, a))) << "\n";
    }
}