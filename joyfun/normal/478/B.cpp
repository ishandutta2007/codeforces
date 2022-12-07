#include <cstdio>
#include <cstring>

typedef long long ll;

ll n, m;

int main() {
    scanf("%lld%lld", &n, &m);
    ll yu = n - m + 1;
    ll Max = yu * (yu - 1) / 2;
    yu = n % m;
    ll sb = n / m;
    ll sbb = sb + 1;
    ll Min = 0;
    if (sbb % 2) {
        Min += yu * (sbb - 1) / 2 * sbb;
    } else Min += yu * sbb / 2 * (sbb - 1);
    if (sb % 2) {
        Min += (m - yu) * (sb - 1) / 2 * sb;
    } else Min += (m - yu) * sb / 2 * (sb - 1);
    printf("%lld %lld\n", Min, Max);
    return 0;
}