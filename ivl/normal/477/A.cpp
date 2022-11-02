#include <cstdio>

using namespace std;

long long a, b;

int main(){
    scanf("%I64d%I64d", &a, &b);
    long long r1 = b * (b - 1);
    r1 /= 2;
    r1 %= 1000000007;
    long long r2 = a * (a + 1);
    r2 /= 2;
    r2 %= 1000000007;
    r2 *= b;
    r2 += a;
    r2 %= 1000000007;
    long long r = r1 * r2;
    r %= 1000000007;
    printf("%d\n", (int)r);
    return 0;
}