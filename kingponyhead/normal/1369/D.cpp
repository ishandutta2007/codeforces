// Screw this ..
#include<bits/stdc++.h>
using namespace std;
const int N = 2000006, Mod = 1e9 + 7;
int dp[N];
int main()
{
    dp[1] = dp[2] = 0;
    for (int i = 3; i < N; i ++)
        dp[i] = (dp[i - 1] + dp[i - 2] * 2LL + (i % 3 == 0 ? 4 : 0)) % Mod;

    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}