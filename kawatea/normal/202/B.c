#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_perm(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int next_permutation(int a[], int n)
{
    int m = a[n - 1], p = 1, i, j;
    int b[20];
    
    b[0] = m;
    
    for (i = n - 2; i >= 0; i--) {
        if (m > a[i]) {
            qsort(b, p, sizeof(int), cmp_perm);
            
            for (j = 0; ; j++) {
                if (b[j] > a[i]) {
                    m = a[i];
                    a[i++] = b[j];
                    b[j] = m;
                    
                    break;
                }
            }
            
            for (p = 0; i < n; i++) {
                a[i] = b[p++];
            }
            
            return 1;
        } else {
            b[p++] = a[i];
            
            if (a[i] > m) m = a[i];
        }
    }
    
    return 0;
}

int main()
{
    int n, m, p = -1, q = -1, i, j, l;
    int k[10];
    char s1[4][11];
    char s2[10][20][11];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%s", s1[i]);
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d", &k[i]);
        
        for (j = 0; j < k[i]; j++) scanf("%s", s2[i][j]);
    }
    
    for (i = 0; i < m; i++) {
        int a[4] = {0, 1, 2, 3};
        
        do {
            int x = 0;
            
            for (j = 0; j < k[i] && x < n; j++) {
                if (strcmp(s1[a[x]], s2[i][j]) == 0) x++;
            }
            
            if (x < n) continue;
            
            x = 0;
            
            for (j = 0; j < n; j++) {
                for (l = j + 1; l < n; l++) {
                    if (a[j] > a[l]) x++;
                }
            }
            
            if (n * (n - 1) / 2 - x + 1 > q) {
                p = i + 1;
                q = n * (n - 1) / 2 - x + 1;
            }
        } while (next_permutation(a, n));
    }
        
    if (p == -1) {
        puts("Brand new problem!");
    } else {
        printf("%d\n", p);
        
        printf("[:");
        for (i = 0; i < q; i++) putchar('|');
        printf(":]\n");
    }
    
    return 0;
}