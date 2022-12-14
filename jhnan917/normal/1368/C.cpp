#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", 3 * n + 4);
    for (int i = 1; i <= 2; i++) for (int j = 1; j <= 2; j++) printf("%d %d\n", i, j);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i + 2, i + 1);
        printf("%d %d\n", i + 1, i + 2);
        printf("%d %d\n", i + 2, i + 2);
    }
}