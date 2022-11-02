#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int f(int m, int d)
{
    int x = 0, i;
    
    for (i = 0; i < m - 1; i++) x += a[i];
    
    x += d - 1;
    
    return x;
}

int main()
{
    int n, ans = 0, i, j;
    int b[465] = {0};
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y, z, w, p;
        
        fscanf(fp, "%d %d %d %d", &x, &y, &z, &w);
        
        p = f(x, y) + 100;
        
        for (j = p - w; j < p; j++) b[j] += z;
    }
    
    fclose(fp);
    
    for (i = 0; i < 465; i++) ans = max(ans, b[i]);
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "%d\n", ans);
    
    fclose(fp);
    
    return 0;
}