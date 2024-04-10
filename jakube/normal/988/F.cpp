#include <bits/stdc++.h>
using namespace std;

enum Event {
    R = 0, U = 1, L = 2
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, n, m;
    cin >> a >> n >> m;
    vector<pair<int, int>> rain(n);
    for (int i = 0; i < n; i++) {
        cin >> rain[i].first >> rain[i].second;
    }
    vector<int> umbrellas(m);
    vector<int> weight(3000, std::numeric_limits<int>::max());
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u;
        umbrellas[i] = u;
        int w;
        cin >> w;
        weight[u] = min(weight[u], w);
    }
    sort(rain.begin(), rain.end());
    sort(umbrellas.begin(), umbrellas.end());
    
    if (umbrellas[0] > rain[0].first) {
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<int, Event>> events;
    for (int x : umbrellas) {
        events.push_back({x, U});
    }
    for (auto [l, r] : rain) {
        events.push_back({l, L});
        events.push_back({r, R});
    }
    sort(events.begin(), events.end());

    
    vector<long long> dp(events.size(), 0);
    bool raining = false;
    for (int i = 0; i < (int)events.size(); i++) {
        auto [idx, e] = events[i];
        if (e == R) {
            raining = false;
            long long best = std::numeric_limits<long long>::max();
            for (int j = 0; j < i; j++) {
                if (events[j].second == U) {
                    int u = events[j].first;
                    best = min(best, dp[j] + (idx - u) * weight[u]);
                }
            }
            dp[i] = best;
        }
        if (e == U) {
            if (raining) {
                long long best = std::numeric_limits<long long>::max();
                for (int j = 0; j < i; j++) {
                    if (events[j].second == U) {
                        int u = events[j].first;
                        best = min(best, dp[j] + (idx - u) * weight[u]);
                    }
                }
                dp[i] = best;
            } else {
                long long best = 0;
                for (int j = i-1; j >= 0; j--) {
                    if (events[j].second == R) {
                        best = dp[j];
                        break;
                    }
                }
                dp[i] = best;
            }
        }
        if (e == L)
            raining = true;
    }

    for (int i = (int)events.size() - 1; i >= 0; i--) {
        if (events[i].second == R) {
            cout << dp[i] << '\n';
            return 0;
        }
    }
}