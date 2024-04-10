#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

long long n;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%lld", &n);
    int d = gcd(123456, 1234);
    //printf("%d\n", d);
    int f = 0;
    for (int i = 0; 1234567LL * i <= n; i++) {
        long long yu = n - 1234567LL * i;
        for (int j = 0; 123456LL * j <= yu; j++) {
            long long c = yu - 123456LL * j;
            if (c % 1234 == 0) {
                f = 1;
                break;
            }
        }
        if (f) break;
    }
    printf("%s\n", f ? "YES" : "NO");
    return 0;
}