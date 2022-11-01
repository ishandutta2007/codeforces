// write in C...
#include <stdio.h>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

int adj[1005][1005];

int main() {
    int i, j, n;
    scanf("%d", &n);
    if (n == 2 || n == 4) printf("-1");
    else {
        for (i = 1; i+1 < n; i += 2) {
            // add node i and i+1
            adj[i][i+1] = 1;
            for (j = 0; j < i; j++) adj[j][i] = adj[i+1][j] = 1;
        }
        if (~n&1) {
            adj[n-1][0] = 1;
            adj[1][n-1] = 1;
            adj[n-1][n-2] = 1;
            adj[n-3][n-1] = 1;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j && !adj[i][j] && !adj[j][i]) {
                    adj[i][j] = 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf("%d ", adj[i][j]);
            printf("\n");
        }
    }
    return 0;
}