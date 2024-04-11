#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n;
vector<int> graph[maxn];
char used[maxn];
set<int> d[maxn];
int degree[maxn];
deque<int> q;

void out(int x) {
    --x;
    while (x % 2 == 0) x /= 2;
    cout << x << '\n';
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        degree[i] = graph[i].size();
        if (degree[i] == 1) {
            d[i].insert(0);
            q.push_back(i);
            //used[i] = true;
        }
    }

    int last;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (d[v].size() != 1) continue;
        used[v] = true;
        vector<int> vec;
        for (auto u: graph[v]) {
            if (!used[u]) {
                vec.push_back(u);
            }
        }
        graph[v] = vec;
        int len = *d[v].begin() + 1;
        last = len;
        for (auto u: graph[v]) {
            d[u].insert(len);
            --degree[u];
            if (degree[u] <= 1)
                q.push_back(u);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) ++cnt;
    }
    if (cnt > 1) {
        cout << "-1\n";
        return 0;
    }
    if (cnt == 0) out(last);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (d[i].size() == 2) {
                int ans = 1;
                for (auto j: d[i]) {
                    ans += j;
                }
                out(ans);
            }
        }
    }
    cout << "-1\n";
}