#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=5e5+10;
const ll mod=1e6+3;
typedef pair<ll,ll>pll;
int dp[mn][4];
bool o[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==0){
        printf("0");
        return 0;
    }
    memset(dp,0xc0,sizeof(dp));
    int ad=1;
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        o[x-1]=1;
    }
    for(int i=0;i<1<<n;i+=2)ad+=o[i]|o[i+1];
    for(int i=0;i<1<<n-1;i++){
        int num=0+o[i*2]+o[i*2+1];
        dp[(1<<n-1)+i][0]=0;
        if(num>=1)dp[(1<<n-1)+i][1]=0,dp[(1<<n-1)+i][2]=0;
        if(num==2)dp[(1<<n-1)+i][3]=0;
    }
    for(int i=(1<<n-1)-1;i;i--){
        for(int j=0;j<4;j++)for(int k=0;k<4;k++){
            dp[i][j|k]=max(dp[i][j|k],dp[i*2][j]+dp[i*2+1][k]);
        }
        for(int j=0;j<4;j++)dp[i][j]+=j;
    }
    int od=0;
    for(int i=0;i<4;i++)od=max(od,dp[1][i]);
    printf("%d",od+ad);
}