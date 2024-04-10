#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, size;

int goal = 0;
int result1 = -1;
int result2 = -1;

pair<int, bool> dfs(int v) {
    int s = 0;
    bool b = false;
    for (int next : adj[v]) {
        auto tmp = dfs(next);
        if (tmp.second == false && tmp.first == goal) {
            if (result1 == -1) {
                result1 = next;
            } else {
                result2 = next;
            }
            b = true;
        } else if (tmp.second == true && tmp.first == 2*goal) {
            result2 = next;
            b = true;
        }
        b |= tmp.second;
        s += tmp.first;
    }
    return {s + size[v], b};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);
    parent.resize(n), size.resize(n);

    int root;
    for (int i = 0; i < n; i++) {
        cin >> parent[i] >> size[i];
        if (parent[i] == 0) {
            root = i;
        } else {
            parent[i]--;
            adj[parent[i]].push_back(i);
        }
    }

    int sum = accumulate(size.begin(), size.end(), 0);
    if (sum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    goal = sum / 3;

    dfs(root);

    if (result1 == -1 || result2 == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << result1 + 1 << ' ' << result2 + 1 << endl;
    
    return 0;
}