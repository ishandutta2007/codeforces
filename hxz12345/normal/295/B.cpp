#include<bits/stdc++.h>
using namespace std;
int w,T,n,i,j,ans;
long long sum;
int f[10000],e[10000],x;
long long  b[1000][1000],a[1000][1000],g[10000];
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            cin>>a[i][j];
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
             b[i][j]=1000000000000;
    for (i=1;i<=n;i++) cin>>e[i];
    for (T=n;T>=1;T--)
        {
        x=e[T];
        for (i=1;i<=w;i++)
           for (j=1;j<=w;j++)
               b[x][f[j]]=min(b[x][f[j]],a[x][f[i]]+b[f[i]][f[j]]);
        for (i=1;i<=w;i++)
           for (j=1;j<=w;j++)
               b[f[j]][x]=min(b[f[j]][x],b[f[j]][f[i]]+a[f[i]][x]);
        for (i=1;i<=w;i++)
           for (j=1;j<=w;j++)
               b[f[i]][f[j]]=min(b[f[i]][f[j]],b[f[i]][x]+b[x][f[j]]);
        b[x][x]=0;
        w++;f[w]=x;
        sum=0;
        for (i=1;i<=w;i++)
           for (j=1;j<=w;j++)
              sum+=b[f[i]][f[j]];
        g[T]=sum;
        }
for (i=1;i<=n;i++) cout<<g[i]<<" ";
cout<<endl;
    return 0;
}