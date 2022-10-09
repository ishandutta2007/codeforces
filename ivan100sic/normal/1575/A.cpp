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

    int n, m;
    cin >> n >> m;
    vector<string> aa(n);
    for (auto& s : aa) cin >> s;

    vector<int> p(n);
    iota(begin(p), end(p), 0);

    R::sort(p, [&](int i, int j) {
        string a = aa[i];
        string b = aa[j];
        for (int i=0; i<m; i++) {
            if (a[i] != b[i]) {
                if (i % 2 == 0) return a[i] < b[i];
                else return a[i] > b[i];
            }
        }
        return false;
    });

    for (int x : p) cout << x+1 << ' ';
    cout << "\n";
}