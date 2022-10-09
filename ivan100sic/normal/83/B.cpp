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

    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (accumulate(begin(a), end(a), 0ll) < k) {
        cout << "-1\n";
        return 0;
    }

    auto lc = [&](int m) {
        ll z = 0;
        for (int x : a) {
            z += min(x, m);
        }
        return z;
    };

    int l = *R::partition_point(ra(0, int(1e9+3)), [&](int m) {
        return lc(m) <= k;
    }) - 1;

    k -= lc(l);
    for (int& x : a) x -= min(x, l);

    deque<int> dq;
    for (int i : ra(0, n)) dq.push_back(i);

    while (k > 0) {
        int i = dq.front();
        dq.pop_front();
        if (a[i] == 0) continue;
        a[i]--;
        k--;
        if (a[i] > 0) {
            dq.push_back(i);
        }
    }

    for (int x : dq) if (a[x] > 0) {
        cout << x+1 << ' ';
    }

    cout << '\n';
}