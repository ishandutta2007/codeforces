#include <cstdio>

using namespace std;

int t, k;

int dp[100015];
int f(int pos){
    if (pos < 0) return 0;
    if (dp[pos]) return dp[pos];
    return (f(pos - 1) + f(pos - k)) % 1000000007;
}

int main(){
    scanf("%d%d", &t, &k);
    dp[0] = 1;
    for (int i = 1; i <= 100005; ++i) dp[i] = f(i);
    for (int i = 1; i <= 100005; ++i) dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
    
    //printf("-- %d\n", f(4));
    for (int i = 0; i < t; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        int r = f(b) - f(a - 1);
        r = (r + 1000000007) % 1000000007;
        printf("%d\n", r);
    }
    return 0;
}