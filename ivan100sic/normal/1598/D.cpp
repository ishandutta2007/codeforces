// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

ll cuv(const vector<int>& a) {
    vector<int> b(a.size() + 1);
    for (auto x : a) b[x]++;

    ll s = 0, p = 0, t = 0;
    for (auto v : b) {
        if (!v) continue;
        t += p * v;
        p += s * v;
        s += v;
    }

    return t;
}

ll cup(vector<pair<int, int>>&& a) {
    R::sort(a);
    int n = ssize(a);
    vector<int> l(n+1), r(n+1);
    ll sp = 0, lc = 0, rc = n, sol = 0;

    for (auto [x, y] : a) r[y]++;

    for (int i=0; i<n;) {
        int j = i;
        while (j < n && a[j].first == a[i].first) j++;

        for (int k=i; k<j; k++) {
            int y = a[k].second;
            sp -= l[y];
            r[y]--;
            rc--;
        }

        for (int k=i; k<j; k++) {
            int y = a[k].second;
            sol += lc * rc - sp - l[y] * (rc - r[y]) - r[y] * (lc - l[y]);
        }

        for (int k=i; k<j; k++) {
            int y = a[k].second;
            sp += r[y];
            l[y]++;
            lc++;
        }

        i = j;
    }

    return sol;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i : ra(0, n)) {
            cin >> a[i] >> b[i];
        }

        ll sol = cuv(a) + cuv(b);
        vector<pair<int, int>> c(n);
        for (int i : ra(0, n)) c[i] = {a[i], b[i]};
        sol -= cup(move(c));
        cout << sol << '\n';
    }
}