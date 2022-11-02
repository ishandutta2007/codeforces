#include <stdio.h>

int a[50000];

int lower_bound(int a[], int n, int x)
{
    int l = -1, r = n, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (a[m] >= x) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    return r;
}

int upper_bound(int a[], int n, int x)
{
    int l = -1, r = n, m = (l + r) / 2;
    
    while (r - l > 1) {
        if (a[m] > x) {
            r = m;
            m = (l + r) / 2;
        } else {
            l = m;
            m = (l + r) / 2;
        }
    }
    
    return r;
}

int main()
{
    int n, i, j;
    
    for (i = 0; i < 50000; i++) a[i] = (long long)(i + 1) * (i + 2) / 2;
    
    scanf("%d", &n);
    
    for (i = 0; i < 50000; i++) {
        int x = n - a[i];
        
        if (x < 0) break;
        
        if (upper_bound(a, 50000, x) - lower_bound(a, 50000, x) > 0) {
            puts("YES");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}