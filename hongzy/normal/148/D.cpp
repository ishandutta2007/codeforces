#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

double dp[N][N];
int n, m;

int pn(int n) { return n * (n - 1); }

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) dp[i][0] = 1;
    for(int i = 0; i <= m; i ++) dp[0][i] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int c = pn(i + j - 1);
            double p = 0; //
            if(i >= 1 && j - 1 >= 1) p += i * (j - 1) * 1.0 / c * dp[i - 1][j - 2];
            if(j - 1 >= 2) p += pn(j - 1) * 1.0 / c * dp[i][j - 3];
            dp[i][j] = i * 1.0 / (i + j) + j * 1.0 / (i + j) * p;
        }
    }
    printf("%.9f\n", dp[n][m]);
    return 0;
}