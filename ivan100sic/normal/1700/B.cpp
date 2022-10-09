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
        string s;
        cin >> s;
        if (s[0] <= '7') {
            for (char& c : s) {
                c = '9' - c + '0';
            }
            cout << s << '\n';
        } else {
            vector<int> a(n+1, 1);
            for (int i : ra(0, n)) {
                a[i] -= s[n-1-i] - '0';
            }
            for (int i : ra(0, n)) {
                if (a[i] < 0) {
                    a[i+1] -= 1;
                    a[i] += 10;
                } else if (a[i] > 9) {
                    a[i+1] += 1;
                    a[i] -= 10;
                }
            }

            for (int i=n-1; i>=0; i--) {
                cout << a[i];
            }
            cout << '\n';
        }
    }
}