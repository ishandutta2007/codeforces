#include <bits/stdc++.h>
using namespace std;
const int N  = 5e5 + 1;
vector <int> v[N], e[N];
int c[N];

void dfs(int u, int pr) {
    set <int> s;
    for (int i = 0; i < v[u].size(); ++i)
    if (c[v[u][i]] != 0)
        s.insert(c[v[u][i]]);
    int top = 1;
    for (int i = 0; i < v[u].size(); ++i)
    if (c[v[u][i]] == 0) {
        while (s.find(top) != s.end())
            ++top;
        c[v[u][i]] = top;
        s.insert(top);
    }
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u);
}

int main() {
    int i, j, k, n, m, a, b, s;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int ans = 1;
    for (i = 1; i <= n; ++i) {
        cin >> s;
        ans = max(s, ans);
        v[i].resize(s);
        for (j = 0; j < s; ++j)
            cin >> v[i][j];
    }
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
    for (i = 1;  i<= m; ++i)
    if (c[i] == 0)
        cout << 1 << ' ';
    else
        cout << c[i] << ' ';
}