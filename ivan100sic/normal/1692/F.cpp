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
        int f[10] = {0};
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            f[x % 10]++;
        }

        vector<int> a;
        for (int i : ra(0, 10)) {
            for (int j : ra(0, min(3, f[i]))) {
                a.push_back(i);
            }
        }

        int m = ssize(a);
        string s = "NO\n";
        for (int i : ra(0, m)) {
            for (int j : ra(0, i)) {
                for (int k : ra(0, j)) {
                    if ((a[i] + a[j] + a[k]) % 10 == 3) {
                        s = "YES\n";
                    }
                }
            }
        }

        cout << s;
    }
    
}