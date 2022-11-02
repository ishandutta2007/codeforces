#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;
int forest[MAXN];
int used[MAXN];
int n, m;

void dfs(int v) {
    // cout << "v:" << v << endl;
    deque<int> q;
    q.push_back(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        used[v] = true;
        if (v - 1 >= 0 && !used[v - 1] && !forest[v - 1]) {
            used[v - 1] = true;
            q.push_back(v - 1);
        }
        if (v - m >= 0 && !used[v - m] && !forest[v - m]) {
            used[v - m] = true;
            q.push_back(v - m);
        }
    }
}

main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                forest[i * m + j] = '1';
            }
        }
    }
    dfs(n * m - 1);
    if (!used[0]) {
        cout << 0;
        return 0;
    }
    int v = 0;
    while (v != n * m - 1) {
        // cout << v << endl;
        if (used[v + m]) {
            v += m;
        } else {
            v++;
        }
        forest[v] = true;
    }
    forest[n * m - 1] = false;
    fill(used, used + MAXN, 0);
    dfs(n * m - 1);
    if (!used[0]) {
        cout << 1;
    } else {
        cout << 2;
    }
    return 0;
}