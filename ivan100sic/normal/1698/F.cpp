// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        if (n == 1) {
            if (a[0] == b[0]) {
                cout << "YES\n0\n";
            } else {
                cout << "NO\n";
            }
            continue;
        }

        map<pair<int, int>, int> mp;
        for (int i : ra(0, n-1)) {
            mp[minmax({a[i], a[i+1]})]++;
            mp[minmax({b[i], b[i+1]})]--;
        }

        if (R::any_of(mp, [](auto x) { return x.second != 0; }) ||
            a[0] != b[0] || a[n-1] != b[n-1])
        {
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> sol;
        for (int i : ra(1, n-1)) {
            if (a[i] != b[i]) {
                // Find in the right order

                auto go = [&] {
                    int jf = -1;
                    for (int j : ra(i, n-1)) {
                        if (a[j] == b[i] && a[j+1] == b[i-1]) {
                            jf = j;
                            break;
                        } 
                    }

                    if (jf != -1) {
                        reverse(a.begin() + i - 1, a.begin() + jf + 2);
                        sol.emplace_back(i-1, jf+1);
                        return true;
                    }

                    return false;
                };

                if (!go()) {
                    int jf = -1;
                    for (int j : ra(i, n-1)) {
                        if (a[j+1] == b[i] && a[j] == b[i-1]) {
                            jf = j;
                            break;
                        } 
                    }

                    // Find two equals around this pair jf,jf+1
                    vector<int> posl(n+1, -1);
                    for (int p : ra(i-1, jf+1)) {
                        // cerr << "writing in " << a[p] << ' ' << p << '\n';
                        posl[a[p]] = p;
                    }

                    for (int p : ra(jf+1, n)) {
                        if (posl[a[p]] != -1) {
                            // good, reverse it
                            int l = posl[a[p]];
                            int r = p;

                            // cerr << "reversing " << a[l] << ' ' << a[r] << ' ' << l << ' ' << r << '\n';

                            reverse(a.begin() + l, a.begin() + r + 1);
                            sol.emplace_back(l, r);

                            go();
                            break;
                        }
                    }
                }
            }
        }

        cout << "YES\n";
        cout << sol.size() << '\n';
        for (auto [x, y] : sol) {
            cout << x+1 << ' ' << y+1 << '\n';
        }
    }
}