#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;
long long a[N];

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

bool judge() {
   long long tmp = 0;
   for (int i = 0; i < n; i++) {
        tmp = gcd(tmp, a[i]);
   }
   for (int i = 0; i < n; i++) {
        long long sb = a[i] / tmp;
        while (sb % 2 == 0) sb /= 2;
        while (sb % 3 == 0) sb /= 3;
        if (sb != 1) return false;
   }
   return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    printf("%s\n", judge() ? "Yes" : "No");

    return 0;
}