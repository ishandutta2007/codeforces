#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<long long> v;

pair<long long, long long> f(int cur) {
    visited[cur] = true;
    if (adj[cur].size() == 1 && cur != 0)
    {
        if (v[cur] > 0) {
            return {-v[cur], 0};
        }
        else {
            return {0, -v[cur]};
        }
    }

    long long mi = 0;
    long long ma = 0;
    for (int next : adj[cur]) {
        if (!visited[next]) {
            long long a, b;
            tie(a, b) = f(next);
            mi = min(mi, a);
            ma = max(ma, b);
        }
    }

    v[cur] += mi + ma;

    if (v[cur] > 0) 
        mi -= v[cur];
    else
        ma -= v[cur];

    return {mi, ma};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    visited.assign(n, false);
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto t = f(0);
    cout << t.second - t.first << endl;

    return 0;
}