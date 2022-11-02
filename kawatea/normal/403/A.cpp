#include <cstdio>

using namespace std;

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, p, j, k;
        int a[24][24] = {{0}};
        
        scanf("%d %d", &n, &p);
        
        for (j = 0; j < n; j++) {
            a[j][(j + 1) % n] = a[(j + 1) % n][j] = 1;
            a[j][(j + 2) % n] = a[(j + 2) % n][j] = 1;
        }
        
        for (j = 0; j < n && p > 0; j++) {
            for (k = j + 1; k < n && p > 0; k++) {
                if (a[j][k] == 0) {
                    a[j][k] = a[k][j] = 1;
                    
                    p--;
                }
            }
        }
        
        for (j = 0; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                if (a[j][k] == 1) printf("%d %d\n", j + 1, k + 1);
            }
        }
    }
    
    return 0;
}