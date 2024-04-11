#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

pair<double, double> doit(double a, double b, double d) {
    vector<double> result;
    vector<double> as = {a - d, a, a + d};
    vector<double> bs = {b - d, b, b + d};

    double cmin = a * b, cmax = a * b;
    for (double x : as)
        for (double y : bs) {
            cmin = min(cmin, x * y);
            cmax = max(cmax, x * y);
        }
    return make_pair(cmin, cmax);
}

int main() {
    double a, b, c, d;

    cin >> a >> b >> c >> d;

    double l = 0, r = max(max(fabs(a), fabs(b)), max(fabs(c), fabs(d)));
    for (int i = 0; i < 1000; ++i) {
        double center = (l + r) / 2.;

        auto A = doit(a, d, center);
        auto B = doit(c, b, center);

        double left = max(A.first, B.first), right = min(A.second, B.second);
        if (left <= right) r = center;
        else l = center;
    }

    cout.precision(15); cout << fixed;
    cout << l << endl;

    return 0;
}