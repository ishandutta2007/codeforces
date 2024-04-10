#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int vis[2000005];
int n, a[N], g[N][N];

int main() {
    vis[1] = 1;
    for (int i = 2; i <= 2000000; i++) {
        if (1LL * i * i > 2000000LL) continue;
        for (int j = i * i; j <= 2000000; j += i)
            vis[j] = 1;
    }
    scanf("%d", &n);
    int one = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) one++;
    }

    int aa = 0, bb = 0, ans = 0, cc = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!vis[a[i] + a[j]]) {
                if (!vis[a[i] + 1] && !vis[a[j] + 1]) {
                    int oo = one;
                    if (a[i] == 1) oo--;
                    if (a[j] == 1) oo--;
                    if (ans < 2 + oo) {
                        ans = 2 + oo;
                        aa = i;
                        bb = j;
                        cc = oo;
                    }
                } else {
                    if (ans < 2) {
                        ans = 2;
                        aa = i;
                        bb = j;
                        cc = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!vis[a[i] + 1]) {
            int oo = one;
            if (a[i] == 1) oo--;
            if (ans < 1 + oo) {
                ans = 1 + oo;
                aa = i;
                bb = 0;
                cc = oo;
            }
        } else {
            if (ans < 1) {
                ans = 1;
                aa = i;
                bb = 0;
                cc = 0;
            }
        }
    }
    printf("%d\n", ans);
    if (aa && bb) {
        printf("%d %d", a[aa], a[bb]);
        for (int i = 0; i < cc ; i++) printf(" 1");
    } else if (aa) {
        printf("%d", a[aa]);
        for (int i = 0; i < cc ; i++) printf(" 1");
        printf("\n");
    }
    return 0;
}