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
        int n, m, k;
        cin >> n >> m >> k;
        string a, b, c;
        cin >> a >> b;
        R::sort(a);
        R::sort(b);
        int i = 0, j = 0, s1 = 0, s2 = 0;
        while (i < n && j < m) {
            bool first;
            first = a[i] < b[j];
            if (first && s1 == k) {
                first = 0;
            } else if (!first && s2 == k) {
                first = 1;
            }

            if (first) {
                s1++;
                s2 = 0;
                c += a[i++];
            } else {
                s1 = 0;
                s2++;
                c += b[j++];
            }
        }
        cout << c << '\n';
    }
    
}