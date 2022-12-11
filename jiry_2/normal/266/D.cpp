#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int point1,point2,w;
}b[40000];
int d[210][210],n,m,A[210];
double ans;
struct atom{
    double w;
    int where,l,r;
}x[210];
int compare(atom k1,atom k2){
    return k1.w<k2.w;
}
int main(){
    scanf("%d%d",&n,&m); memset(d,0x3f,sizeof d);
    for (int i=1;i<=m;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
        d[k1][k2]=min(d[k1][k2],k3); d[k2][k1]=min(d[k2][k1],k3);
        b[i]=(bian){k1,k2,k3};
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    ans=1e15;
    for (int i=1;i<=n;i++) d[i][i]=-0;
    for (int now=1;now<=m;now++){
        for (int j=1;j<=n;j++){
            int k1=d[j][b[now].point1],k2=d[j][b[now].point2]+b[now].w;
            double k3=(k2-k1)/2.0; k3=min(max(k3,0.0),b[now].w*1.0); x[j]=(atom){k3,j,k1,k2};
        }
        sort(x+1,x+n+1,compare); for (int i=1;i<=n+1;i++) A[i]=-1e9;
        for (int i=n;i;i--) A[i]=max(A[i+1],x[i].l); int B=-1e9;
        double num=1e15;
        for (int i=1;i<=n+1;i++){
            double k1=min(max((B-A[i])/2.0,x[i-1].w),x[i].w); num=min(num,max(A[i]+k1,B-k1)); B=max(B,x[i].r);
        }
        ans=min(ans,num);
    }
    printf("%.2lf\n",ans);
    return 0;
}