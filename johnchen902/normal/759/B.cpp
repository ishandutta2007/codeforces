#include <cstdio>
#include <algorithm>
using namespace std;
int t[100000]; 
int dp[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", t + i);
    dp[0] = 0;
    for(int i = 0, j = 0, k = 0; i < n; i++) {
        while(t[i] - t[j] >= 90)
            j++;
        while(t[i] - t[k] >= 1440)
            k++;
        dp[i + 1] = min(dp[i] + 20, min(dp[j] + 50, dp[k] + 120));
        printf("%d\n", dp[i + 1] - dp[i]);
    }
}