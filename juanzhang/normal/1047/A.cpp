#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    putchar(49), putchar(32);
    if (n % 3 == 0 || n % 3 == 1) {
        printf("%d %d", 1, n - 2);
    } else {
        printf("%d %d", 2, n - 3);
    }
    return 0;
}