#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1610][1610],b[1610][1610],n,m,pd[1610][1610],w[1610][1610],sign,gox[4]={1,-1,0,0},goy[4]={0,0,1,-1},ans[2000000],c[1610][1610],len;
void dfs(int k1,int k2){
    pd[k1][k2]=1; w[k1][k2]=sign;
    for (int i=0;i<4;i++){
        int k3=k1+gox[i],k4=k2+goy[i];
        if (pd[k3][k4]==0&&a[k3][k4]) dfs(k3,k4);
    }
}
void getin(){
    memcpy(c,b,sizeof b);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (b[i][j]==0)
                for (int k=0;k<4;k++){
                    int k1=i+gox[k],k2=j+goy[k];
                    c[k1][k2]=0;
                }
    memcpy(b,c,sizeof c);
}
void getout(){
    memcpy(c,b,sizeof b);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (b[i][j]==1)
                for (int k=0;k<4;k++){
                    int k1=i+gox[k],k2=j+goy[k];
                    if (k1>0&&k1<=n&&k2>0&&k2<=m) c[k1][k2]=1;
                }
    memcpy(b,c,sizeof c);
}
void dfs2(int k1,int k2){
    int gox[8]={1,1,1,-1,-1,-1,0,0},goy[8]={1,-1,0,1,-1,0,1,-1};
    pd[k1][k2]=1; w[k1][k2]=sign;
    for (int i=0;i<8;i++){
        int k3=k1+gox[i],k4=k2+goy[i];
        if (pd[k3][k4]==0&&a[k3][k4]) dfs2(k3,k4);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            scanf("%d",&a[i][j]); b[i][j]=a[i][j];
        }
    sign=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (pd[i][j]==0&&a[i][j]){
                sign++; dfs(i,j);
            }
    for (int i=1;i<=3;i++) getin();
    for (int i=1;i<=5;i++) getout();
    memcpy(c,a,sizeof a);
    memset(a,0x00,sizeof a);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (b[i][j]==0&&c[i][j]==1) a[i][j]=1;
    len=sign; sign=0; memset(pd,0x00,sizeof pd);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]&&pd[i][j]==0){
                sign++; ans[w[i][j]]++; dfs2(i,j);
            }
    sort(ans+1,ans+len+1);
    printf("%d\n",len);
    for (int i=1;i<=len;i++) printf("%d ",ans[i]); cout<<endl;
    return 0;
}