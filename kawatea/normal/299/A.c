#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    
    return gcd(b, a % b);
}

int main()
{
    int n, g, i;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        if (i == 0) {
            g = a[i];
        } else {
            g = gcd(g, a[i]);
        }
    }
    
    for (i = 0; i < n; i++) {
        if (g % a[i] == 0) {
            printf("%d\n", a[i]);
            
            return 0;
        }
    }
    
    puts("-1");
    
    return 0;
}