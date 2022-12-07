#include <stdio.h>
#include <string.h>

const int N = 105;
int n, m, g[N][N];

bool judge(int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != g[n - i - 1][j])
                return false;
        }
    }
    return true;
}

int solve(int n) {
    if (n % 2) return n;
    if (!judge(n)) return n;
    return solve(n / 2);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &g[i][j]);
    printf("%d\n", solve(n));
    return 0;
}