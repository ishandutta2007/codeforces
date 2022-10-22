#include <bits/stdc++.h>

using namespace std;

typedef long long big;

big calc(big n) {
    big a = n / 3, b = (n - a) / 2, c = n - a - b;
    return (a * b + a * c + b * c) * 2;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        big n;
        scanf("%lld", &n);
        big a = 1, b = 1000000;
        while (a < b) {
            big mid = (a + b) >> 1;
            if (calc(mid) >= n)
                b = mid;
            else
                a = mid + 1;
        }
        printf("%lld\n", a);
    }
    return 0;
}