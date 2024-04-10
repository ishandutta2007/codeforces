#include <stdio.h>

long long sum = 0;
int a[1000001];

void dfs(int x)
{
    int y, c = 0, i;
    
    if (x <= 0) return;
    
    y = x;
    
    while (y) {
        y /= 2;
        c++;
    }
    
    y = 1 << (c - 1);
    
    for (i = 0; y + i <= x; i++) {
        a[y + i] = y - i - 1;
        a[y - i - 1] = y + i;
        
        sum += ((y + i) ^ (y - i - 1)) * 2;
    }
    
    dfs(x - (x - y + 1) * 2);
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    dfs(n);
    
    printf("%I64d\n", sum);
    
    for (i = 0; i <= n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}