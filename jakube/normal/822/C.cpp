#include <bits/stdc++.h>
using namespace std;

struct S
{
    int l, r, cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    vector<S> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r >> v[i].cost;
    }

    vector<vector<S>> w(2e5+1);
    for (auto s : v) {
        w[s.r - s.l + 1].push_back(s);
    }

    int best_cost = numeric_limits<int>::max();
    for (int i = 0; i < x; i++) {
        auto l = w[i];
        sort(l.begin(), l.end(), [](auto p, auto q){ return p.r < q.r; });

        auto r = w[x - i];
        sort(r.begin(), r.end(), [](auto p, auto q){ return p.l < q.l; });

        if (l.size() == 0 || r.size() == 0)
            continue;

        vector<int> suffix_costs(r.size());
        suffix_costs[r.size() - 1] = r.back().cost;
        for (int i = r.size() - 2; i >= 0; i--) {
            suffix_costs[i] = min(suffix_costs[i + 1], r[i].cost);
        }

        int j = 0;
        int prefix_cost = numeric_limits<int>::max();
        for (int k = 0; k < l.size(); k++) {
            prefix_cost = min(prefix_cost, l[k].cost);

            while (j < r.size() && l[k].r >= r[j].l) {
                j++;
            }

            if (j < r.size()) {
                best_cost = min(best_cost, prefix_cost + suffix_costs[j]);
            }
        }
    }

    if (best_cost == numeric_limits<int>::max())
        cout << -1 << endl;
    else
        cout << best_cost << endl;
}