#include <cstdio>
#include <map>

std::map<int, int> m;

int main() {
    int N, mod, K;
    scanf("%d%d%d", &N, &mod, &K);
    long long wyn = 0;
    for (int i = 1; i <= N; i++) {
        long long a;
        scanf("%lld", &a);
        long long h = a * a;
        h %= mod;
        h *= h;
        h %= mod;
        h -= K * a;
        h %= mod;
        h += mod;
        h %= mod;
        wyn += m[h]++;
    }
    printf("%lld", wyn);
    return 0;
}