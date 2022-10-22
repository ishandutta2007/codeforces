#include <bits/stdc++.h>
using namespace std;
int n,k;
string s[51];
int cnt[51][51];
int dp[51][51][51][51];
int main()
{
    int n,i,j,k,l,d,e,f;
    scanf("%d",&n);
    for(i=1;i<=n;i++)cin>>s[i],s[i]=" "+s[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(s[i][j]=='#')cnt[i][j]=1;
            cnt[i][j]=cnt[i][j]+cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
        }
    }
    for(d=0;d<n;d++){
        for(i=1;i+d<=n;i++){
            j=i+d;
            for(e=0;e<n;e++){
                for(k=1;k+e<=n;k++){
                    l=k+e;
                    if(cnt[j][l]-cnt[i-1][l]-cnt[j][k-1]+cnt[i-1][k-1]==0)continue;
                    if(d==e)dp[i][j][k][l]=d+1;
                    else dp[i][j][k][l]=0x3f3f3f3f;
                    for(f=i;f<j;f++){
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i][f][k][l]+dp[f+1][j][k][l]);
                    }
                    for(f=k;f<l;f++){
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i][j][k][f]+dp[i][j][f+1][l]);
                    }
                }
            }
        }
    }
    printf("%d",dp[1][n][1][n]);
}