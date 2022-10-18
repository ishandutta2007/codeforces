#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx].first >> v[idx].second;
    int q;
    cin >> q;
    
    map<int, int> m;
    map<int, vector<int>> person;
    for (auto& p : v) {
        m[p.second] = p.first;
        if (person.count(p.first)) {
            person[p.first].push_back(p.second);
        } else person[p.first] = {p.second};
    }

    vector<pair<int, int>> sorted;
    for (auto& p : person) {
        sorted.push_back({-p.second.back(), p.first});
    }
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        set<int> s;
        int total = 0;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            s.insert(x);
            if (person.count(x))
                total += person[x].size();
        }

        if (false) {
        // if (total < 333) {
            auto best = m.rbegin();
            while (best != m.rend() && s.count(best->second)) {
                ++best;    
            }
            if (best == m.rend()) {
                cout << "0 0\n";
                continue;
            }
            auto new_best = best;
            ++new_best;
            while (new_best != m.rend() && (new_best->second == best->second || s.count(new_best->second))) {
                if (new_best->second == best->second) {
                    best = new_best;
                }
                ++new_best;
            }

            if (best == m.rend()) {
                cout << "0 0\n";
                continue;
            }
            else {
                cout << best->second << ' ' << best->first << '\n';
            }
        }
        else {
            int best = 0;
            int control = 0;
            int a = -1;
            int b = -1;
            for (auto &p : sorted) {
                if (!s.count(p.second)) {
                    if (a == -1) {
                        a = p.second;
                        best = -p.first;
                    } else {
                        b = p.second;
                        control = -p.first;
                        break;
                    }
                }
            }
            
            if (a == -1) {
                cout << "0 0\n";
                continue;
            }

            best = *upper_bound(person[a].begin(), person[a].end(), control);
            cout << a << ' ' << best << '\n';
        }
    }

    cout << flush;

    return 0;
}