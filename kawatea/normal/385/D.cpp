#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double dp[1 << 20];

int main()
{
    int n, l, r, i, j;
    double pi = acos(-1);
    int a[20][3];
    
    scanf("%d %d %d", &n, &l, &r);
    
    for (i = 0; i < n; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    
    dp[0] = 0;
    
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            double x1, y1, x2, y2;
            
            if ((i >> j) & 1) continue;
            
            x1 = l + dp[i] - a[j][0];
            y1 = -a[j][1];
            x2 = x1 * cos(a[j][2] * pi / 180) - y1 * sin(a[j][2] * pi / 180);
            y2 = x1 * sin(a[j][2] * pi / 180) + y1 * cos(a[j][2] * pi / 180);
            
            if (y2 >= 0) {
                dp[i | (1 << j)] = r - l;
            } else {
                dp[i | (1 << j)] = max(dp[i | (1 << j)], min((double)r, a[j][0] - a[j][1] / y2 * x2) - l);
            }
        }
    }
    
    printf("%.12lf\n", dp[(1 << n) - 1]);
    
    return 0;
}