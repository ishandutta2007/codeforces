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
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<int> a;
        for (auto [k, v] : mp) a.push_back(v);

        cout << *R::partition_point(ra(1, n/k+1), [&](int m) {
            // pairs
            int p=0, s=0;
            for (int x : a) {
                p += x / 2;
                s += x % 2;
            }

            // sat. pairs
            p -= m/2 * k;
            if (p < 0) return false;
            // sat singles
            s += 2*p;
            s -= m%2 * k;
            return s >= 0;
        }) - 1 << '\n';
    }
}