#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int cnt;
bool cycle;

int MOD = 1e9 + 7;

long long power(int k)
{
    long long base = 2;
    long long result = 1;
    while (k) {
        if (k & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        k /= 2;
    }
    return result;
}

void dfs(int v, int p)
{
    cnt++;
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        if (visited[u])
            cycle = true;
        else
            dfs(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    set<int> x, y;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        x.insert(v[i].first);
        y.insert(v[i].second);
    }

    vector<int> xs(x.begin(), x.end());
    vector<int> ys(y.begin(), y.end());
    for (auto &p : v) {
        p.first = lower_bound(xs.begin(), xs.end(), p.first) - xs.begin();
        p.second = lower_bound(ys.begin(), ys.end(), p.second) - ys.begin();
        // cout << p.first << ", " << p.second << endl;
    }

    vector<int> nodes_x(n, -1), nodes_y(n, -1);
    int idx = 0;
    adj.resize(2*n);
    for (int i = 0; i < n; i++) {
        int x = v[i].first;
        int y = v[i].second;
        if (nodes_x[x] == -1) {
            nodes_x[x] = idx;
            idx++;
        }
        if (nodes_y[y] == -1) {
            nodes_y[y] = idx;
            idx++;
        }
        adj[nodes_x[x]].push_back(nodes_y[y]);
        adj[nodes_y[y]].push_back(nodes_x[x]);
    }

    long long result = 1;
    visited.assign(idx, false);
    for (int i = 0; i < idx; i++) {
        if (!visited[i]) {
            cnt = 0;
            cycle = false;
            dfs(i, i);
            if (cycle) {
                result = (result * power(cnt)) % MOD;
            } else {
                result = (result * (power(cnt) - 1)) % MOD;
            }
        }
    }
    cout << result << endl;
}