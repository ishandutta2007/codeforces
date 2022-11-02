#include <cstdio>

using namespace std;

int a[5000];
short sum[5001][5001][2];
short sum2[5001][5001][2];

int main()
{
    int n, ans = 0, num = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                sum[i][j + 1][0] = sum[i][j][0];
                sum[i][j + 1][1] = sum[i][j][1];
            } else if (a[j] < a[i]) {
                sum[i][j + 1][0] = sum[i][j][0] + 1;
                sum[i][j + 1][1] = sum[i][j][1];
            } else {
                sum[i][j + 1][0] = sum[i][j][0];
                sum[i][j + 1][1] = sum[i][j][1] + 1;
            }
        }
        
        for (j = n - 1; j >= 0; j--) {
            if (i == j) {
                sum2[i][j][0] = sum2[i][j + 1][0];
                sum2[i][j][1] = sum2[i][j + 1][1];
            } else if (a[j] < a[i]) {
                sum2[i][j][0] = sum2[i][j + 1][0] + 1;
                sum2[i][j][1] = sum2[i][j + 1][1];
            } else {
                sum2[i][j][0] = sum2[i][j + 1][0];
                sum2[i][j][1] = sum2[i][j + 1][1] + 1;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int tmp = 1;
            
            if (a[i] < a[j]) continue;
            
            tmp += sum2[i][i][0] - sum2[i][j][0];
            tmp -= sum2[i][i][1] - sum2[i][j][1];
            tmp -= sum[j][j][0] - sum[j][i + 1][0];
            tmp += sum[j][j][1] - sum[j][i + 1][1];
            
            if (tmp > ans) {
                ans = tmp;
                num = 1;
            } else if (tmp == ans) {
                num++;
            }
        }
    }
    
    ans = -ans;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) ans++;
        }
    }
    
    printf("%d %d\n", ans, num);
    
    return 0;
}