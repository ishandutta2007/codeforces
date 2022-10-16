#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int d[2][1005][1005],a[1005][1005];
char p[2010];
int main()
{
int n,i,j,k,l,ii,jj;
while(~scanf("%d",&n))
{
    memset(d,INF,sizeof(d));
    d[0][0][1]=d[0][1][0]=d[1][0][1]=d[1][1][0]=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    ii=jj=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
    if(a[i][j]==0){ii=i;jj=j;}
    k=a[i][j];
    d[0][i][j]=0;
    while(a[i][j]&&a[i][j]%2==0){d[0][i][j]++;a[i][j]>>=1;}
    d[0][i][j]+=d[0][i-1][j]<d[0][i][j-1]?d[0][i-1][j]:d[0][i][j-1];
    d[1][i][j]=0;
    while(a[i][j]&&a[i][j]%5==0){d[1][i][j]++;a[i][j]/=5;}
    d[1][i][j]+=d[1][i-1][j]<d[1][i][j-1]?d[1][i-1][j]:d[1][i][j-1];
    a[i][j]=k;
    }
    if(ii&&d[0][n][n]&&d[1][n][n])
    {
    puts("1");
    for(k=1;k<ii;k++)putchar('D');
    for(k=1;k<jj;k++)putchar('R');
    for(k=ii;k<n;k++)putchar('D');
    for(k=jj;k<n;k++)putchar('R');
    puts("");
    continue;
    }
    i=d[1][n][n]<d[0][n][n]?1:0;
    printf("%d\n",d[i][n][n]);
    p[2*n-2]=0;j=k=n;
    for(l=2*n-3;l>=0;l--)
    {
        if(d[i][j-1][k]<d[i][j][k-1])
        {
        p[l]='D';
        j--;
        }
        else
        {
        p[l]='R';
        k--;
        }

    }
    puts(p);
}
}