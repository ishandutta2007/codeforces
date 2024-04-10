#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> cnt(201, 0);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    
    map<int, pair<int, vector<int>>> m;
    for (int i = 0; i < n; i++) {
        if (!m.count(l[i]))
            m[l[i]] = {0, {}};
        auto& p = m[l[i]];
        p.first++;
        p.second.push_back(d[i]);
    }

    vector<int> rev;
    for (auto& p : m) {
        rev.push_back(p.first);
    }
    reverse(rev.begin(), rev.end());
    
    int best_cost = std::numeric_limits<int>::max();
    int cost = 0;
    for (auto leg : rev) {
        auto& p = m[leg];
        for (auto dd : p.second)
            cnt[dd]--;
        // p.first * 2 > n - remove
        int to_remove = n - 2 * p.first + 1;
        if (to_remove <= 0) {
            best_cost = min(best_cost, cost);
        } else {
            int additional = 0;
            for (int i = 0; i <= 200; i++) {
                int x = min(cnt[i], to_remove);
                to_remove -= x;
                additional += x * i;
            }
            best_cost = min(best_cost, cost + additional);
        }

        for (int dd : p.second) {
            cost += dd;
        }
        n -= p.first;
    }

    cout << best_cost << '\n';
}