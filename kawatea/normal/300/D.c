#include <stdio.h>

long long a[30][1001];
long long b[5][1001];

int main()
{
    int q, m = 7340033, i, j, l, r;
    
    a[0][0] = 1;
    
    for (i = 1; i < 30; i++) {
        for (j = 0; j < 5; j++) {
            for (l = 0; l <= 1000; l++) {
                b[j][l] = 0;
            }
        }
        
        b[0][0] = 1;
        
        for (j = 0; j < 4; j++) {
            for (l = 0; l <= 1000; l++) {
                for (r = 0; l + r <= 1000; r++) {
                    b[j + 1][l + r] = (b[j + 1][l + r] + b[j][l] * a[i - 1][r] % m) % m;
                }
            }
        }
        
        a[i][0] = 1;
        
        for (j = 1; j <= 1000; j++) a[i][j] = b[4][j - 1];
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int n, k, c = 0;
        
        scanf("%d %d", &n, &k);
        
        while (n > 1) {
            if (n % 2 == 0) break;
            
            n /= 2;
            c++;
        }
        
        printf("%d\n", (int)a[c][k]);
    }
    
    return 0;
}