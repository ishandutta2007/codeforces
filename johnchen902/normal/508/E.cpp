#include <cstdio>
using namespace std;

int l[600], r[600];
int ok[601][601];

void go(int i, int j) {
    if(i != j) {
        putchar('(');
        go(i + 1, ok[i][j]);
        putchar(')');
        go(ok[i][j], j);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", l + i, r + i);
    for(int i = 0; i <= n; i++)
        ok[i][i] = 1;
    for(int d = 1; d <= n; d++) {
        for(int i = 0, j = i + d; j <= n; i++, j++) {
            for(int k = i + 1; k <= j; k++) {
                int dis = (k - (i + 1)) * 2 + 1;
                if(l[i] <= dis && dis <= r[i] && ok[i + 1][k] && ok[k][j]) {
                    ok[i][j] = k;
                    break;
                }
            }
        }
    }
    if(ok[0][n]) {
        go(0, n);
        putchar('\n');
    } else {
        puts("IMPOSSIBLE");
    }
}