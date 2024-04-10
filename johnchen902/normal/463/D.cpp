#include <cstdio>
#include <algorithm>
using namespace std;
int a[5][1000];
bool bad[1000][1000];
int dp[1000];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", a[i] + j), a[i][j]--;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k <= j; k++)
                bad[a[i][j]][a[i][k]] = true;
//    for(int j = 0; j < n; j++) {
//        for(int k = 0; k < n; k++)
//            printf("%d ", bad[j][k]);
//        puts("");
//    }
    int maxi = 1;
    for(int i = 0; i < n; i++) {
        int x = a[0][i];
        dp[x] = 1;
        for(int j = 0; j < n; j++) {
            if(!bad[j][x]) {
                dp[x] = max(dp[x], dp[j] + 1);
            }
        }
        maxi = max(maxi, dp[x]);
    }
//    for(int j = 0; j < n; j++) {
//        printf("%d ", dp[j]);
//    }
//    puts("");
    printf("%d\n", maxi);
}