#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
const int mod=1e9+7;
int n,dp[N][N],a[N][26],b[N][26];
char s[N],t[N];
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);scanf("%s%s",s+1,t+1);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<26;j++) a[i][j]=a[i+1][j],b[i][j]=b[i+1][j];
            a[i][s[i]-'a']++;b[i][t[i]-'a']++;
        }
        bool flag=true;
        for(int i=0;i<26;i++) if(a[1][i]!=b[1][i]) flag=false;
        if(!flag)
        {
            printf("-1\n");continue;
        }
        dp[0][1]=dp[1][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            bool flag=true;
            for(int k=0;k<26;k++)
                if(a[i][k]<b[j][k]) {flag=false;break;}
            if(flag)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(s[i]==t[j]));
        }
        printf("%d\n",n-dp[n][n]);
    }
}