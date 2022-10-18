#include "bits/stdc++.h"
using namespace std;

const int INF = std::numeric_limits<int>::max();

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;

    auto push = [&](int cur_push) {
        for (int i = 0; i < n; i++) {
            int demand_next = max(0, a[(i+1)%n] - cur_push);
            if (i == n-1)
                return demand_next;
            if (demand_next > b[(i+1)%n])
                return INF; // impossible => infinite demand
            cur_push = b[(i+1)%n] - demand_next;
        }
    };

    int demand = push(b[0]);
    if (demand == INF) {
       cout << "NO" << '\n';
    } else {
        int to_push = max(0, b[0] - demand);
        int unassigned = b[0] - to_push;
        if (push(to_push) > unassigned)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}