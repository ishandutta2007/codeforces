#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

int main() {
    scanf("%lld", &n);
    printf("%lld\n", 1 + n * (n + 1) * 3);
    return 0;
}