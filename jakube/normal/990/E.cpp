#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> blocked(n + 1, false);
    vector<int> left(n + 1);
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        blocked[s] = true;
    }
    vector<long long> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    
    if (blocked[0]) {
        cout << -1 << '\n';
        return 0;
    }

    left[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (blocked[i])
            left[i] = left[i-1];
        else
            left[i] = i;
    }

    // find min possible
    int mi = 0;
    for (int i = 0; i <= n; i++) {
        if (left[i] == -1) {
            mi = i + 1;
        } else {
            mi = max(mi, i - left[i] + (i < n ? 1 : 0));
        }
    }
    // cout << mi << '\n';
    
    long long best = std::numeric_limits<long long>::max();
    for (int K = mi; K <= k; K++) {
        int cnt = 1;
        int cur = 0;
        while (cur + K < n) {
            cnt++;
            cur = left[min(n, cur + K)];
        }
        best = min(best, cnt * a[K-1]);
    }

    if (best == std::numeric_limits<long long>::max())
        cout << -1 << '\n';
    else
        cout << best << '\n';
}