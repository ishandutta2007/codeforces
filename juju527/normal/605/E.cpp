#include<bits/stdc++.h>
#define db double
using namespace std;
const int maxn=1005;
db p[maxn][maxn];
bool vis[maxn];
int a[maxn];
db pr[maxn];
db f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    n=read();
    if(n==1){puts("0");return 0;}
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)p[i][j]=1.0*read()/100;
    for(int i=1;i<=n;i++)f[i]=1,pr[i]=1;
    f[0]=1e9;
    f[n]=0;
    a[1]=n;vis[n]=1;
    for(int i=1;i<=n;i++){
        int x=a[i],y=0;
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            if(i>1)f[j]=f[j]+f[x]/(1-pr[x])*p[j][x]*pr[j];
            pr[j]*=(1-p[j][x]);
            if(f[j]/(1-pr[j])<f[y]/(1-pr[y]))y=j;
        }
        if(y==1)break;
        vis[y]=1;
        a[i+1]=y;
    }
    printf("%.10lf\n",f[1]/(1-pr[1]));
    return 0;
}