#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> r(n), l(n);
        vector<pii> events;
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            l[i] = r[i] - l[i] + 1;
            events.emplace_back(l[i], -1);
            events.emplace_back(r[i], 1);
        }
        sort(events.begin(), events.end());
        int balance = 0;
        ll start = 0;
        ll ans = 0;
        for (int i = 0; i < 2 * n; ++i) {
            ll tm = events[i].first;
            if (balance == 0) {
                start = tm;
            }
            balance += events[i].second;
            if (balance == 0) {
                ans += (tm - start + 1) * (ll)(tm - start + 2) / 2LL;
            }
        }
        cout << ans << "\n";
    }
}