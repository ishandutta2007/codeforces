// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int f(int x) {
    return max(0, 5-2*x);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<string> a[3];
        map<string, int> cnt;
        for (int i : ra(0, 3)) {
            for (int j : ra(0, n)) {
                string s;
                cin >> s;
                a[i].push_back(s);
                cnt[s]++;
            }
        }

        for (int i : ra(0, 3)) {
            int sum = 0;
            for (int j : ra(0, n)) {
                sum += f(cnt[a[i][j]]);
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }
}