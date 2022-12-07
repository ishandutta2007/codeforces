#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

double n, t;

int main() {
    scanf("%lf%lf", &n, &t);
    printf("%.100f\n", pow(1.000000011, t) * n);
    return 0;
}