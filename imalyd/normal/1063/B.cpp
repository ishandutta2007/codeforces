//Problem B
#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},dz[4]={1,0,1,0};
int n,m,r,c,x,y,d[2109][2109],q[4444444][2],h,t,s;
char ch[2109][2109];
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
    for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
    h=t=1;q[1][0]=r;q[1][1]=c;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=4444444;d[r][c]=0;
    while(t<=h){
        int x=q[t][0],y=q[t][1];++t;
        for(int i=0;i<4;i++){
            int X=x+dx[i],Y=y+dy[i],Z=d[x][y]+dz[i];
            if(X&&X<=n&&Y&&Y<=m&&ch[X][Y]=='.'&&Z<d[X][Y])d[X][Y]=Z,q[++h][0]=X,q[h][1]=Y;
        }
    }
    //for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%8d",d[i][j]);printf("\n");}
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(d[i][j]<4444444){
        int l=(d[i][j]+c-j)>>1,r=(d[i][j]+j-c)>>1;
        if(l<=x&&r<=y)++s;
    }printf("%d",s);
    return 0;
}