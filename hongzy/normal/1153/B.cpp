#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, m, h;
int b[N], a[N], c[N][N], ans[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= m; i ++)
        scanf("%d", b + i);
    for(int i = 1; i <= n; i ++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d", &c[i][j]);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(c[i][j]) {
                ans[i][j] = min(a[i], b[j]);
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}