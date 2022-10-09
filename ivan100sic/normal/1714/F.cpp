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
        int n, d12, d23, d31;
        cin >> n >> d12 >> d23 >> d31;

        auto solve = [&] {
            for (int m : ra(0, d12+1)) {
                int q1 = d31 - m;
                int q2 = d23 - (d12 - m);
                if (q1 >= 0 && q1 == q2 && q1 + d12 <= n-1 && ((m != 0 && m != d12) || q1 != 0)) {
                    // Found
                    cout << "YES\n";

                    // Unused vertex
                    int k = 4;

                    // Path
                    vector<int> p12;
                    if (q1 > 0) {
                        p12 = {1};
                        for (int i : ra(0, d12-1)) {
                            p12.push_back(k++);
                        }
                        p12.push_back(2);
                        // Path to 2
                        int z = p12[m];
                        for (int i : ra(0, q1-1)) {
                            cout << z << ' ' << k << '\n';
                            z = k++;
                        }
                        cout << z << " 3\n";
                    } else {
                        p12 = {1};
                        for (int i : ra(0, m-1)) {
                            p12.push_back(k++);
                        }
                        p12.push_back(3);
                        for (int i : ra(0, d12-m-1)) {
                            p12.push_back(k++);
                        }
                        p12.push_back(2);
                    }

                    // 1-2 path and other edges
                    for (int i : ra(0, ssize(p12) - 1)) {
                        cout << p12[i] << ' ' << p12[i+1] << '\n';
                    }                    
                    while (k <= n) {
                        cout << k++ << " 1\n";
                    }

                    return true;
                }
            }
            return false;
        };

        if (!solve()) {
            cout << "NO\n";
        }
    }
}