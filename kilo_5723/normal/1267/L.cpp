#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m,k;
char s[1000010],a[1010][1010];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s",s+1);
    sort(s+1,s+1+n*m);
    int l=1,p=1;
    memset(a,0,sizeof(a));
    for (int i=1;i<=m;i++)
    {
        for (int j=l;j<=k;j++)
            a[j][i]=s[p],p++;
        for (int j=k;j>=1;j--)
            if (a[k][i]!=a[j][i]) {l=j+1;break;}
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]==0) a[i][j]=s[p],p++;
    for (int i=1;i<=n;i++,puts(""))
        for (int j=1;j<=m;j++)
            putchar(a[i][j]);
    return 0;
}