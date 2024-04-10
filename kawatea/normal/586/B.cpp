#include <cstdio>
#include <algorithm>

using namespace std;

int a[2][50];
int b[50];

int main()
{
    int n, x = 1e9, y = 1e9, i;
    
    scanf("%d", &n);
    
    for (i = 1; i < n; i++) scanf("%d", &a[0][i]);
    for (i = 1; i < n; i++) scanf("%d", &a[1][i]);
    for (i = 0; i < n; i++) scanf("%d", &b[i]);
    
    for (i = 1; i < n; i++) a[0][i] += a[0][i - 1];
    for (i = 1; i < n; i++) a[1][i] += a[1][i - 1];
    
    for (i = 0; i < n; i++) {
        int z = a[0][i] + b[i] + a[1][n - 1] - a[1][i];
        
        if (z < x) {
            y = x;
            x = z;
        } else if (z < y) {
            y = z;
        }
    }
    
    printf("%d\n", x + y);
    
    return 0;
}