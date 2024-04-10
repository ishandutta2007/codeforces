#include <cstdio>
#include <algorithm>

using namespace std;

int a[500];
int b[500][500];

int main()
{
    int n, m, i, j;
    double ans = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < m; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        b[x - 1][y - 1] = z;
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] == 0) continue;
            
            ans = max(ans, (double)(a[i] + a[j]) / b[i][j]);
        }
    }
    
    printf("%.12lf\n", ans);
    
    return 0;
}