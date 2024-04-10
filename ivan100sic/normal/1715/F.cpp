// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

using cd = complex<double>;

valarray<cd> teeth() {
    valarray<cd> a(301);
    for (int i=0; i<100; i++) {
        a[3*i+0] = cd(1.2 * i, 200);
        a[3*i+1] = cd(1.2 * i + 0.05, 0);
        a[3*i+2] = cd(1.2 * i + 0.10, 200);
    }
    a[300] = cd(500, 500);
    return a;
}

double ask(valarray<cd> a) {
    cout << "? " << a.size() << "\n";

    for (auto x : a) {
        cout << x.real() << ' ' << x.imag() << '\n';
    }
    cout << flush;
    double r;
    cin >> r;
    return r;
}

double find_coord(valarray<cd> t, char xy) {
    auto offs1 = xy == 'x' ? cd(4, 0) : cd(0, 4);
    auto offs2 = xy == 'x' ? cd(0.6, 0) : cd(0, 0.6);
    auto tx1 = t - offs1;
    auto tx2 = tx1 - offs2;

    double xc1 = ask(tx1);
    double xc2 = ask(tx2);
    return max(xc1, xc2);
}

double f(double x) {
    return x*2000 - 0.5;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;

    auto tx = teeth();
    double x = find_coord(tx, 'x');

    auto ty = tx;
    for (int i = 0; i < ssize(tx); i++) {
        ty[i] = cd(tx[i].imag(), tx[i].real());
    }

    double y = find_coord(ty, 'y');

    cout << "! " << f(y) << ' ' << f(x) << '\n' << flush;
}