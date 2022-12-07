#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

int n;
double a[N];

double cal(double x) {
    double ans1 = -1e20, ans2 = 1e20;
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] - x;
        if (s < 0) s = 0;
        ans1 = max(ans1, s);
    }
    s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] - x;
        if (s > 0) s = 0;
        ans2 = min(ans2, s);
    }
    return max(ans1, -ans2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    double l = -10001, r = 10001;
    for (int i = 0; i < 100; i++) {
        double midl = (l * 2 + r) / 3;
        double midr = (l + 2 * r) / 3;
        if (cal(midl) < cal(midr)) r = midr;
        else l = midl;
    }
    printf("%.12f\n", cal(l));
    return 0;
}