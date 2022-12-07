#include <iostream>
#include <cmath>

using namespace std;
typedef long double ld;

int main() {
    int n, m;
    cin >> m >> n;

    ld ans = 0;
    ld prev = 0;
    for (int i = 1; i <= m; ++i) {
        ld p = ld(i) / ld(m);
        ld cur = powl(p, n);

        ans += ld(i) * (cur - prev);
        prev = cur;
    }

    cout.precision(15);
    cout << ans << endl;

    return 0;
}