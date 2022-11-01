#include <cstdio>
#include <algorithm>
using namespace std;

char *findr(char *p, char *p2, char x) {
    for (char *p3 = p2; p3 != p;)
        if (*--p3 == x)
            return p3;
    return p2;
}

int p[300000];
char c[300000];

int solve(int n) {
    int g1 = find(c, c + n, 'G') - c;
    int g2 = findr(c, c + n, 'G') - c;
    int r1 = find(c, c + n, 'R') - c;
    int r2 = findr(c, c + n, 'R') - c;
    int b1 = find(c, c + n, 'B') - c;
    int b2 = findr(c, c + n, 'B') - c;
    if (g1 == n) {
        int ans = 0;
        if (r1 < r2)
            ans += p[r2] - p[r1];
        if (b1 < b2)
            ans += p[b2] - p[b1];
        return ans;
    }
    int ans = 0;
    if (r1 < g1)
        ans += p[g1] - p[r1];
    if (b1 < g1)
        ans += p[g1] - p[b1];
    if (r2 < n && g2 < r2)
        ans += p[r2] - p[g2];
    if (b2 < n && g2 < b2)
        ans += p[b2] - p[g2];
    while (g1 < g2) {
        int ng2 = find(c + g1 + 1, c + g2, 'G') - c;
        int x = p[ng2] - p[g1];
        int mr = 0, mb = 0, r3 = g1, b3 = g1;
        while (r3 < ng2) {
            int nr3 = find(c + r3 + 1, c + ng2, 'R') - c;
            mr = max(mr, p[nr3] - p[r3]);
            r3 = nr3;
        }
        while (b3 < ng2) {
            int nb3 = find(c + b3 + 1, c + ng2, 'B') - c;
            mb = max(mb, p[nb3] - p[b3]);
            b3 = nb3;
        }
        // fprintf(stderr, "x = %d, mr = %d, mb = %d\n", x, mr, mb);
        ans += x + min(x, 2 * x - (mr + mb));
        g1 = ng2;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[2];
        scanf("%d %1s", p + i, s);
        c[i] = s[0];
    }

    printf("%d\n", solve(n));
}