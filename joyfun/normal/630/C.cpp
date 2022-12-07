#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int n;

int main() {
    scanf("%d", &n);
    printf("%lld\n", (1LL<<(n + 1)) - 2);
    return 0;
}