#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    scanf("%lld", &n);
    int a = 2;
    for (int i = 3; i <= 10; i++)
        a = lcm(a, i);
    printf("%lld\n", n / a);
    return 0;
}