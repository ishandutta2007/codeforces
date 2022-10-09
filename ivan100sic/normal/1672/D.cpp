// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void ans(bool x) {
    cout << (x ? "YES\n" : "NO\n");
}

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

        vector<int> mem(n+1);
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] == b[j]) {
                int x = a[i];
                // go forward
                i++;
                j++;
                // Try to repay debt
                while (mem[x] > 0 && j < n && x == b[j]) {
                    mem[x]--;
                    j++;
                }
            } else {
                // debt
                mem[a[i++]]++;
            }
        }

        ans(i == n && j == n);
    }
}