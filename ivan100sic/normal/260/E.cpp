// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int x[100005], y[100005];
int x_orig[100005], y_orig[100005];
int a[9];
vector<int> x_map, y_map;

void uq(int* orig, int* a, vector<int>& v) {
    v.resize(n);
    copy(orig, orig+n, v.begin());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i : ra(0, n)) {
        a[i] = R::lower_bound(v, orig[i]) - begin(v);
    }
}

bool ystdone[100005];
vector<int> ystorage[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x_orig[i] >> y_orig[i];
    }

    uq(x_orig, x, x_map);
    uq(y_orig, y, y_map);
    for (int i : ra(0, 9)) {
        cin >> a[i];
    }

    R::sort(a);
    vector<int> xsorted(x, x+n);
    R::sort(xsorted);

    auto dox = [&](int xb) {
        if (ystdone[xb]) return;
        ystdone[xb] = true;

        for (int i : ra(0, n)) {
            if (x[i] < xb) {
                ystorage[xb].push_back(y[i]);
            }
        }
        R::sort(ystorage[xb]);
    };

    for (int i : ra(0, 9)) {
        for (int j : ra(i+1, 9)) {
            for (int k : ra(j+1, 9)) {
                int sum = a[i] + a[j] + a[k];
                for (int cnt : {sum, n-sum}) {
                    int xb = xsorted[cnt];
                    dox(xb);
                }
            }
        }
    }

    dox(n);

    auto lesscnt = [&](int x, int y) -> int {
        return R::lower_bound(ystorage[x], y) - ystorage[x].begin();
    };

    do {
        int x1 = xsorted[accumulate(a, a+3, 0)];
        int x2 = xsorted[accumulate(a, a+6, 0)];

        if (!ystdone[x1] || !ystdone[x2]) continue;

        auto vg = [&](auto& v, int x) {
            return x < ssize(v) ? v[x] : -1;
        };

        int y1 = vg(ystorage[n], a[0] + a[3] + a[6]);
        int y2 = vg(ystorage[n], n - a[2] - a[5] - a[8]);

        if (y1 == -1 || y2 == -1) continue;

        // let's try
        if (lesscnt(x1, y1) == a[0] &&
            lesscnt(x1, y2) == a[0] + a[1] &&
            lesscnt(x1, n) == a[0] + a[1] + a[2] &&
            lesscnt(x2, y1) == a[0] + a[3] &&
            lesscnt(x2, y2) == a[0] + a[3] + a[1] + a[4] &&
            lesscnt(x2, n) == a[0] + a[3] + a[1] + a[4] + a[2] + a[5] &&
            lesscnt(n, y1) == a[0] + a[3] + a[6] &&
            lesscnt(n, y2) == a[0] + a[3] + a[6] + a[1] + a[4] + a[7])
        {
            x1 = x_map[x1];
            x2 = x_map[x2];
            y1 = y_map[y1];
            y2 = y_map[y2];
            cout << fixed << x1-0.5 << ' ' << x2-0.5 << '\n' << y1-0.5 << ' ' << y2-0.5 << '\n';
            return 0;
        }

    } while (next_permutation(a, a+9));

    cout << "-1\n";
}