#include <cstdio>

using namespace std;

int a[1000001];
int b[1000001][2];
int ans[200000];

int main()
{
    int n, p, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        a[x] = y;
        b[x][0]++;
        b[y][1]++;
    }
    
    p = a[0];
    
    for (i = 1; p != 0; i += 2) {
        ans[i] = p;
        p = a[p];
    }
    
    for (i = 1; i <= 1000000; i++) {
        if (b[i][0] == 1 && b[i][1] == 0) {
            p = i;
            
            break;
        }
    }
    
    for (i = 0; p != 0; i += 2) {
        ans[i] = p;
        p = a[p];
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", ans[i]);
    }
    
    puts("");
    
    return 0;
}