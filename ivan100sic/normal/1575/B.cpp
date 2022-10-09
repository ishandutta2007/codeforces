// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int x[100005], y[100005];
double d[100005];

double double_midpoint(double l, double r) {

}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    int c0 = 0, n2 = 0;
    for (int i : ra(0, n)) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            c0++;
        } else {
            ::x[n2] = x;
            ::y[n2] = y;
            d[n2] = sqrt(1.0*x*x + 1.0*y*y);
            n2++;
        }
    }
    n = n2;

    if (c0 >= k) {
        cout << "0.0\n";
        return 0;
    }

    double l = 0.5, r = 222222.0;
    for (int step : ra(0, 20)) {
        double m = sqrt(l*r);
        vector<pair<double, int>> seg;

        for (int i : ra(0, n)) {
            double x = ::x[i], y = ::y[i];
            double i_angle = atan2(y, x);

            double acos_arg = d[i] / (2*m);
            if (acos_arg > 1) {
                continue;

            }
            double delta = acos(acos_arg);
            seg.emplace_back(i_angle - delta, 1);
            seg.emplace_back(i_angle + delta, -1);
            seg.emplace_back(i_angle - delta + 2 * numbers::pi, 1);
            seg.emplace_back(i_angle + delta + 2 * numbers::pi, -1);
        }

        R::sort(seg);
        int hi = 0, run = 0;
        for (auto [k, v] : seg) {
            run += v;
            hi = max(hi, run);
        }

        if (hi >= k) {
            r = m;
        } else {
            l = m;
        }
    } 

    cout << setprecision(14) << fixed << sqrt(l*r) << '\n';
}