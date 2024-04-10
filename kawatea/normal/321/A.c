#include <stdio.h>
#include <string.h>

long long absl(long long x)
{
    if (x < 0) return -x;
    
    return x;
}

long long dist(long long x1, long long y1, long long x2, long long y2)
{
    return absl(x1 - x2) + absl(y1 - y2);
}

int main()
{
    int a, b, n, x = 100, y = 100, x1 = 100, y1 = 100, x2 = 100, y2 = 100, i;
    long long l, r, m1, m2;
    int d[201][201] = {0};
    char s[101];
    
    scanf("%d %d", &a, &b);
    scanf("%s", s);
    
    n = strlen(s);
    
    d[x][y] = 1;
    
    for (i = 0; i < n; i++) {
        if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        } else if (s[i] == 'L') {
            x--;
        } else {
            x++;
        }
        
        if (x > x1) x1 = x;
        if (y > y1) y1 = y;
        if (x < x2) x2 = x;
        if (y < y2) y2 = y;
        
        d[x][y] = 1;
    }
    
    x -= 100;
    y -= 100;
    x1 -= 100;
    y1 -= 100;
    x2 -= 100;
    y2 -= 100;
    
    l = 0, r = 1e9;
    
    while (r - l > 1) {
        long long z1, z2;
        
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        
        if (m1 >= m2 || m1 <= l || m1 >= r || m2 <= l || m2 >= r) break;
        
        z1 = dist(m1 * x, m1 * y, a, b);
        z2 = dist(m2 * x, m2 * y, a, b);
        
        if (z1 > z2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    
    for (i = l - 200; i <= l + 200; i++) {
        long long p, q;
        
        if (i < 0) continue;
        
        p = a - i * x;
        q = b - i * y;
        
        if (absl(p) > 100 || absl(q) > 100) continue;
        
        if (d[p + 100][q + 100] == 1) {
            puts("Yes");
            
            return 0;
        }
    }
    
    puts("No");
    
    return 0;
}