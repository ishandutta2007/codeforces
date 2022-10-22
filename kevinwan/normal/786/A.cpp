#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=7e3+10;
int a[mn][2],n,k[2];
int dp[mn][2],num[mn][2];
void dfs(int x,bool y){
    for(int i=0;i<k[!y];i++){
        int pos=(x-a[i][!y]+n)%n;
        if(pos==0)continue;
        dp[pos][!y]=max(dp[pos][!y],2-dp[x][y]);
        if(dp[x][y]==0){
            if(num[pos][!y]){
                num[pos][!y]=0;
                dfs(pos,!y);
            }
        }
        else{
            if(num[pos][!y]){
                num[pos][!y]--;
                if(!num[pos][!y]){
                    dfs(pos,!y);
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i,j;
    cin>>n>>k[0];
    for(i=0;i<k[0];i++)cin>>a[i][0];
    cin>>k[1];
    for(i=0;i<k[1];i++)cin>>a[i][1];
    memset(dp,-1,sizeof(dp));
    for(i=1;i<n;i++){
        num[i][0]=k[0];
        num[i][1]=k[1];
    }
    dp[0][0]=dp[0][1]=0;
    dfs(0,0);
    dfs(0,1);
    for(i=1;i<n;i++){
        if(num[i][0])printf("Loop ");
        else if(dp[i][0])printf("Win ");
        else printf("Lose ");
    }
    printf("\n");
    for(i=1;i<n;i++){
        if(num[i][1])printf("Loop ");
        else if(dp[i][1])printf("Win ");
        else printf("Lose ");
    }
}