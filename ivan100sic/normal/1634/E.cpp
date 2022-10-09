// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct xyz {
    int x, y;
    char* sol;

    strong_ordering operator<=>(const xyz& b) const = default;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int m;
    cin >> m;

    set<xyz> a, b;
    vector<string> sol(m);
    map<int, int> c;

    for (int i : ra(0, m)) {
        int k;
        cin >> k;
        sol[i].resize(k, '?');
        map<int, int> seen;
        for (int j : ra(0, k)) {
            int x;
            cin >> x;
            if (seen.count(x)) {
                int y = seen[x];
                seen.erase(x);
                sol[i][j] = 'L';
                sol[i][y] = 'R';
            } else {
                seen[x] = j;
            }
        }

        for (auto [what, where] : seen) {
            a.insert({i, what, &sol[i][where]});
            b.insert({what, i, &sol[i][where]});
            c[what]++;
        }
    }

    for (auto [k, v] : c) {
        if (v % 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    while (a.size()) {
        auto [x, y, id] = *a.begin();
        a.erase(a.begin());
        b.erase({y, x, id});
        while (1) {
            *id = 'L';
            auto it2 = b.lower_bound({y, -1, nullptr});
            // if (it2 == b.end() || it2->x != y) {
            //     break;
            // }

            auto [x2, y2, id2] = *it2;
            b.erase(it2);
            a.erase({y2, x2, id2});
            *id2 = 'R';

            auto it = a.lower_bound({y2, -1, nullptr});
            if (it == a.end() || it->x != y2) {
                break;
            }

            x = it->x;
            y = it->y;
            id = it->sol;
            a.erase(it);
            b.erase({y, x, id});
        }
    }

    for (auto s : sol) cout << s << '\n';
}