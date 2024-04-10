#include <iostream>
#include <iomanip>
using namespace std;

double eps = 1e-6;


void iterate(double c, double m, double p, double v, double P, double i, double& res) {
    if (c > eps) {
        double d = min(c, v);
        int div = 1;
        if (m > eps) div++;
        iterate(c - d, div == 1 ? 0 : m + d / div, p + d / div, v, P * c, i + 1, res); 
    }

    if (m > eps) {
        double d = min(m, v);
        int div = 1;
        if (c > eps) div++;
        iterate(div == 1 ? 0 : c + d / div, m - d, p + d / div, v, P * m, i + 1, res); 
    }

    res += P * p * (i + 1);
}

int main(void) {
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while (t--) {
        double c, m, p, v;
        cin >> c >> m >> p >> v;
        double res = 0;
        iterate(c, m, p, v, 1, 0, res);
        cout << res << "\n";
    }
}