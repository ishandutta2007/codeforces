#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 510;

int n, m, a[N][N];
int c0, c1[N], c2[N];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    int x, fl = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            scanf("%d", &x);
            a[i][j] ^= x;
            if(i == 1 || j == 1) continue ;
            c0 ^= a[i][j];
            c1[i] ^= a[i][j];
            c2[j] ^= a[i][j];
        }
    if(a[1][1] != c0) fl = 0;
    for(int i = 2; i <= n; i ++)
        if(a[i][1] != c1[i]) fl = 0;
    for(int i = 2; i <= m; i ++)
        if(a[1][i] != c2[i]) fl = 0;
    puts(fl ? "Yes" : "No");
    return 0;
}