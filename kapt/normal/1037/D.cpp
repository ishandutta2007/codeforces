#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int maxn = 1e6;
bool used[maxn];
vector<int> g[maxn];
int arr[maxn];

bool bfs() {
    queue<int> q;
    q.push(0);
    int k = 1;
    while (!q.empty()) {
        int v = q.front();
        used[v] = true;
        q.pop();
        unordered_set<int> h, is_h;
        for (auto u : g[v]) {
            if (!used[u]) {
                h.insert(u);
            }
        }
        for (int i = k; i < k + h.size(); ++i) {
            is_h.insert(arr[i]);
            q.push(arr[i]);
        }
        k += h.size();
        if (h != is_h) {
            return false;
        }
    }
    return true;
}

main() {
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
    }
    if (arr[0] != 0) {
        cout << "No";
        return 0;
    }
    if (bfs()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}