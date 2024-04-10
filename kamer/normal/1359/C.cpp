#include <iostream>
#include <cmath>
using namespace std;

const int UPPER_BOUND = 10000000;
double eps = 1e-6;


double computeAverage(double h, double c, int l) {
    return (h * (l + 1) + c * l) / (2 * l + 1);
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int H, C, T;
        cin >> H >> C >> T;
        if (H == T) {
            cout << "1 \n";
            continue;
        }
        double h = H, c = C, t = T;
        if (t <= (h + c) / 2.0 + eps) {
            cout << "2 \n";
            continue;
        }

        int l = 0, r = UPPER_BOUND / 2;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (computeAverage(h, c, mid) > t) l = mid;
            else r = mid;
        }

        double xl = computeAverage(h, c, l);
        double xr = computeAverage(h, c, r);
        if (abs(xl - t) > abs(xr - t)) {
            cout << 2 * r + 1 << "\n";
        } else {
            cout << 2 * l + 1 << "\n";
        }
    }
}