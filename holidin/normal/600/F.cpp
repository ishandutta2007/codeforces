#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1;

int c[N][N], f[N][N], d[N][N], s1[N], s2[N];
int a[N * N], b[N * N];
vector <int> e[N];

void kras(int u, int v, int y) {
    c[u][y] = v;
    f[v][y] = u;
    d[u][v] = y;
}


void dfs(int u, int c1, int c2) {
    if (f[u][c1] == 0) {
        f[u][c2] = 0;
        return;
    }
    int v = f[u][c1];
    if (c[v][c2] != 0) {
        dfs(c[v][c2], c1, c2);
        kras(v, c[v][c2], c1);
    } else
        c[v][c1] = 0;
    kras(v, u, c2);
}

int main() {
    int i, j, na, nb, k, ans = 0, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> na >> nb >> k;
    for (i = 0; i < k; ++i) {
        cin >> a[i] >> b[i];
        e[a[i]].push_back(b[i]);
        ++s1[a[i]];
        ++s2[b[i]];
        ans = max(ans, max(s1[a[i]], s2[b[i]]));
    }
    for (i = 1; i <= na; ++i) {
        int p = 0;
        for (j = 0; j < e[i].size(); ++j)
        if (d[i][e[i][j]] == 0) {
            bool flag = false;
            for (p = 1; p <= ans; ++p)
            if (c[i][p] == 0 && f[e[i][j]][p] == 0) {
                kras(i, e[i][j], p);
                flag = true;
                break;
            }
            if (flag)
                continue;
            int c1 = 0, c2 = 0;
            for (l = 1; l <= ans; ++l)
            if (c[i][l] == 0)
                c1 = l;
            else if (f[e[i][j]][l] == 0)
                    c2 = l;
            dfs(e[i][j], c1, c2);
            kras(i, e[i][j], c1);
        }
    }
    cout << ans << endl;
    for (i = 0; i < k; ++i)
        cout << d[a[i]][b[i]] << ' ';
}