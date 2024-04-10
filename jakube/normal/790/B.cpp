#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
long long result = 0;

pair<int, array<long long, 5>> compute(int v, int p) {
    int size = 1;
    array<long long, 5> cnt = {{0}};

    for (int u : adj[v]) {
        if (u == p) continue;

        auto res = compute(u, v);
        size += res.first;

        for (int i = 1; i < k; i++)
            result += res.second[i];

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result += (i + j + k - 1) / k * cnt[i] * res.second[j];
            }
        }

        for (int i = 0; i < k; i++)
            cnt[i] += res.second[i];
    }

    cnt[0]++;

    array<long long, 5> cnt2;
    for (int i = 0; i < k; i++) {
        if (i < k - 1) {
            cnt2[i+1] = cnt[i];
        } else {
            result += cnt[i] * (n - size);
            cnt2[0] = cnt[i];
        }
    }

    return {size, cnt2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    compute(1, 0);

    cout << result << endl;
}