#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001][1001],b[1001][1001],c[1001][1001],e[1001][1001],x[1001][1001],n,m,k,l[1001][1001],r[1001][1001],u[1001][1001],d[1001][1001];
long long f[1001][1001];
int main(){
    scanf("%d%d%d",&n,&m,&k); for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&x[i][j]);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=(a[i-1][j-1]+x[i][j]);
    for (int i=n;i;i--) for (int j=1;j<=m;j++) b[i][j]=(b[i+1][j-1]+x[i][j]);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) c[i][j]=(c[i][j-1]+x[i][j]);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) e[i][j]=(e[i-1][j]+x[i][j]);
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++)
            if (j==k){
                if (i==k)
                    for (int k1=1;k1<=i;k1++)
                        for (int k2=1;k2<=m;k2++){if (abs(k1-i)+abs(k2-j)<k) u[i][j]+=x[k1][k2];}
                else u[i][j]=u[i-1][j]+c[i][j+k-1]-c[i][j-k]-(a[i-1][j+k-1]-a[i-k][j])-(b[i-k][j]-b[i][j-k]);
            } else u[i][j]=u[i][j-1]-a[i-k][j-1]+a[i][j+k-1]-(b[i-k+1][j-1]-b[i+1][j-k-1]);
    for (int i=n-k+1;i>=k;i--)
        for (int j=k;j<=m-k+1;j++)
            if (j==k){
                if (i==n-k+1)
                    for (int k1=n;k1>=i;k1--)
                        for (int k2=1;k2<=m;k2++){if (abs(k1-i)+abs(k2-j)<k) d[i][j]+=x[k1][k2];}
                else d[i][j]=d[i+1][j]+c[i][j+k-1]-c[i][j-k]-(a[i+k][j]-a[i][j-k])-(b[i+1][j+k-1]-b[i+k][j]);
            } else d[i][j]=d[i][j-1]-(a[i+k-1][j-1]-a[i-1][j-1-k])+(b[i][j+k-1]-b[i+k][j-1]);
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++)
            if (j==k){
                if (i==k)
                    for (int k1=1;k1<=n;k1++)
                        for (int k2=1;k2<=j;k2++){if (abs(k1-i)+abs(k2-j)<k) l[i][j]+=x[k1][k2];}
                else l[i][j]=l[i-1][j]-(b[i-k][j]-b[i][j-k])+(a[i+k-1][j]-a[i-1][j-k]);
            } else l[i][j]=l[i][j-1]+e[i+k-1][j]-e[i-k][j]-(b[i-k+1][j-1]-b[i][j-k])-(a[i+k-1][j-1]-a[i-1][j-k-1]);
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++)
            if (j==k){
                if (i==k)
                    for (int k1=1;k1<=n;k1++)
                        for (int k2=i;k2<=m;k2++){if (abs(k1-i)+abs(k2-j)<k) r[i][j]+=x[k1][k2];}
                else r[i][j]=r[i-1][j]-(a[i-1][j+k-1]-a[i-k-1][j-1])+(b[i][j+k-1]-b[i+k][j-1]);
            } else r[i][j]=r[i][j-1]-(e[i+k-1][j-1]-e[i-k][j-1])+a[i][j+k-1]-a[i-k][j-1]+b[i+1][j+k-2]-b[i+k][j-1]; 
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++)
            if (j==k){
                if (i==k)
                    for (int k1=1;k1<=n;k1++)
                        for (int k2=1;k2<=m;k2++) {f[i][j]+=1ll*max(0,k-abs(k1-i)-abs(k2-j))*x[k1][k2];}
                else f[i][j]=f[i-1][j]-u[i-1][j]+d[i][j];
            } else f[i][j]=f[i][j-1]-l[i][j-1]+r[i][j];
    int num1=0,num2=0; long long ans=-1e10;
    for (int i=k;i<=n-k+1;i++)
        for (int j=k;j<=m-k+1;j++)
            if (ans<f[i][j]){ans=f[i][j]; num1=i; num2=j;}
    cout<<num1<<" "<<num2<<endl; return 0;
}