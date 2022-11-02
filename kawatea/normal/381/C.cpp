#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000][3];
long long b[100001];

int main()
{
    int m, n, i;
    
    scanf("%d", &m);
    
    b[0] = 0;
    
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i][0]);
        
        if (a[i][0] == 1) {
            scanf("%d", &a[i][1]);
            
            b[i + 1] = b[i] + 1;
        } else {
            scanf("%d %d", &a[i][1], &a[i][2]);
            
            b[i + 1] = b[i] + a[i][1] * a[i][2];
        }
    }
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        long long x;
        
        scanf("%I64d", &x);
        
        if (i > 0) putchar(' ');
        
        while (1) {
            int y = lower_bound(b, b + m + 1, x) - b;
            
            if (a[y - 1][0] == 1) {
                printf("%d", a[y - 1][1]);
                
                break;
            } else {
                x -= b[y - 1] + 1;
                x %= a[y - 1][1];
                x++;
            }
        }
    }
    
    puts("");
    
    return 0;
    
    return 0;
}