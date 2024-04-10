#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int mod = 1000000007;
char s[1001];
int a[26];
int dp[1001], dp2[1001];
int main() {
    int n;
    scanf("%d %s", &n, s);
    for(int i = 0; i < 26; i++)
        scanf("%d", a + i);
    dp[0] = 1, dp2[0] = 0;
    int maxlen = 0;
    for(int i = 0; i < n; i++) {
        // fprintf(stderr, "%d %d %d\n", dp[i], maxlen, dp2[i]);
        int lim = 20000;
        for(int j = i; j >= 0; j--) {
            lim = min(lim, a[s[j] - 'a']);
            if(i - j + 1 > lim)
                break;
            dp[i + 1] = (dp[i + 1] + dp[j]) % mod;
            dp2[i + 1] = dp2[j] + 1;
            maxlen = max(maxlen, i - j + 1);
        }
    }
    printf("%d\n%d\n%d\n", dp[n], maxlen, dp2[n]);
}