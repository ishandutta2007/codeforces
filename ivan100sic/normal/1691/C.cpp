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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int l=n, r=-1;
        for (int i : ra(0, n)) {
            if (s[i] == '1') {
                l = min(l, i);
                r = max(r, i);
            }
        }

        if (r == -1) {
            // nothing
            cout << "0\n";
            continue;
        }

        if (l == r) {
            // can only move into one of?
            if (n-1-l <= k) {
                cout << "1\n";
            } else if (l <= k) {
                cout << "10\n";
            } else {
                cout << "11\n";
            }
            continue;
        }

        int sum = 0;
        for (int i : ra(0, n-1)) {
            sum += (s[i]-'0')*10 + s[i+1]-'0';
        }

        // can move both?
        int redux = 0;
        if (n-1-r + l <= k && n-1-r && l) {
            redux = 11;
        } else if (n-1-r <= k && n-1-r) {
            redux = 10;
        } else if (l <= k && l) {
            redux = 1;
        }

        cout << sum - redux << '\n';
    }
}