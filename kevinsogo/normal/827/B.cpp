#include <bits/stdc++.h>
using namespace std;

int f(int k, int l) {
    if (l % 2 == 0) {
        return 1 + (l / 2 - 1) * k;
    } else {
        return 2 + (l / 2 - 1) * k;
    }
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int l = 2;
    while (f(k, l) < n - k) l++;
    printf("%d\n", l);
    if (l % 2 == 0) {
        for (int i = 1; i < n; i++) {
            printf("%d %d\n", i, min(n, i + k));
        }
    } else {
        for (int i = 1; i < n - 1; i++) {
            printf("%d %d\n", i, i == n - 2 ? n : min(n - 1, i + k));
        }
        printf("%d %d\n", n - 1, n);
    }
}