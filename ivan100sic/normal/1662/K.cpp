// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using pt = complex<double>;
using numbers::pi;

pt rd() {
    int x, y;
    cin >> x >> y;
    return pt{x, y};
}

const double third = 2.0 * pi / 3.0;
const double sixth = 1.0 * pi / 3.0;

pt intersection(pt a, pt b, pt c, pt d) {
    pt p = (conj(b-a)*a - (b-a)*conj(a))*(d-c);
    pt q = (conj(d-c)*c - (d-c)*conj(c))*(b-a);
    pt r = (d-c)*conj(b-a) - (b-a)*conj(d-c);

    return (p-q) / r;
}

double fermat(pt a, pt b, pt c) {
    pt quot = (c-a)*conj(b-a);
    if (quot.imag() < 0.0) {
        quot = conj(quot);
        swap(b, c);
    }

   double ang = arg(quot);
   // cerr << "ang: " << ang << a << ' ' << b << ' ' << c << '\n';

   if (ang >= third) {
       // cerr << "big ang\n";
       return abs(b-a) + abs(c-a);
   } else {
       pt bb = a + (b-a)*exp(-1i * sixth);
       pt cc = a + (c-a)*exp(+1i * sixth);

       pt mid = intersection(b, cc, c, bb);
       return abs(mid-a) + abs(mid-b) + abs(mid-c);
   }
}

double dist(pt a, pt b, pt c) {
    double dab = abs(a-b);
    double dbc = abs(b-c);
    double dca = abs(c-a);

    double dmax = max({dab, dbc, dca});
    if (dbc == dmax) {
        swap(a, c);
    } else if (dca == dmax) {
        swap(b, c);
    }

    return fermat(c, a, b);
}

const int steps = 1000000;

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    const double beta = 100.0 / steps;

    pt a = rd(), b = rd(), c = rd();

    if (((b-a)*conj(c-a)).imag() == 0.0) {
        cout << max({abs(b-a), abs(c-b), abs(a-c)}) << '\n';
        return 0;
    }

    pt g = (a+b+c) / 3.0;

    for (int i : ra(0, steps)) {
        auto dab = dist(g, a, b);
        auto dbc = dist(g, b, c);
        auto dca = dist(g, c, a);

        double dmax = max({dab, dbc, dca});
        pt push = 0.0;
        push += (dab-dmax)/dmax * (g-c);
        push += (dbc-dmax)/dmax * (g-a);
        push += (dca-dmax)/dmax * (g-b);
        push *= beta;

        g += push;

        // cerr << g << ' ' << dab << ' ' << dbc << ' ' << dca << '\n';
    }

    cout << max({dist(g, a, b), dist(g, b, c), dist(g, c, a)}) << '\n';
}