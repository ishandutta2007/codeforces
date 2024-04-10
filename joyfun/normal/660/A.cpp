#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1005;
int a[N], ans[N], an = 0;
int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    return a;
}

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ans[an++] = a[1];
    for (int i = 2; i <= n; i++) {
        if (gcd(a[i], a[i - 1]) != 1) ans[an++] = 1;
        ans[an++] = a[i];
    }
    printf("%d\n", an - n);
    for (int i = 0; i < an; i++) printf("%d ", ans[i]);
    return 0;
}