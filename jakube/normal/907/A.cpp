#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d;
    g = max({c, d});
    f = max({g + 1, b, d, 2*d + 1});
    e = max({f + 1, a, d, 2*d + 1});
    if (2 * a < e || 2 * b < f || 2 * c < g || 2 * d < g)
        cout << -1 << '\n';
    else
        cout << e << endl << f << endl << g << endl;
}