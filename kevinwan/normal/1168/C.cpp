#include <bits/stdc++.h>
using namespace std;
const int mn=3e5+10;
int a[mn],dp[mn][19],rec[19];
int main()
{
    int n,q,i,j,k;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)scanf("%d",a+i);
    memset(dp,0x3f,sizeof(dp));
    for(i=0;i<19;i++)dp[n][i]=n,rec[i]=n;
    for(i=n-1;i>=0;i--){
        for(j=0;j<19;j++){
            if((a[i]>>j)&1){
                dp[i][j]=i;
                for(k=0;k<19;k++){
                    dp[i][k]=min(dp[i][k],dp[rec[j]][k]);
                }
                rec[j]=i;
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        bool ans=0;
        for(i=0;i<19;i++)if((a[y]>>i)&1)ans|=dp[x][i]<=y;
        if(ans)printf("Shi\n");
        else printf("Fou\n");
    }
}