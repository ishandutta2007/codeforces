#include <bits/stdc++.h>
using namespace std;
int dp[2001];
bool ex[2001];
int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    memset(dp,0x3f,sizeof(dp));
    for(i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        ex[x-n+1000]=1;
    }
    memset(dp,0x3f,sizeof(dp));
    queue<int>q;
    for(i=0;i<=2000;i++)if(ex[i]){
        dp[i]=1;
        q.push(i);
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        for(i=0;i<=2000;i++){
            int y=i+x-1000;
            if(y>2000||y<0||!ex[i])continue;
            if(dp[x]+1<dp[y]){
                q.push(y);
                dp[y]=dp[x]+1;
            }
        }
    }
    if(dp[1000]==0x3f3f3f3f)printf("-1");
    else printf("%d",dp[1000]);
}