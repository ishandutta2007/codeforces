#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N][N],c[N][N],dist[N][N],t;
char str[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++)if(str[j]=='*')a[i][j+1]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int d=0;
        while(a[i-d][j]&&a[i+d][j]&&a[i][j-d]&&a[i][j+d])++d;
        --d;
        if(d<=0)continue;
        dist[i][j]=d,++t;//printf("%d %d %d\n",i,j,d);
        for(int k=0;k<=d;k++)c[i-k][j]=c[i+k][j]=c[i][j-k]=c[i][j+k]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]&&!c[i][j]){printf("-1");return 0;}
    printf("%d\n",t);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(dist[i][j])printf("%d %d %d\n",i,j,dist[i][j]);
    return 0;
}