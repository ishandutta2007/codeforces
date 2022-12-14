#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N][N],c[N][N][2],dist[N][N],t,p[N][N][4];
char str[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++)if(str[j]=='*')a[i][j+1]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j])p[i][j][0]=p[i-1][j][0]+1;
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)if(a[i][j])p[i][j][1]=p[i][j+1][1]+1;
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)if(a[i][j])p[i][j][2]=p[i+1][j][2]+1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j])p[i][j][3]=p[i][j-1][3]+1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int d=n+m;
        for(int k=0;k<4;k++)d=min(d,p[i][j][k]);
        --d;
        if(d<=0)continue;
        dist[i][j]=d,++t;//printf("%d %d %d\n",i,j,d);
        c[i-d][j][0]=max(c[i-d][j][0],d<<1|1);
        c[i][j-d][1]=max(c[i][j-d][1],d<<1|1);
    }
    //for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<2;k++)printf("%d %d %d %d\n",i,j,k,c[i][j][k]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j][0]=max(c[i][j][0],c[i-1][j][0]-1);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j][1]=max(c[i][j][1],c[i][j-1][1]-1);
   // for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<2;k++)printf("%d %d %d %d\n",i,j,k,c[i][j][k]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]&&!(c[i][j][0]||c[i][j][1])){printf("-1");return 0;}
    printf("%d\n",t);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(dist[i][j])printf("%d %d %d\n",i,j,dist[i][j]);
    return 0;
}