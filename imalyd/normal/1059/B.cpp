//Problem B
#include<bits/stdc++.h>
using namespace std;
int x[8]={0,0,0,1,2,2,2,1},y[8]={0,1,2,2,2,1,0,0};
int n,m,a[1007][1007],c[1007][1007];
char str[1007];
#define NO {printf("NO");exit(0);}
int chk(int x,int y){
    if(!a[x][y]||x<1||n<x||y<1||m<y)return 0;
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str+1);
        for(int j=1;j<=m;j++)if(str[j]=='#')a[i][j]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int f=1;
        for(int k=0;k<8;k++)f&=chk(i+x[k]-1,j+y[k]-1);
        if(f)for(int k=0;k<8;k++)c[i+x[k]-1][j+y[k]-1]=1;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]&&!c[i][j])NO
    printf("YES");
    return 0;
}