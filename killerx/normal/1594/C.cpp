#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    int n;
    char target;
    static char s[300005];
    scanf("%d %c", &n, &target);
    scanf("%s", s);
    int cnt = 0;
    rep(i, n) if (s[i] != target) ++ cnt;
    if (cnt == 0) puts("0");
    else if (s[n - 1] == target) printf("1\n%d\n", n);
    else {
        static bool ban[300005];
        for (int i = 1; i <= n; ++ i) ban[i] = false;
        rep(i, n) if (s[i] != target) {
            for (int x = 1; x * x <= i + 1; ++ x) if ((i + 1) % x == 0) {
                ban[x] = ban[(i + 1) / x] = true;
            }
        }
        bool ok = false;
        int x = -1;
        for (int i = 1; i <= n; ++ i) {
            if (!ban[i]) {
                x = i;
                ok = true;
            }
        }
        if (ok) printf("1\n%d\n", x);
        else printf("2\n%d %d\n", n, n - 1);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}