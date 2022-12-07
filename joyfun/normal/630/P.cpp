#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
double n, r;


int main() {
    scanf("%lf%lf", &n, &r);
    double r1 = pi / n;
    double r2 = pi / n / 2;
    double s = n * sin(r1) * sin(r2) / sin(pi - r1 - r2);
    printf("%.100f\n", s * r * r);
    return 0;
}