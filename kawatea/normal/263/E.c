#include <stdio.h>

long long sum[1001][1001];
int a[1000][1000];
long long b[1000][1000];

int abs(int x)
{
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

long long get(int x1, int y1, int x2, int y2)
{
    return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
}

int main()
{
    int n, m, k, p, q, i, j, l;
    long long ans = -1;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (abs(i - k + 1) + abs(j - k + 1) < k) {
                b[0][0] += (long long)a[i][j] * (k - abs(i - k + 1) - abs(j - k + 1));
            }
        }
    }
    
    for (i = 0; i + k - 1 < n - k + 1; i++) {
        for (j = 0; j + k - 1 < m - k + 1; j++) {
            if (i == 0 && j == 0) continue;
            
            if (i == 0) {
                b[i][j] = b[i][j - 1];
                
                for (l = 0; l < k; l++) {
                    b[i][j] += get(i + k - 1 - k + l + 1, j + k - 1 + l, i + k - 1 + k - l - 1, j + k - 1 + l);
                    b[i][j] -= get(i + k - 1 - k + l + 1, j + k - 1 - l - 1, i + k - 1 + k - l - 1, j + k - 1 - l - 1);
                }
            } else {
                b[i][j] = b[i - 1][j];
                
                for (l = 0; l < k; l++) {
                    b[i][j] += get(i + k - 1 + l, j + k - 1 - k + l + 1, i + k - 1 + l, j + k - 1 + k - l - 1);
                    b[i][j] -= get(i + k - 1 - l - 1, j + k - 1 - k + l + 1, i + k - 1 - l - 1, j + k - 1 + k - l - 1);
                }
            }
        }
    }
    
    for (i = 0; i + k - 1 < n - k + 1; i++) {
        for (j = 0; j + k - 1 < m - k + 1; j++) {
            if (b[i][j] > ans) {
                ans = b[i][j];
                p = i;
                q = j;
            }
        }
    }
    
    printf("%d %d\n", p + k, q + k);
    
    return 0;
}