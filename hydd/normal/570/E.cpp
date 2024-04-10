#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,m,dp[2][510][510];
char a[510][510];
inline int add(int x,int y){ return (x+y>=Mod?x+y-Mod:x+y);}
int main(){
    scanf("%d%d",&n,&m); n--; m--;
    for (int i=0;i<=n;i++) scanf("%s",a[i]);
    //(0,0) -> (n,m)
    int now=0,ans=0; dp[now][0][n]=1;
    for (int k=0;k<=((n+m)>>1);k++){
        for (int i=0;i<=k&&i<=n;i++){
            int x=k-i;
            for (int j=max(i,n-k);j<=n;j++){
                int y=n+m-k-j;
                int v=dp[now][i][j]; dp[now][i][j]=0;//(i,x),(j,y)
                if (x<0||x>m||y<0||y>m||x>y||a[i][x]!=a[j][y]||!v) continue;
//                cerr<<i<<' '<<x<<' '<<j<<' '<<y<<' '<<v<<endl;
                if (k==((n+m)>>1)){ ans=add(ans,v); continue;}
//                if (i+1<=j-1&&a[i+1][x]==a[j-1][y])
                dp[now^1][i+1][j-1]=add(dp[now^1][i+1][j-1],v);//(i+1,x),(j-1,y)
//                if (i<j&&x<y&&a[i][x+1]==a[j-1][y])
                dp[now^1][i][j-1]=add(dp[now^1][i][j-1],v);//(i,x+1),(j-1,y)
//                if (i<j&&x<y&&a[i+1][x]==a[j][y-1])
                dp[now^1][i+1][j]=add(dp[now^1][i+1][j],v);//(i+1,x),(j,y-1)
//                if (x+1<=y-1&&a[i][x+1]==a[j][y-1])
                dp[now^1][i][j]=add(dp[now^1][i][j],v);//(i,x+1),(j,y-1)
            }
        }
        now^=1;
    }
    printf("%d\n",ans);
    return 0;
}