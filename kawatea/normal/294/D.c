#include <stdio.h>

int n, m;
int a[400000];
int b[400000][4];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int f(int x, int y)
{
    if (x == 1) {
        return y - 1;
    } else if (x == n) {
        return m + y - 1;
    } else if (y == 1) {
        return 2 * m + x - 1;
    } else {
        return 2 * m + n + x - 1;
    }
}

int main()
{
    int x, y, p, r = 0, i;
    long long sum = 1;
    char s[3];
    
    scanf("%d %d", &n, &m);
    scanf("%d %d %s", &x, &y, s);
    
    if (s[0] == 'D') {
        if (s[1] == 'R') {
            p = 0;
        } else {
            p = 1;
        }
    } else {
        if (s[1] == 'R') {
            p = 2;
        } else {
            p = 3;
        }
    }
    
    for (i = 1; i <= m; i++) {
        if ((x + y) % 2 != (i + 1) % 2) a[f(1, i)] = 1;
        if ((x + y) % 2 != (i + n) % 2) a[f(n, i)] = 1;
    }
    
    for (i = 1; i <= n; i++) {
        if ((x + y) % 2 != (i + 1) % 2) a[f(i, 1)] = 1;
        if ((x + y) % 2 != (i + m) % 2) a[f(i, m)] = 1;
    }
    
    a[2 * m] = a[2 * m + n - 1] = a[2 * m + n] = a[2 * m + 2 * n - 1] = a[f(x, y)] = 1;
    
    for (i = 0; i < 2 * m + 2 * n; i++) {
        if (a[i] == 0) r++;
    }
    
    while (1) {
        int c = 1e9;
        
        if (p < 2) {
            c = min(c, n - x);
        } else {
            c = min(c, x - 1);
        }
        
        if (p & 1) {
            c = min(c, y - 1);
        } else {
            c = min(c, m - y);
        }
        
        x += dx[p] * c;
        y += dy[p] * c;
        sum += c;
        
        if (a[f(x, y)] == 0) r--;
        
        if (r == 0) break;
        
        a[f(x, y)] = 1;
        
        if (b[f(x, y)][p] == 1) {
            puts("-1");
            
            return 0;
        }
        
        b[f(x, y)][p] = 1;
        
        if (x == 1 || x == n) p = (p + 2) % 4;
        if (y == 1) p = (p + 3) % 4;
        if (y == m) p = (p + 1) % 4;
    }
    
    printf("%I64d\n", sum);
    
    return 0;
}