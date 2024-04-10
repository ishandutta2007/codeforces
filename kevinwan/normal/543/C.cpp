#include <bits/stdc++.h>
using namespace std;
string s[20];
int c[20][20];
char cnt[26];
int dp[1<<20];
int am[20][20],co[20][20],mo[20][20];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>s[i];
    memset(c,0x3f,sizeof(c));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&c[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(s[i][j]==s[k][j]){
                    am[i][j]|=1<<k;
                    co[i][j]+=c[k][j];
                    mo[i][j]=max(mo[i][j],c[k][j]);
                }
            }
            co[i][j]-=mo[i][j];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<1<<n;i++){
        int b=__builtin_ctz(i);
        for(int j=0;j<m;j++){
            dp[i]=min(dp[i],min(dp[i^(1<<b)]+c[b][j],dp[i&(~am[b][j])]+co[b][j]));
        }
    }
    printf("%d",dp[(1<<n)-1]);
}