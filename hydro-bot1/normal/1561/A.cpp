// Hydro submission #62596cb037de167dd82c2463@1650027697351
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define N 1010

int a[N];

void f(int i) {
    if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
}

int main() {
    for (int T = read(); T --;) {
        int n = read();
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
        }
        int flag = true;
        for (int i = 2; i <= n; i ++) {
            if (a[i] < a[i - 1]) flag = false;
        }
        if (flag) {
            puts("0");
            continue;
        }
        int i;
        for (i = 1; i <= n; i ++) {
            if (i & 1) {
                for (int j = 1; j < n - 1; j += 2) {
                    f(j);
                }
            } else {
                for (int j = 2; j < n; j += 2) {
                    f(j);
                }
            }
            int flag = true;
            for (int i = 2; i <= n; i ++) {
                if (a[i] < a[i - 1]) flag = false;
            }
            if (flag) break;
        }
        printf("%d\n", i);
    }
    return 0;
}