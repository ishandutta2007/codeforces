#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (auto& x : k)
        cin >> x;
    vector<pair<int, int>> dt(m);
    for (auto& x : dt) {
        cin >> x.first >> x.second;
        x.second--;
    }
    
    int L = 0; // not possible
    int R = 400'001; // possible
    while (L + 1 != R) {
        int M = (L + R) / 2;

        map<int, int> last;
        for (int i = 0; i < n; i++) {
            last[i] = 0;
        }
        for (auto [d, t] : dt) {
            if (d <= M)
                last[t] = max(last[t], d);
        }
        vector<pair<int, int>> v(last.begin(), last.end());
        sort(v.begin(), v.end(), [](auto p, auto q) {
            return p.second < q.second;
        });
        int cur = 0;
        int amount = 0;
        int later = 0;
        for (auto [t, d] : v) {
            amount += d - cur;
            cur = d;
            int max_buy = min(k[t], amount);
            amount -= max_buy;
            int rem = k[t] - max_buy;
            later += rem * 2;
        }
        amount += M - cur;
        if (amount >= later)
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}