#include <cstdio>

using namespace std;

int main()
{
    int n, m, i, j, k;
    int a[100][100];
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 1; ; i <<= 1) {
        int f = 0;
        
        if (n / i % 2 != 0) break;
        
        for (j = 0; j < n / i / 2; j++) {
            for (k = 0; k < m; k++) {
                if (a[j][k] != a[n / i - j - 1][k]) f = 1;
            }
        }
        
        if (f == 1) break;
    }
    
    printf("%d\n", n / i);
    
    return 0;
}