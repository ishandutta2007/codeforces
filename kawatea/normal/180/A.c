#include <stdio.h>

int main()
{
    int n, m, c = 0, q = 0, i, j, k;
    int a[200][200], b[200];
    int p[200] = {0};
    int x[400][2];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        
        for (j = 0; j < b[i]; j++) {
            scanf("%d", &a[i][j]);
            
            p[a[i][j] - 1] = ++c;
        }
    }
    
    for (i = 0; i < c; i++) {
        if (p[i] == i + 1) continue;
        
        for (j = i + 1; j < n; j++) {
            if (p[j] == i + 1) break;
        }
        
        for (k = i; k < n; k++) {
            if (p[k] == 0) break;
        }
        
        if (k == i) {
            x[q][0] = j + 1;
            x[q++][1] = i + 1;
            
            p[j] = 0;
            p[i] = i + 1;
        } else {
            x[q][0] = i + 1;
            x[q++][1] = k + 1;
            x[q][0] = j + 1;
            x[q++][1] = i + 1;
            
            p[j] = 0;
            p[k] = p[i];
            p[i] = i + 1;
        }
    }
    
    printf("%d\n", q);
    
    for (i = 0; i < q; i++) printf("%d %d\n", x[i][0], x[i][1]);
    
    return 0;
}