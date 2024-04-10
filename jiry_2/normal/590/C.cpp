#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int dp[1100][1100][1<<3],w[1100][1100],n,m,now,pd[1100][1100];
const int gox[4]={1,0,-1,0},goy[4]={0,1,0,-1};
struct atom{
    int x,y,w;
};
int operator < (atom k1,atom k2){
    return k1.w>k2.w;
}
priority_queue<atom>Q;
char ch[1100][1100];
int main(){
    scanf("%d%d",&n,&m);
    memset(w,0xff,sizeof w);
    for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (ch[i][j]=='.') w[i][j]=0; else if (ch[i][j]!='#') w[i][j]=ch[i][j]-'0';
    memset(dp,0x3f,sizeof dp); int ans=1e9;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) if (w[i][j]!=-1){
            if (w[i][j]==0) dp[i][j][0]=1; else dp[i][j][(1<<w[i][j]-1)]=0;
        }
    for (now=0;now<(1<<3);now++){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (w[i][j]!=-1){
                    int num=(w[i][j]==0);
                    for (int k=now;k;k=(k-1)&now) dp[i][j][now]=min(dp[i][j][now],dp[i][j][k]+dp[i][j][now-k]-num);
                }
        memset(pd,0x00,sizeof pd);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) if (w[i][j]!=-1&&dp[i][j][now]<ans) Q.push((atom){i,j,dp[i][j][now]});
        while (!Q.empty()){
            atom k=Q.top(); Q.pop();
            int x=k.x,y=k.y; if (pd[x][y]) continue;
            pd[x][y]=1;
            for (int i=0;i<4;i++){
                int k1=gox[i]+x,k2=goy[i]+y; if (w[k1][k2]==-1) continue;
                if (dp[k1][k2][now]>k.w+(w[k1][k2]==0)){
                    dp[k1][k2][now]=k.w+(w[k1][k2]==0);
                    Q.push((atom){k1,k2,dp[k1][k2][now]});
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) ans=min(ans,dp[i][j][7]);
    if (ans<=n*m) printf("%d\n",ans); else printf("-1\n");
    return 0;
}