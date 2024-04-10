#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
#define mo 777777777
using namespace std;
int n;
int w[4][4];
int seg[300000][4][4]={0};
int tmp[4][4];
void pu(int rt){
    int ls=rt<<1,rs=rt<<1|1;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++){
            tmp[i][j]=0;
            for (int k=1;k<=3;k++)tmp[i][j]=(tmp[i][j]+1ll*seg[ls][i][k]*w[k][j])%mo;
        }
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++){
            seg[rt][i][j]=0;
            for (int k=1;k<=3;k++)seg[rt][i][j]=(seg[rt][i][j]+1ll*tmp[i][k]*seg[rs][k][j])%mo;
        }
}
void build(int l,int r,int rt){
    if(l==r){
        seg[rt][1][1]=seg[rt][2][2]=seg[rt][3][3]=1;
    }else{
        int mid=l+r>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        pu(rt);
    }
}
int I,x;
void upd(int l,int r,int rt){
    if(l==r){
        if(x==0)seg[rt][1][1]=seg[rt][2][2]=seg[rt][3][3]=1;
        else seg[rt][1][1]=seg[rt][2][2]=seg[rt][3][3]=0,seg[rt][x][x]=1;
    }else{
        int mid=l+r>>1;
        if(I<=mid)upd(l,mid,rt<<1);
        else upd(mid+1,r,rt<<1|1);
        pu(rt);
    }
}
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)scanf("%d",&w[i][j]);
    build(1,n,1);
    while(q--){
        scanf("%d%d",&I,&x);
        upd(1,n,1);
        int ans=0;
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++){
                ans=(ans+seg[1][i][j])%mo;
            }
        printf("%d\n",ans);
    }
    return 0;
}