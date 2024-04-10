#include<bits/stdc++.h>
using namespace std;
#define mid (l+r>>1)
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef long double ld;
ll mod=1e9+7;
const ld pi=acos(-1.L);
const ld eps=3e-17;
const int mn=2e5+10;
int dp[101][101][101][2];
int a[101],r[2];
int main(){
    int n;
    scanf("%d",&n);
    r[0]=n/2,r[1]=n-r[0];
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(!a[i])a[i]=-1;
        else a[i]%=2,r[a[i]]--;
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0][0]=dp[0][0][0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=r[0];j++){
            for(int k=0;k<=r[1];k++){
                if(a[i]==0){
                    dp[i][j][k][0]=min(dp[i-1][j][k][0],dp[i-1][j][k][1]+1);
                }
                else if(a[i]==1){
                    dp[i][j][k][1]=min(dp[i-1][j][k][1],dp[i-1][j][k][0]+1);
                }
                else{
                    if(j)dp[i][j][k][0]=min(dp[i-1][j-1][k][0],dp[i-1][j-1][k][1]+1);
                    if(k)dp[i][j][k][1]=min(dp[i-1][j][k-1][1],dp[i-1][j][k-1][0]+1);
                }
            }
        }
    }
    printf("%d",min(dp[n][r[0]][r[1]][0],dp[n][r[0]][r[1]][1]));
}