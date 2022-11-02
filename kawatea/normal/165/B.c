#include <stdio.h>

int n, k;

int ok(int x)
{
    int sum = 0;
    
    while (x) {
        sum += x;
        x /= k;
    }
    
    if (sum >= n) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int l, r, m;
    
    scanf("%d %d", &n, &k);
    
    l = 0, r = n + 1, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (ok(m)) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}