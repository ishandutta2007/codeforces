#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d %d", &n, &m);
    
    fclose(fp);
    
    fp = fopen("output.txt", "w");
    
    if (n > m) {
        for (i = 0; i < m; i++) fprintf(fp, "BG");
        
        for (i = 0; i < n - m; i++) fprintf(fp, "B");
        
        fprintf(fp, "\n");
    } else {
        for (i = 0; i < n; i++) fprintf(fp, "GB");
        
        for (i = 0; i < m - n; i++) fprintf(fp, "G");
        
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    
    return 0;
}