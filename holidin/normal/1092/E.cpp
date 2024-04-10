#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;

vector <int> e[N];
int p[N], l[N], l1[N], c[N], t[N], top = 0, d[N];

void dfs(int u, int pr, int top) {
    l[u] = 0;
    l1[u] = 0;
    t[u] = top;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u, top);
        if (l[e[u][i]] + 1 > l[u]) {
            l1[u] = l[u];
            l[u] = l[e[u][i]] + 1;
        } else if (l[e[u][i]] + 1 > l1[u])
                l1[u] = l[e[u][i]] + 1;
    }
}

int main() {
    int i, j, a, b, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (i = 1; i <= n; ++i) {
        if (t[i] == 0) {
            ++top;
            t[i] = top;
            p[top] = n + 1;
        }
        dfs(i, 0, top);
        if (l[i] < p[t[i]]) {
            c[t[i]] = i;
            p[t[i]] = l[i];
            d[t[i]] = l[i] + l1[i];
        }
    }
    vector <pair<int, int> > ans;
    int y = 1;
    for (i = 1; i <= top; ++i)
    if (d[i] > d[y])
        y = i;
    for (i = 1; i <= top; ++i)
    if (i != y) {
        ans.push_back({c[i], c[y]});
        d[y] = max(p[y] + p[i] + 1, d[y]);
        p[y] = max(p[y], p[i] + 1);
    }
    cout << d[y] << "\n";
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
}