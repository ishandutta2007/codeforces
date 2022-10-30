// Hydro submission #63036b686addf33406e45276@1661168488367
#include <cstdio>
using namespace std;
int n, m;
char f, last = ' ';
int main() {
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; i++) {
        f = getchar();
        while (f < '0' || f > '9') f = getchar();
        for (register int j = 2; j <= m; j++) {
            char t = getchar();
            if (t != f) {
                printf("NO");
                return 0;
            }
        }
        if (last == f) {
            printf("NO");
            return 0;
        }
        last = f;
    }
    printf("YES");
    return 0;
}