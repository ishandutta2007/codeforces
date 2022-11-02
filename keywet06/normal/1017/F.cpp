#include <bits/stdc++.h>
#define SC scanf
typedef unsigned int uint;
using namespace std;

bitset<100000001> bs;
uint n, A, B, C, D, ans;

void zad(uint x)
{
    uint sum = A * x * x * x + B * x * x + C * x + D, o = n;
    while (o / x) ans += sum * (o /= x);
    return;
}

int main() {
    SC("%u %u %u %u %u", &n, &A, &B, &C, &D);
    zad(2), zad(3);
    for (uint i = 5, ch = 2; i <= n; i += ch, ch = 6 - ch) {
        if (bs[i / 3]) continue;
        zad(i);
        if (i > n / i) continue;
        for (uint j = i * i, v = ch; j <= n; j += v * i, v = 6 - v)
            bs[j / 3] = 1;
    }
    printf("%u", ans);
}