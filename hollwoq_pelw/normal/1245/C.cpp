#include<bits/stdc++.h>
using namespace std;
char s[101010];
int dp[101010];
const int MOD = 1e9+7;
int main()
{
    dp[0] = 1;
    scanf("%s", s+1);
    int N = strlen(s+1);
    for(int i=1; i<=N; ++i)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            puts("0");
            return 0;
        }
        dp[i] = dp[i-1];
        if(i!=1&&(s[i] == 'n'&&s[i-1]=='n' || s[i]=='u'&&s[i-1]=='u'))
            dp[i] = (dp[i-2]+dp[i])%MOD;
    }
    printf("%d\n", dp[N]);
}