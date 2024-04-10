#include <bits/stdc++.h>
using namespace std;

int n, p, a[3];

int main() {
    scanf("%d %d", &n, &p);
    n %= 6, a[1] = 1, a[2] = 2;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            swap(a[0], a[1]);
        } else {
            swap(a[1], a[2]);
        }
    }
    putchar(a[p] | 48);
    return 0;
}