#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, ans = 1e9, i;
    int a[5001] = {0};
    int sum[5001] = {0};
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        fscanf(fp, "%d", &x);
        
        a[x]++;
    }
    
    fclose(fp);
    
    for (i = 1; i <= 5000; i++) sum[i] = sum[i - 1] + a[i];
    
    for (i = 1; i <= 5000; i++) {
        if (i * 2 > 5000) {
            ans = minimum(ans, sum[i - 1]);
        } else {
            ans = minimum(ans, sum[i - 1] + sum[5000] - sum[i * 2]);
        }
    }
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "%d\n", ans);
        
    fclose(fp);
    
    return 0;
}