#include <bits/stdc++.h>
using namespace std;

enum Status { change, stay, unknown };

int n, m;
vector<vector<int>> adj;
vector<Status> status;

bool dfs(int v) {
    for (int u : adj[v]) {
        if (status[u] == Status::stay) {
            return false;
        }
        if (status[u] == Status::unknown) {
            status[u] = Status::change;
            if (!dfs(u))
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        v[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> v[i][j];
        }
    }

    // vector<int> value(m+1, 0);
    // for (int i = 0; i <= m; i++) {
    //     value[i] = i + m;
    // }
    status.assign(m+1, Status::unknown);
    adj.resize(m+1);
    
    for (int i = 0; i < n - 1; i++) {
        auto &a = v[i];
        auto &b = v[i+1];
        int s = min(v[i].size(), v[i+1].size());
        bool all_equal = true;
        for (int j = 0; j < s; j++) {
            if (a[j] !=  b[j]) {
                all_equal = false;
                if (a[j] > b[j]) {
                    if (status[a[j]] == Status::stay || status[b[j]] == Status::change) {
                        cout << "No" << endl;
                        return 0;
                    }
                    status[a[j]] = Status::change;
                    status[b[j]] = Status::stay;
                } else {
                    adj[b[j]].push_back(a[j]);
                }
                break;
            }
        }
        if (all_equal && a.size() > b.size()) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (status[i] == Status::change) {
            if (!dfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    vector<int> res;
    for (int i = 1; i <= m; i++) {
        if (status[i] == Status::change)
            res.push_back(i);
    }
    cout << res.size() << endl;
    for (int i : res)
        cout << i << " ";
    cout << endl;
}