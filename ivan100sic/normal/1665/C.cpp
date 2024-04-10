// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void remzeros(auto& v) {
    v.erase(R::partition(v, [](int x) { return x > 0; }, {}).begin(), v.end());
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ch(n+1);
        for (int i : ra(2, n+1)) {
            int p;
            cin >> p;
            ch[p]++;
        }
        R::sort(ch, greater<int>{});
        remzeros(ch);
        ch.push_back(1);

        int sol = 0;
        for (int i : ra(0, ssize(ch))) {
            sol = max(sol, ch[i] + i);
        }

        if (sol == ssize(ch)) {
            cout << sol << '\n';
        } else {
            vector<int> e;
            for (int i : ra(0, ssize(ch))) {
                int x = ch[i] + i - ssize(ch);
                if (x > 0) {
                    e.push_back(x);
                }
            }

            int steps = 0;
            while (e.size()) {
                int i = R::max_element(e) - begin(e);
                e[i]--;
                if (e[i] > 0) {
                    e[i]--;
                }
                for (int j : ra(0, ssize(e))) {
                    if (j != i) {
                        e[j]--;
                    }
                }
                remzeros(e);
                steps++;
            }
            
            cout << ssize(ch) + steps << '\n';
        }
    }
}