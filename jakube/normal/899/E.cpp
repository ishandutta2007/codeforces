#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    set<pair<int, int>> lens, positions;
    pair<int, int> p = {0, 0};
    for (int i = 0; i < n; i++) {
        if (p.first != v[i])
            p = {v[i], 0};
        p.second++;
        if (i == n-1 || v[i] != v[i+1]) {
            lens.insert({-p.second, i + 1 - p.second});
            positions.insert({i + 1 - p.second, -p.second});
        }
    }

    int cnt = 0;
    while (lens.size()) {
        cnt++;
        auto p = *lens.begin();
        lens.erase(lens.begin());
        auto it = positions.lower_bound({p.second, p.first});
        if (it == positions.begin()) {
            positions.erase(positions.begin());
        } else {
            auto prev = it;
            --prev;
            auto next = it;
            ++next;
            auto prev_val = *prev;
            auto next_val = *next;
            auto it_val = *it;
            if (next != positions.end()) {
                if (v[prev_val.first] == v[next_val.first]) {
                    lens.erase(lens.lower_bound({prev_val.second, prev_val.first}));
                    lens.erase(lens.lower_bound({next_val.second, next_val.first}));
                    pair<int, int> neww = {prev_val.first, prev_val.second + next_val.second};
                    positions.erase(positions.lower_bound(prev_val));
                    positions.erase(positions.lower_bound(next_val));
                    positions.insert(neww);
                    lens.insert({neww.second, neww.first});
                }
            }
            positions.erase(positions.lower_bound(it_val));
        }
    }
    cout << cnt << endl;
}