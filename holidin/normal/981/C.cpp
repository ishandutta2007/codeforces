#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int cnt[N];
bool b[N];
vector <int> e[N];

void dfs(int u, int pr) {
    b[u] = true;
    cnt[u] = 0;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        ++cnt[u];
        b[u] &= b[e[u][i]];
    }
    b[u] &= (cnt[u] < 2);
}

int dfs2(int u, int pr) {
    if (e[u].size() == 1)
        return u;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        return dfs2(e[u][i], u);
}

bool calc(int u, int pr, int v) {
    for (int i = 0; i <e[u].size(); ++i)
    if (e[u][i] != u && e[u][i] != v)
        return b[e[u][i]];
}

void dfs1(int u, int pr) {
    bool ft = true;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        if (cnt[u] == 1 || (u == 1 && cnt[u] == 2 && calc(u, pr, e[u][i])))
            dfs1(e[u][i], u);
        ft &= b[e[u][i]];
    }
    if (ft) {
        vector <pair<int, int> > v;
        for (int i = 0; i < e[u].size(); ++i)
            v.push_back({u, dfs2(e[u][i], u)});
        cout << "Yes\n";
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); ++i)
            cout << v[i].first << ' ' << v[i].second << "\n";
        exit(0);
    }
}

int main() {
    int i, j, n, a, b1;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i < n; ++i) {
        cin >> a >> b1;
        e[a].push_back(b1);
        e[b1].push_back(a);
    }
    dfs(1, 0);
    dfs1(1, 0);
    cout << "No";
}