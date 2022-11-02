#include <stdio.h>

int main()
{
    int n, k, x = -1, y = -1, i, j;
    int p[100];
    int q[100];
    int s[100];
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &q[i]);
    for (i = 0; i < n; i++) scanf("%d", &s[i]);
    
    for (i = 0; i < n; i++) {
        p[i] = i;
        
        q[i]--;
        s[i]--;
    }
    
    for (i = 0; i < n; i++) {
        if (p[i] != s[i]) break;
    }
    
    if (i == n) {
        puts("NO");
        
        return 0;
    }
    
    for (i = 0; i < k; i++) {
        int r[100];
        
        for (j = 0; j < n; j++) r[j] = p[q[j]];
        
        for (j = 0; j < n; j++) p[j] = r[j];
        
        for (j = 0; j < n; j++) {
            if (p[j] != s[j]) break;
        }
        
        if (j == n) {
            x = i + 1;
            
            break;
        }
    }
    
    for (i = 0; i < n; i++) p[i] = i;
    
    for (i = 0; i < k; i++) {
        int r[100];
        
        for (j = 0; j < n; j++) r[q[j]] = p[j];
        
        for (j = 0; j < n; j++) p[j] = r[j];
        
        for (j = 0; j < n; j++) {
            if (p[j] != s[j]) break;
        }
        
        if (j == n) {
            y = i + 1;
            
            break;
        }
    }
    
    if (x != -1 && x % 2 == k % 2) {
        if (x > 1 || y == -1 || y > 1 || k == 1) {
            puts("YES");
            
            return 0;
        }
    }
    
    if (y != -1 && y % 2 == k % 2) {
        if (y > 1 || x == -1 || x > 1 || k == 1) {
            puts("YES");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}