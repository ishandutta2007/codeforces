#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, a[N];
bool used[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    std::sort(a, a + n);
    used[0] = true;
    for (int i = 0; i < n; i++) {
        if (!used[a[i] - 1]) {
            used[a[i] - 1] = true; a[i]--;
        } else if (!used[a[i]]) {
            used[a[i]] = true;
        } else if (!used[a[i] + 1]) {
            used[a[i] + 1] = true; a[i]++;
        }
    }
    std::sort(a, a + n);
    printf("%d\n", std::unique(a, a + n) - a);
    return 0;
}