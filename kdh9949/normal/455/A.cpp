#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, t;
ll s[100010];
ll dp[100010][2];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &t), s[t] += (ll)t;
    for(int i = 1; i <= 100000; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + s[i];
    }
    printf("%I64d", max(dp[100000][0], dp[100000][1]));
}