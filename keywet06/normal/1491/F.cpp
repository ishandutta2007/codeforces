#include <bits/stdc++.h>
int n;
std::vector<int> ans, tmp, hlf;
int main() {
    int T;
    scanf("%d", &T);
    for (; T--;) {
        ans.clear(), tmp.clear(), hlf.clear();
        scanf("%d", &n);
        register int i, ii;
        int sec = 0;
        for (i = 2; i <= n; i++) {
            printf("? 1 %d\n%d\n", i - 1, i);
            for (ii = 1; ii < i; ii++) printf("%d ", ii);
            puts(""), fflush(stdout);
            int f;
            scanf("%d", &f);
            if (f) {
                sec = i;
                break;
            }
        }
        for (i = sec + 1; i <= n; i++) {
            printf("? 1 1\n%d\n%d\n", sec, i);
            fflush(stdout);
            int f;
            scanf("%d", &f);
            if (!f) ans.push_back(i);
        }
        for (i = 1; i < sec; i++) tmp.push_back(i);
        while (tmp.size() > 1) {
            int md = tmp.size() >> 1;
            hlf.clear();
            for (i = 1; i <= md; i++) hlf.push_back(tmp.back()), tmp.pop_back();
            printf("? 1 %d\n%d\n", md, sec);
            for (int t : hlf) printf("%d ", t);
            puts(""), fflush(stdout);
            int f;
            scanf("%d", &f);
            if (f) tmp = hlf;
        }
        for (i = 1; i < sec; i++)
            if (tmp[0] != i) ans.push_back(i);
        printf("! %u", ans.size());
        for (int t : ans) printf(" %d", t);
        puts(""), fflush(stdout);
    }
}