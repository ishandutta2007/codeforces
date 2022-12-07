#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

int n, q;
int ans[N], cao[N];

int main() {
    scanf("%d%d", &n, &q);
    int tp, x;
    int tot = 0;
    int sb = 0;
    int f = 0;
    while (q--) {
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d", &x);
            tot = ((tot + x) % n + n) % n;
            if (x % 2) f ^= 1;
        } else {
            if (f) {
                f ^= 1;
                sb++;
                tot = (tot - 1 + n) % n;
            }
            else {
                f ^= 1;
                sb--;
                tot = (tot + 1) % n;
            }
        }
    }
    sb = (sb % (n / 2) + n / 2) % (n / 2);
    for (int i = 1; i <= n; i++) ans[i] = cao[i] = i;
    for (int i = 2; i <= n; i += 2) {
        int v = (i - sb * 2);
        if (v <= 0) v += n;
        ans[i] = cao[v];
    }
    //for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
    for (int i = 1; i <= n; i++) cao[i] = ans[i];
    for (int i = 1; i <= n; i++) {
        int v = i - tot;
        if (v <= 0) v += n;
        printf("%d ", cao[v]);
    }
    printf("\n");
    return 0;
}