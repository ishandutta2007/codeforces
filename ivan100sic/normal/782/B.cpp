#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double x[60005], v[60005];

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        int n;
        cin >> n; 

        for (int i=1; i<=n; i++) {
                cin >> x[i];
        }

        for (int i=1; i<=n; i++) {
                cin >> v[i];
        }

        double l = 0.0, r = 1e18;
        int steps = 100;
        while (steps--) {
                double m = (l+r) / 2;

                double lo = -1e36, hi = 1e36;
                for (int i=1; i<=n; i++) {
                        lo = max(lo, x[i] - v[i] * m);
                        hi = min(hi, x[i] + v[i] * m);
                }
                if (lo <= hi) {
                        r = m;
                } else {
                        l = m;
                }
        }
        cout.precision(20);
        cout << fixed << r;
}