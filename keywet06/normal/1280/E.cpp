#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int cnt;

int tp[N];

long long cost[N];

vector<int> son[N];

int work() {
    int u = cnt++;
    char s;
    cin >> s;
    if (s == '*') {
        son[u] = {};
        tp[u] = -1;
        cost[u] = 1;
        return u;
    }
    son[u] = {work()};
    char o;
    cin >> o;
    tp[u] = o == 'S' ? 0 : 1;
    char nxt = o;
    while (nxt == o) {
        son[u].push_back(work());
        cin >> nxt;
    }
    if (o == 'S') {
        cost[u] =
            cost[*min_element(son[u].begin(), son[u].end(),
                              [&](int i, int j) { return cost[i] < cost[j]; })];
    } else {
        cost[u] = 0;
        for (int i = 0; i < son[u].size(); ++i) cost[u] += cost[son[u][i]];
    }
    return u;
}

void dfs(int u, long long x) {
    if (tp[u] == -1) {
        cout << " " << x;
        return;
    }
    if (tp[u] == 0) {
        int y = 0;
        while (cost[u] != cost[son[u][y]]) ++y;
        y = son[u][y];
        for (int v : son[u]) dfs(v, v == y ? x : 0LL);
    } else {
        for (int v : son[u]) dfs(v, x);
    }
}

void solve() {
    int r;
    cin >> r;
    cnt = 0;
    work();
    cout << "REVOLTING";
    dfs(0, 1LL * r * cost[0]);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}