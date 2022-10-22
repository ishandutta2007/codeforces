#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
    int n;
    scanf("%d", &n);
    std::vector <int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) {
        bool ok = false;
        for (int j = i + 1; j >= 1; -- j) {
            if (a[i] % (j + 1) != 0) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            puts("NO");
            return ;
        }
    }
    puts("YES");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}