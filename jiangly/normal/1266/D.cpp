#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> out(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        --u;
        --v;
        out[u] += d;
        out[v] -= d;
    }
    vector<int> pos, neg;
    vector<tuple<int, int, long long>> edge;
    for (int i = 0; i < n; ++i) {
        if (out[i] > 0)
            pos.push_back(i);
        if (out[i] < 0)
            neg.push_back(i);
    }
    int i = 0, j = 0;
    while (i < pos.size()) {
        long long x = min(out[pos[i]], -out[neg[j]]);
        out[pos[i]] -= x;
        out[neg[j]] += x;
        edge.emplace_back(pos[i], neg[j], x);
        if (out[pos[i]] == 0)
            ++i;
        if (out[neg[j]] == 0)
            ++j;
    }
    cout << edge.size() << "\n";
    for (auto [u, v, p] : edge)
        cout << u + 1 << " " << v + 1 << " " << p << "\n";
    return 0;
}