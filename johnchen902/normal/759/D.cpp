#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int mod = 1000000007;

char s[5001];
int dp[5001][5001];
int last[26];
int main() {
    int n;
    scanf("%d %s", &n, s);
    for(int j = 1; j <= n; j++) {
        fill_n(last, 26, 0);
        long long sum = j == 1 ? 1 : 0;
        for(int i = 1; i <= n; i++) {
            int ch = s[i - 1] - 'a';
            sum -= dp[j - 1][last[ch]];
            last[ch] = i;
            sum += dp[j - 1][last[ch]];

            if(sum < 0)
                sum += mod;
            else if(sum >= mod)
                sum -= mod;

            dp[j][i] = sum;
        }
    }
#if 0
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            printf("%4d", dp[i][j]);
        }
        putchar('\n');
    }
#endif
    int ans = 0;
    for(int k = 0; k < 26; k++)
        if(last[k] >= 0)
            ans = (ans + dp[n][last[k]]) % mod;
    printf("%d\n", ans); 
}