#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
  
const int INF=0x3f3f3f3f;  
const int MAX=105;  
int n,a[MAX],dp[MAX][5];  
  
int main(){  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++){  
        scanf("%d",&a[i]);  
    }  
    memset(dp,INF,sizeof(dp));  
    dp[1][0]=1;  
    if(a[1]==1) dp[1][2]=0;  
    if(a[1]==2) dp[1][1]=0;  
    if(a[1]==3) dp[1][1]=dp[1][2]=0;  
    for(int i=2;i<=n;i++){  
        dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;  
        if(a[i]==1) dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]+1);  
        if(a[i]==2) dp[i][1]=min(min(dp[i-1][0],dp[i-1][2]),dp[i-1][1]+1);  
        if(a[i]==3){  
            dp[i][2]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]+1);  
            dp[i][1]=min(min(dp[i-1][0],dp[i-1][2]),dp[i-1][1]+1);  
        }  
    }  
    printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));  
    return 0;  
}