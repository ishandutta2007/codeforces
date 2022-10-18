#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj;
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if ((int)adj[n].size() != n-1) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<int> cnt(n, 0);
    for (int x : adj[n])
        cnt[x]++;

    stack<int> unused;

    vector<deque<int>> ds(n);
    for (int x = 1; x < n; x++) {
        if (cnt[x]) {
            while(cnt[x] > 1 && unused.size()) {
                ds[x].push_back(unused.top());
                cnt[x]--;
                unused.pop();
            }
            ds[x].push_back(n);
            if (cnt[x] > 1) {
                cout << "NO" << '\n';
                return 0;
            }
        } else {
            unused.push(x);
        }
    }
    if (unused.size()) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    for (int x = 1; x < n; x++) {
        int cur = x;
        while (ds[x].size()) {
            int next = ds[x].front();
            cout << cur << " " << next << "\n";
            cur = next;
            ds[x].pop_front();
        }
    }
}