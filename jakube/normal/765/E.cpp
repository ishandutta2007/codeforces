#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> previous;

pair<int, int> bfs(int start) {
    vector<bool> visited(n, false);
    previous.resize(n);

    deque<pair<int, int>> dq;
    dq.push_back({start, 0});
    visited[start] = true;

    pair<int, int> last = {-1, 0};
    while (!dq.empty()) {
        auto cur = dq.front();
        last = cur;
        dq.pop_front();

        for (int v : adj[cur.first]) {
            if (!visited[v]) {
                dq.push_back({v, cur.second + 1});
                visited[v] = true;
                previous[v] = cur.first;
            }
        }
    }

    return last;
}

struct S {
    int a, b;
    bool correct;
};

S check(int u, int p, bool isRoot) {
    S s;
    s.a = 0;
    s.b = 0;
    s.correct = true;

    for (int v : adj[u]) {
        if (v == p) continue;

        S res = check(v, u, false);
        s.correct &= res.correct;
        res.a++;

        if (!isRoot) {
            if (s.a == 0 || s.a == res.a)
                s.a = res.a;
            else
                s.correct = false;
        } else {
            if (s.a == 0 || s.a == res.a)
                s.a = res.a;
            else if (s.b == 0 || s.b == res.a)
                s.b = res.a;
            else
                s.correct = false;
        }
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto end = bfs(0);
    auto other_end = bfs(end.first);
    int diameter = other_end.second;
    int v = other_end.first;
    while (diameter > 0) {
        v = previous[v];
        diameter -= 2;
    }

    auto res = check(v, -1, true);
    int length = res.a;
    if (res.b)
        length += res.b;
    else 
        length += res.a;

    while (length % 2 == 0)
        length /= 2;

    if (res.correct)
        cout << length << endl;
    else 
        cout << -1 << endl;
}