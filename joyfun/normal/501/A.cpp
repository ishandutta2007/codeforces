#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a, b, c, d;

int main() {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double a1 = max(3 * a / 10, a - a / 250 * c);
    double a2 = max(3 * b / 10, b - b / 250 * d);
    if (a1 < a2) printf("Vasya\n");
    else if (a1 > a2) printf("Misha\n");
    else printf("Tie\n");
    return 0;
}