#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}
inline char readChar() {
    char c; for (c = getchar(); !isalpha(c); c = getchar()); return c;
}

const int N = 1e2 + 5;

int n, m;
char c[N][N];

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'A') { return false; }
        }
    }
    return true;
}

bool check0() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'P') { return false; }
        }
    }
    return true;
}

bool check4() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (c[i][j] == 'A') { return false; }
            }
        }
    }
    return true;
}

bool check1() {
    bool flag1, flag2, flag3, flag4;
    flag1 = flag2 = flag3 = flag4 = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && c[i][j] == 'P') { flag1 = false; }
            if (j == 0 && c[i][j] == 'P') { flag2 = false; }
            if (i == n - 1 && c[i][j] == 'P') { flag3 = false; }
            if (j == m - 1 && c[i][j] == 'P') { flag4 = false; }
        }
    }
    return flag1 || flag2 || flag3 || flag4;
}

bool check2() {
    if (c[0][0] == 'A') { return true; }
    if (c[0][m - 1] == 'A') { return true; }
    if (c[n - 1][0] == 'A') { return true; }
    if (c[n - 1][m - 1] == 'A') { return true; }
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'P') { flag = false; }
        }
        if (flag) { return true; }
    }
    for (int j = 0; j < m; j++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (c[i][j] == 'P') { flag = false; }
        }
        if (flag) { return true; }
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i][j] = readChar();
            }
        }
        if (check()) {
            printf("MORTAL\n");
        } else if (check4()) {
            printf("4\n");
        } else if (check0()) {
            printf("0\n");
        } else if (check1()) {
            printf("1\n");
        } else if (check2()) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
    return 0;
}