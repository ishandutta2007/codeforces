#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w, h;
    cin >> n >>  w >> h;
    vector<pair<pair<int, int>, int>> y, x;
    vector<pair<int, int>> goals(n);

    for (int i = 0; i < n; i++) {
        int g, p, t;
        cin >> g >> p >> t;
        if (g == 1) {
            goals[i] = { p, h };
            x.push_back({{p, t - p}, i});
        } else {
            goals[i] = { w, p };
            y.push_back({{p, t - p}, i});
        }
    }

    sort(y.begin(), y.end());
    sort(x.begin(), x.end());

    map<int, vector<pair<int, int>>> orig_goals;
    map<int, deque<int>> X;
    for (auto p : x) {
        X[p.first.second].push_back(p.second);
        orig_goals[p.first.second].push_back({p.first.first, h});
    }

    vector<pair<int, int>> result(n);

    int idx = 0;
    for (int i = 1; i <= h; i++) {
        while (idx < y.size() && y[idx].first.first == i) {
            // search for T - P
            int search = y[idx].first.second;
            if (X.count(search)) {
                X[search].push_front(y[idx].second);
                int last = X[search].back();
                X[search].pop_back();
                result[last] = { w, i };
            } else {
                result[y[idx].second] = { w, i };
            }
            idx++;
        }
    }

    for (auto& pq : X) {
        auto& g = orig_goals[pq.first];
        auto& q = pq.second;

        for (int i = 0; i < g.size(); i++) {
            result[q.front()] = g[i];
            q.pop_front();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i].first << " " << result[i].second << '\n';
    }

    // T_i + p_i =  t_i + x
    // T_i = t_i - p_i + x
}