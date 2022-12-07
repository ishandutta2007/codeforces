#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long m;

long long mi(long long x) {
    return x * x * x;
}

long long cal(long long x) {
    long long sum = 0;
    for (long long i = 2; mi(i) <= x; i++) {
        sum += x / mi(i);
        if (sum > m) return sum;
    }
    return sum;
}

int main() {
    scanf("%lld", &m);
    long long l = 0, r = m * 8 + 1;
    while (l < r) {
        long long mid = (l + r)>>1;
        if (cal(mid) >= m) r = mid;
        else l = mid + 1;
    }
    if (cal(l) > m) printf("-1\n");
    else printf("%lld\n", l);
    return 0;
}