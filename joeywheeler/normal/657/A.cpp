#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, d, h; scanf("%d%d%d", &n, &d, &h);
    if (d <= 2*h) {
        if (h == 1 && d == 1 && n != 2) {
            printf("-1\n");
        } else {
            for (int i = 1; i <= h; i++) {
                printf("%d %d\n", i, i+1);
            }
            for (int i = h+1; i <= d; i++) {
                printf("%d %d\n", i == h+1 ? 1 : i, i+1);
            }
            for (int i = d+2; i <= n; i++) printf("%d %d\n", h, i);
        }
    } else {
        printf("-1\n");
    }
}