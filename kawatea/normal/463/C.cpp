#include <cstdio>
#include <algorithm>

using namespace std;

int a[2000][2000];
long long sum[4000];
long long sum2[4000];

int main()
{
    int n, x1, y1, x2, y2, i, j;
    long long x = -1, y = -1;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            
            sum[i + j] += a[i][j];
            sum2[i - j + 2000] += a[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            long long z = sum[i + j] + sum2[i - j + 2000] - a[i][j];
            
            if ((i + j) % 2 == 0) {
                if (z > x) {
                    x = z;
                    x1 = i + 1;
                    y1 = j + 1;
                }
            } else {
                if (z > y) {
                    y = z;
                    x2 = i + 1;
                    y2 = j + 1;
                }
            }
        }
    }
    
    printf("%I64d\n", x + y);
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    
    return 0;
}