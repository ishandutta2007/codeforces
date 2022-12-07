#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, num[105], i;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int t = num[0];
    for (i = 1; i < n; i++) {
        t = gcd(t, num[i]);
    }
    printf("%d\n", t * n);
    return 0;
}