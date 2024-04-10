#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,g[405][405],i,j,k;
bool f;
char a[25],b[25];
int main()
{
    //freopen("475B.in","r",stdin);
    //freopen("475B.out","w",stdout);
    scanf("%d%d%s%s",&n,&m,a,b);
    for(i=0;i<n;i++)for(j=0;j+1<m;j++)if(a[i]=='<')g[i*m+j+1][i*m+j]=1;
    else g[i*m+j][i*m+j+1]=1;
    for(i=0;i<m;i++)for(j=0;j+1<n;j++)if(b[i]=='v')g[j*m+i][j*m+i+m]=1;
    else g[j*m+i+m][j*m+i]=1;
    n*=m;
    for(i=0;i<n;i++)g[i][i]=1;
    for(k=0;k<n;k++)for(i=0;i<n;i++)for(j=0;j<n;j++)g[i][j]|=(g[i][k]&g[k][j]);
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(!g[i][j])f=1;
    if(f)printf("NO");
    else printf("YES");
    return 0;
}