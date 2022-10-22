#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
int v[maxn],w[maxn];
int f[maxn][maxn];
int u[maxn][maxn],d[maxn][maxn];
int g[maxn];
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
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++)w[i]=read();
    memset(f,0xcf,sizeof(f));
    memset(u,0xcf,sizeof(u));
    memset(d,0xcf,sizeof(d));
    for(int i=1;i<=n;i++)u[i][i]=d[i][i]=0,f[i][i]=v[1];
    for(int s=2;s<=n;s++){
        for(int i=1;i<=n-s+1;i++){
            int j=i+s-1;
            for(int k=i;k<=j;k++){
                if(w[k]==w[j]-1&&w[i]<w[j])u[i][j]=max(u[i][j],u[i][k]+(k+1<=j-1?f[k+1][j-1]:0));
                if(w[k]==w[j]+1&&w[i]>w[j])d[i][j]=max(d[i][j],d[i][k]+(k+1<=j-1?f[k+1][j-1]:0));
            }
            for(int k=i;k<=j;k++){
                int len=w[k]-w[i]+w[k]-w[j]+1;
                if(len>=1&&len<=s&&w[k]>=w[i]&&w[k]>=w[j])f[i][j]=max(f[i][j],u[i][k]+d[k][j]+v[len]);
                if(k<j)f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        g[i]=g[i-1];
        for(int j=0;j<i;j++)g[i]=max(g[i],g[j]+f[j+1][i]);
    }
    printf("%d\n",g[n]);
    return 0;
}