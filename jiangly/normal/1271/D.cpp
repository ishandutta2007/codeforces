#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5000;
int n, m, k;
int r[N], a[N], b[N], c[N], dp[N + 1];
vector<int> e[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        r[i] = i;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[v] = max(r[v], u);
    }
    for (int i = 0; i < n; ++i)
        e[r[i]].push_back(i);
    memset(dp, -1, sizeof(dp));
    dp[k] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = N - b[i]; j >= a[i]; --j)
            dp[j + b[i]] = dp[j];
        for (int j = 0; j < a[i] + b[i]; ++j)
            dp[j] = -1;
        for (int j : e[i])
            for (int k = 0; k < N; ++k)
                if (dp[k + 1] != -1)
                    dp[k] = max(dp[k], dp[k + 1] + c[j]);
    }
    cout << *max_element(dp, dp + N + 1) << endl;
    return 0;
}