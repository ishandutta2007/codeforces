// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct state {
    int p, q;
    state* prev;

    strong_ordering operator<=> (const state& b) const = default;
};

const int inf = 123123123;
state neut = {-inf, -inf, nullptr};

void shorten(vector<state>& b) {
    if (b.empty()) return;
    R::sort(b);
    int j = 0;
    for (int i : ra(1, ssize(b))) {
        if (b[i].p > b[j].p && b[i].q < b[j].q) {
            // keep it
            b[++j] = b[i];
        }
    }
    b.resize(j + 1);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<vector<state>> b(n+1);
        b[0].push_back(neut);

        for (int i : ra(0, n)) {
            auto& nu = b[i+1];
            for (int x : {-a[i], a[i]}) {
                for (auto& s1 : b[i]) {
                    state s2 = s1;
                    s2.prev = &s1;
                    bool invalid = 0;
                    if (x >= s2.p) {
                        s2.p = x;
                    } else if (x >= s2.q) {
                        s2.q = x;
                    } else {
                        invalid = 1;
                    }

                    if (!invalid) {
                        nu.push_back(s2);
                    }
                }
            }

            shorten(nu);
        }

        if (b[n].empty()) {
            cout << "NO\n";
            continue;
        }

        vector<int> c(n);
        auto s = b[n].back();
        for (int i=n-1; i>=0; i--) {
            if (abs(s.p) == a[i]) c[i] = s.p;
            else c[i] = s.q;

            s = *s.prev;
        }

        cout << "YES\n";
        for (int x : c) cout << x << ' ';
        cout << '\n';
    }
}