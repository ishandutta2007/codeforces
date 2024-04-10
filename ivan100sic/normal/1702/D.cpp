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
        string s;
        cin >> s;
        int p;
        cin >> p;

        int n = ssize(s);
        int sum = 0;
        vector<pair<int, int>> q(n);
        for (int i : ra(0, n)) {
            q[i] = {s[i] - 'a' + 1, i};
            sum += q[i].first;
        }

        R::sort(q, greater<>{});

        string rem(n, 0);

        for (int i : ra(0, n)) {
            if (sum <= p) {
                break;
            } else {
                rem[q[i].second] = 1;
                sum -= q[i].first;
            }
        }

        for (int i : ra(0, n)) {
            if (!rem[i]) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    
}