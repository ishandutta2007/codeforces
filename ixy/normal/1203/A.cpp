#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 205;

int n, a[N];

bool check1() {
    for (int i = 1; i < n; i++) {
        if ((a[0] + 0) % n != (a[i] + i) % n) { return false; }
    }
    return true;
}
bool check2() {
    for (int i = 1; i < n; i++) {
        if ((a[0] + n - 0) % n != (a[i] + n - i) % n) { return false; }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) { a[i] = read(); }
        printf("%s\n", check1() || check2() ? "YES" : "NO");
    }
    return 0;
}