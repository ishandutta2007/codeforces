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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<int> ka;
        for (int l=0, r=n-1; l<r; l++, r--) {
            if (a[l] != a[r]) {
                ka = {a[l], a[r]};
                break;
            }
        }

        bool found = false;
        if (ka.empty()) {
            found = true;
        }

        for (int x : ka) {
            bool ok = true;
            for (int l=0, r=n-1; l<r;) {
                if (a[l] != a[r]) {
                    if (a[l] == x && a[r] == x) {
                        l++;
                        r--;
                    } else if (a[l] == x) {
                        l++;
                    } else if (a[r] == x) {
                        r--;
                    } else {
                        ok = false;
                        break;
                    }
                } else {
                    l++;
                    r--;
                }
            }

            if (ok) found = true;
        }

        cout << (found ? "YES\n" : "NO\n");
    }
    
}