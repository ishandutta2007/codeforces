// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool ispal(string_view s) {
    return R::equal(s, R::reverse_view(s));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool f = 0;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        // 1
        for (auto& s : a) {
            if (ispal(s)) {
                f = 1;
            }
        }

        auto go2 = [&](const auto& a, auto ins) {
            set<string> had;
            for (auto& s : a) {
                int k = ssize(s);
                for (int l=1; l<=k; l++) {
                    string p(l + k, 0);
                    for (int i : ra(0, k)) p[l+i] = s[i];
                    for (int i : ra(0, l)) p[i] = s[k-i-1];
                    if (ispal(p) && had.count(p.substr(0, l))) {
                        f = 1;
                    }
                }
                ins(had, s);
            }
        };

        auto go = [&]() {
            go2(a, [&](auto& had, auto& s) { had.insert(s); });

            // 3
            for (char x : ra('a', 'z'+1)) {
                int j = -1;
                for (int i=ssize(a); i>=0; i--) {
                    if (a[i] == string(1, x)) {
                        j = i;
                        break;
                    }
                }

                if (j == -1) continue;

                vector b(begin(a), begin(a) + j);
                go2(b, [&](auto& had, auto& s) { 
                    if (s.size() > 1 && s[0] == x) {
                        had.insert(s.substr(1));
                    }
                });
            }
        };

        go();
        for (auto& s : a) {
            R::reverse(s);
        }
        R::reverse(a);
        go();

        cout << (f ? "YES\n" : "NO\n");
    }
}