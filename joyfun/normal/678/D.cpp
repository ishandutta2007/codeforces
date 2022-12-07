#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int A, B, x;
long long n;

int pow_mod(int x, long long k) {
    int ans = 1;
    while (k) {
        if (k&1)ans = 1LL* ans * x%MOD;
        x = 1LL * x * x % MOD;
        k>>=1;
    }
    return ans;
}

int get(int A, long long n) {
    if (A == 1) return n % MOD;
    int zi = (1 - pow_mod(A, n) + MOD) % MOD;
    int mu = pow_mod((1 - A + MOD) % MOD, MOD - 2);
    return 1LL * zi * mu % MOD;
}

int main() {
    scanf("%d%d%lld%d", &A, &B, &n, &x);
    printf("%d\n", (1LL * pow_mod(A, n) * x % MOD + 1LL * B * get(A, n) % MOD) % MOD);
    return 0;
}