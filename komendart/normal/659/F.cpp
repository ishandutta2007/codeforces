#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1000;

int n, m, k;
int a[maxn][maxn];

char used[maxn][maxn];
char used2[maxn][maxn];
void dfs(int i, int j, int v) {
    if (i < 0 || i >= n || j < 0 || j >= m || used[i][j] || a[i][j] < v || k == 0) return;
    used[i][j] = true;
    k -= v;
    a[i][j] = v;
    dfs(i + 1, j, v);
    dfs(i - 1, j, v);
    dfs(i, j + 1, v);
    dfs(i, j - 1, v);
}

void dfs2(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || used2[i][j]) return;
    used2[i][j] = true;
    if (!used[i][j]) {
        a[i][j] = 0;
    }
    dfs2(i + 1, j);
    dfs2(i - 1, j);
    dfs2(i, j + 1);
    dfs2(i, j - 1);
}

int dsu[maxn * maxn];
int size[maxn * maxn];

void init() {
    for (int i = 0; i < maxn * maxn; i++) {
        dsu[i] = i;
        size[i] = 1;
    }
}

int find_set(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = find_set(dsu[v]);
}

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        dsu[b] = a;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    init();

    cin >> n >> m >> k;
    vector< pair<int, pair<int, int> > > v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            v.push_back({t, {i, j}});
        }
    }
    sort(v.rbegin(), v.rend());

    for (auto it: v) {
        int val = it.first;
        int x = it.second.first;
        int y = it.second.second;
        a[x][y] = val;
        int ind = x * m + y;
        if (x > 0 && a[x - 1][y] != 0) unite(ind, ind - m);
        if (x < n - 1 && a[x + 1][y] != 0) unite(ind, ind + m);
        if (y > 0 && a[x][y - 1] != 0) unite(ind, ind - 1);
        if(y < m - 1 && a[x][y + 1] != 0) unite(ind, ind + 1);
        if (k % val == 0 && k <= val * size[find_set(ind)]) {
            dfs(x, y, val);
            dfs2(x, y);
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
            return 0;
        }
    }
    cout << "NO\n";
}