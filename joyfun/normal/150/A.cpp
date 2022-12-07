#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long q;
long long cnt[1005], cn;

int main() {
    scanf("%lld", &q);
    long long qq = q;
    for (long long i = 2; i * i <= q; i++) {
        while (q % i == 0) {
            q /= i;
            cnt[cn++] = i;
        }
    }
    if (q != 1) cnt[cn++] = q;
    if (cn <= 1) printf("1\n0\n");
    else {
        if (1LL * cnt[0] * cnt[1] == qq) printf("2\n");
        else {
            printf("1\n%lld\n", 1LL * cnt[0] * cnt[1]);
        }
    }
    return 0;
}