#include<cstdio>
int dp[105][105],n,i,j,flag;
char ipt[105];

int main(){
    scanf("%d",&n);
    scanf("%s",&ipt);
    for(i=1;i<=n/4;i++) {
        for(j=i;j<n;j++) {
            if(ipt[j-i]=='*' && ipt[j]=='*') {
                dp[i][j]=dp[i][j-i]+1;
                if(dp[i][j]>=4)flag=1;
            }
        }
    }
    if(flag)puts("yes");
    else puts("no");
}