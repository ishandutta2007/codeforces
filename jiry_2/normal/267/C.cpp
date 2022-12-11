#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int point1,point2,w;
}b[10000];
double x[110][110],d[110];
int n,m;
void doit(){
    for (int i=1;i<=n;i++){
        int r=i;
        for (int j=i+1;j<=n;j++) if (fabs(x[r][i])<fabs(x[j][i])) r=j;
        for (int j=0;j<=n;j++) swap(x[i][j],x[r][j]);
        if (fabs(x[i][i])<1e-8) continue;
        for (int j=i+1;j<=n;j++){
            double k1=x[j][i]/x[i][i];
            for (int k=0;k<=n;k++) x[j][k]-=x[i][k]*k1;
        }
    }
}
void find(int k){
    if (k==0) return;
    if (abs(x[k][k])<1e-11){d[k]=0; find(k-1); return;}
    for (int i=k+1;i<=n;i++) x[k][0]-=x[k][i]*d[i]; d[k]=x[k][0]/x[k][k]; find(k-1); 
}
int main(){
    scanf("%d%d",&n,&m);
    memset(x,0x00,sizeof x);
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&b[i].point1,&b[i].point2,&b[i].w);
        x[b[i].point1][b[i].point2]++; x[b[i].point1][b[i].point1]--;
        x[b[i].point2][b[i].point1]++; x[b[i].point2][b[i].point2]--;
    }
    memset(x[1],0x00,sizeof x[1]); x[1][1]=1;
    memset(x[n],0x00,sizeof x[n]); x[n][0]=1; x[n][n]=1;
//  for (int i=1;i<=n;i++){
//      for (int j=1;j<=n;j++) printf("%.4lf ",x[i][j]); cout<<endl;}
//  cout<<endl;
    doit(); 
//  for (int i=1;i<=n;i++){
//      for (int j=1;j<=n;j++) printf("%.4lf ",x[i][j]); cout<<endl;}
    find(n); double num=1e15;
//  for (int i=1;i<=n;i++) cout<<d[i]<<" "; cout<<endl;
    for (int i=1;i<=m;i++) if (fabs(d[b[i].point1]-d[b[i].point2])>1e-8) num=min(num,abs(b[i].w/(d[b[i].point1]-d[b[i].point2])));
    double ans=0; for (int i=1;i<=n;i++) d[i]=d[i]*num;
    for (int i=1;i<=m;i++) if (b[i].point1==n) ans-=d[b[i].point2]-d[b[i].point1];
    for (int i=1;i<=m;i++) if (b[i].point2==n) ans+=d[b[i].point2]-d[b[i].point1];
    if (ans<0){
        ans=0; for (int i=1;i<=n;i++) d[i]=0;
    }
    printf("%.11lf\n",ans);
    for (int i=1;i<=m;i++) printf("%.11lf\n",d[b[i].point2]-d[b[i].point1]);
    return 0;
}