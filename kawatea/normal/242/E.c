#include <stdio.h>

int a[100000];
int b[20][250][400];
int c[20][250];
int d[20][250];

int main()
{
    int n, m, i, j, k, l;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < 20; i++) {
        for (j = 0; j < n; j++) {
            if (a[j] % 2 == 1) {
                b[i][j / 400][j % 400] = 1;
                c[i][j / 400]++;
            }
            
            a[j] /= 2;
        }
    }
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x, y;
            long long sum = 0;
            
            scanf("%d %d", &x, &y);
            
            x--;
            y--;
            
            for (j = 0; j < 20; j++) {
                for (k = x / 400; k <= y / 400; k++) {
                    int p = 0, q = 400;
                    
                    if (k == x / 400) p = x % 400;
                    if (k == y / 400) q = y % 400 + 1;
                    
                    if (p == 0 && q == 400) {
                        if (d[j][k]) {
                            sum += (1 << j) * (400 - c[j][k]);
                        } else {
                            sum += (1 << j) * c[j][k];
                        }
                    } else {
                        for (l = p; l < q; l++) {
                            if (d[j][k] ^ b[j][k][l]) sum += (1 << j);
                        }
                    }
                }
            }
            
            printf("%I64d\n", sum);
        } else {
            int x, y, z;
            
            scanf("%d %d %d", &x, &y, &z);
            
            x--;
            y--;
            
            for (j = 0; j < 20; j++, z /= 2) {
                if (z % 2 == 0) continue;
                
                for (k = x / 400; k <= y / 400; k++) {
                    int p = 0, q = 400;
                    
                    if (k == x / 400) p = x % 400;
                    if (k == y / 400) q = y % 400 + 1;
                    
                    if (p == 0 && q == 400) {
                        d[j][k] = 1 - d[j][k];
                    } else {
                        for (l = p; l < q; l++) {
                            if (b[j][k][l]) {
                                c[j][k]--;
                                b[j][k][l] = 0;
                            } else {
                                c[j][k]++;
                                b[j][k][l] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}