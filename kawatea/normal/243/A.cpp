#include <cstdio>
#include <set>

using namespace std;

int a[100000];
int b[1000001][20];

int main()
{
    int n, i, j;
    set <int> s;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < 20; i++) b[n][i] = n;
    
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < 20; j++) {
            b[i][j] = b[i + 1][j];
            
            if ((a[i] >> j) & 1) b[i][j] = i;
        }
    }
    
    for (i = 0; i < n; i++) {
        int x = a[i], y = i;
        
        s.insert(x);
        
        while (1) {
            int z = n;
            
            for (j = 0; j < 20; j++) {
                if ((x >> j) & 1) continue;
                
                z = min(z, b[y][j]);
            }
            
            if (z == n) break;
            
            x = x | a[z];
            y = z;
            s.insert(x);
        }
    }
    
    printf("%d\n", (int)s.size());
    
    return 0;
}