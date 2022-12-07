#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll a, b, c;

int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a == 0) printf("%.100f %.100f\n", -c * 1.0 / b, -c * 1.0 / b);
    else {
        double det = sqrt(b * b - 4 * a * c);
        double a1 = (-b * 1.0 + det) / 2 / a;
        double a2 = (-b * 1.0 - det) / 2 / a;
        if (a1 < a2) swap(a1, a2);
        printf("%.100f %.100f\n", a1, a2);
    }
    return 0;
}