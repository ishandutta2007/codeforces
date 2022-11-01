#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const double eps = 1e-9;

int main(void) {
    int n, q, a, b;
    scanf("%d%d%d%d", &n, &q, &a, &b);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    vector<double> y(n);
    vector<int> from(n, -1);
    y[0] = x[0];
    for (int i = 1; i < n; ++i) {
        double shiftSum = 0.0;
        shiftSum = 0.0;
        double curPos = x[i];
        int j;
        double shift = 0.0;
        double maxShift = q - curPos;
        double minShift = 1.0 - curPos;
        for (j = i - 1; j >= 0; j--) {
            shift = max(minShift, min(maxShift, shiftSum / (i - j)));
            double pos = curPos + shift;
            if (pos >= y[j] + a - eps && pos <= y[j] + b + eps)
                break;
            if (pos >= y[j] + b) {
                curPos -= b;
            } else {
                curPos -= a;
            }
            minShift = max(minShift, 1.0 - curPos);
            shiftSum += x[j] - curPos;
        }
        shift = max(minShift, min(maxShift, shiftSum / (i - j)));
        y[i] = x[i] + shift;
        from[i] = j;
    }
    vector<double> ry(n);

    for (int i = n-1; i >= 0;) {
        ry[i] = y[i];
        for (int j = i - 1; j > from[i]; --j) {
            if (ry[j+1] >= y[j] + b)
                ry[j] = ry[j+1] - b;
            else
                ry[j] = ry[j+1] - a;
        }
        i = from[i];
    }

    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        double d = ry[i] - x[i];
        res += d*d;
        printf("%.9lf ", ry[i]);
    }
    printf("\n%.9lf\n", res);
}