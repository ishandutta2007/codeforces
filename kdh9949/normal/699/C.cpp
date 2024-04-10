#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[101];
int dp[101][3];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(a[i] & 1){
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }else dp[i][1] = 123;
        if(a[i] & 2){
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }else dp[i][2] = 123;
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
    }
    printf("%d", min(dp[n][0], min(dp[n][1], dp[n][2])));
}