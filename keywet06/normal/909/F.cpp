#include <bits/stdc++.h>

void Do2(int n) {
    int i, p = 1;
    while (p * 2 <= n) p *= 2;
    if (p == n) return void(printf("NO\n"));
    if (n <= 5) return void(printf("NO\n"));
    if (n == 6) {
        printf("YES\n");
        printf("3 6 2 5 1 4\n");
    } else {
        printf("YES\n");
        printf("3 6 2 5 1 7 4 ");
        p = 8;
        while (p <= n) {
            int i;
            std::vector<int> Vec;
            for (i = p; i <= std::min(2 * p - 1, n); ++i) Vec.push_back(i);
            for (i = 0; i < Vec.size(); ++i) printf("%d ", Vec[(i + 1) % Vec.size()]);
            p *= 2;
        }
    }
}

void Do(int n) {
    if (!n) return;
    if (n == 2) return void(printf("2 1 "));
    int po = 1;
    while (po * 2 <= n) po *= 2;
    int i;
    Do(2 * po - 2 - n);
    for (i = 2 * po - 1 - n; i <= n; ++i) printf("%d ", po * 2 - 1 - i);
}

void Do1(int n) {
    if (n % 2 == 1) return void(printf("NO"));
    printf("YES\n"), Do(n);
}

int main() {
    int n;
    scanf("%d", &n);
    Do1(n), puts(""), Do2(n);
    return 0;
}