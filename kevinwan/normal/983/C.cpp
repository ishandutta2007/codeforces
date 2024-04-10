#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e3+10,ms=1e4+10;
int a[mn],b[mn];
int dp[2][10][ms];
int add[mn][10];
int sub[mn][10];
int c[10][10][10][10];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
    memset(add,-1,sizeof(add));
    memset(sub,-1,sizeof(sub));
    int ct=0;
    for(int i=0;i<=9;i++)for(int j=i;j<=9;j++)for(int k=j;k<=9;k++)for(int l=k;l<=9;l++){
        c[i][j][k][l]=ct++;
    }
    for(int i=0;i<=9;i++)for(int j=i;j<=9;j++)for(int k=j;k<=9;k++)for(int l=k;l<=9;l++){
        if(!i)for(int m=1;m<=9;m++){
            vector<int>v={m,j,k,l};
            sort(v.begin(),v.end());
            int nxt=c[v[0]][v[1]][v[2]][v[3]];
            int cur=c[i][j][k][l];
            add[cur][m]=nxt;
            sub[nxt][m]=cur;
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<ct;j++)for(int k=1;k<=9;k++)if(add[j][b[i]]){
            dp[1][a[i]][add[j][b[i]]]=min(dp[1][a[i]][add[j][b[i]]],dp[0][k][j]+abs(a[i]-k)+1);
        }
        memcpy(dp[0],dp[1],sizeof(dp[0]));
        memset(dp[1],0x3f,sizeof(dp[1]));
        for(int j=ct-1;j>=0;j--){
            for(int k=1;k<=9;k++){
                for(int l=1;l<=9;l++)if(sub[j][l]!=-1){
                        dp[0][l][sub[j][l]]=min(dp[0][l][sub[j][l]],dp[0][k][j]+abs(l-k)+1);
                }
            }
        }

    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=9;i++)ans=min(ans,dp[0][i][0]);
    printf("%d",ans);
}