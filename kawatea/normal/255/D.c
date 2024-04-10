#include <stdio.h>

long long min(long long a, long long b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, x, y, c;
    long long l, r, m;
    
    scanf("%d %d %d %d", &n, &x, &y, &c);
    
    x--;
    y--;
    
    l = -1;
    r = n * 2;
    m = (l + r) / 2;
    
    while (r - l > 1) {
        long long sum = m * m * 2 + m * 2 + 1;
        
        if (x < m) sum -= (m - x) * (m - x);
        if (y < m) sum -= (m - y) * (m - y);
        if (n - x - 1 < m) sum -= (m - n + x + 1) * (m - n + x + 1);
        if (n - y - 1 < m) sum -= (m - n + y + 1) * (m - n + y + 1);
        
        if (m - x - y - 1 > 0) {
            long long z = m - x - y - 1;
            
            sum += z * (z + 1) / 2;
        }
        
        if (m - x - n + y > 0) {
            long long z = m - x - n + y;
            
            sum += z * (z + 1) / 2;
        }
        
        if (m - y - n + x > 0) {
            long long z = m - y - n + x;
            
            sum += z * (z + 1) / 2;
        }
        
        if (m + x + y - n * 2 + 1 > 0) {
            long long z = m + x + y - n * 2 + 1;
            
            sum += z * (z + 1) / 2;
        }
        
        if (sum >= c) {
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