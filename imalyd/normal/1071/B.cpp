//Problem B
#include<bits/stdc++.h>
using namespace std;

int n,k,a[2018][2018][2],is[2018][2018],dp[2018][2018],pre[2018][2018];
char ch[2018][2018],ans[4444];
int trans(int a,char c){
    if(a<0)return -c;
    if(a==0&&c!='a')return -c;
    if(c!='a')return a-1;
    return a;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
    for(int i=1;i<=n+1;i++)for(int j=1;j<=n+1;j++)a[i][j][0]=a[i][j][1]=-10000;
    a[1][1][0]=k-1;
    for(int i=2;i<=n<<1;i++){
        int mx=-10000;
        for(int x=1;x<=n;x++){
            int y=i-x;
            if(0<y&&y<=n)mx=max(mx,max(a[x][y][0],a[x][y][1]));
        }//printf("Turn %d max=%d\n",i,mx);
        for(int x=1;x<=n;x++){
            int y=i-x;
            if(0<y&&y<=n){//printf("(%d,%d):%d,%d\n",x,y,a[x][y][0],a[x][y][1]);
                if(a[x][y][0]==mx||a[x][y][0]>=max(0,a[x][y][1]))is[x][y]=1;
                else if(a[x][y][1]==mx||a[x][y][1]>=max(0,a[x][y][0]))a[x][y][0]=a[x][y][1],is[x][y]=1,pre[x][y]=1;
            }
        }
        for(int x=1;x<=n;x++){
            int y=i-x;
            if(0<y&&y<=n&&is[x][y]){//printf("is %d %d:",x,y);
                if(y<n)a[x][y+1][0]=trans(a[x][y][0],ch[x][y+1]);
                if(x<n)a[x+1][y][1]=trans(a[x][y][0],ch[x+1][y]);//printf("(%d,%d)->%d,%d\n",x,y,a[x][y+1][0],a[x+1][y][1]);
            }
        }//printf("\n");
    }
    int X=n,Y=n,cnt=k;
    for(int i=2*n-1;i;i--){
        ans[i]=ch[X][Y];
        if(pre[X][Y])--X;else --Y;
    }
    for(int i=1;i<=2*n-1;i++){
        if(ans[i]!='a'&&cnt)--cnt,printf("a");
        else printf("%c",ans[i]);
    }
    return 0;
}