#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll xa, ya, xb, yb;

int main() {
    scanf("%lld%lld%lld%lld", &xa, &ya, &xb, &yb);
    printf("%lld\n", ((xb - xa + 1) * (yb - ya + 1) + 1) / 2);
    return 0;
}