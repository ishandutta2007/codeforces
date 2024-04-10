// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void dps(vector<int>& a) {
    int s = a[0];
    a[0] = 0;
    for (int i : ra(1, ssize(a))) {
        int t = a[i];
        a[i] = s;
        s += t;
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    array<string, 3> a;
    for (int i : ra(0, 3)) {
        cin >> a[i];
        for (char& c : a[i]) c -= '0';
    }

    int cl = -1;
    vector<int> sg(n+1), db(n+1);
    vector<pair<int, int>> c;
    for (int i : ra(0, n)) {
        // V
        if (a[0][i]) sg[i]++;
        if (a[1][i]) sg[i]++;
        if (a[2][i]) sg[i]++;

        // Ev
        if (a[0][i] && a[1][i]) sg[i]--;
        if (a[1][i] && a[2][i]) sg[i]--;

        if (i+1 < n) {
            // Eh
            if (a[0][i] && a[0][i+1]) db[i]--;
            if (a[1][i] && a[1][i+1]) db[i]--;
            if (a[2][i] && a[2][i+1]) db[i]--;
            
            // Q
            if (a[0][i] && a[0][i+1] && a[1][i] && a[1][i+1]) db[i]++;
            if (a[1][i] && a[1][i+1] && a[2][i] && a[2][i+1]) db[i]++;
        }

        // C
        if (a[0][i] && a[1][i] && a[2][i]) {
            if (cl != -1 && i - cl >= 2) {
                c.emplace_back(cl, i+1);
            }
            cl = i;
        } else if (a[0][i] && a[2][i]) {
            // keep going
        } else {
            cl = -1;
        }
    }
    
    dps(sg);
    dps(db);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int sol = sg[r] - sg[l];
        sol += db[r-1] - db[l];

        auto it1 = R::lower_bound(c, pair(l, -1));
        auto it2 = R::upper_bound(c, pair(-1, r), [](auto u, auto v) { return u.second < v.second; });

        cout << sol + max(0ll, ll(it2 - it1)) << '\n';
    }
}