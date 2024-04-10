#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c[55][55];
int n,i,j,m1,m2,m3,m4;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%s",c[i]+1);
    m1=m3=n+1;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i][j]=='4')
    {
        m1=min(m1,i);
        m2=max(m2,i);
        m3=min(m3,j);
        m4=max(m4,j);
    }
    for(i=m1;i<=m2;i++)
    {
        for(j=m3;j<=m4;j++)if(c[i][j]!='4')break;
        if(j<=m4)break;
    }
    if(i<=m2)
    {
        puts("No");
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)if(c[i][j]!='0'&&(i<m1-1||i>m2+1||j<m3-1||j>m4+1))break;
        if(j<=n)break;
    }
    if(i<=n)
    {
        puts("No");
        return 0;
    }
    for(i=m1;i<=m2;i++)if(m3>1&&c[i][m3-1]!='2'||m4<n&&c[i][m4+1]!='2')break;
    if(i<=m2)
    {
        puts("No");
        return 0;
    }
    for(i=m3;i<=m4;i++)if(m1>1&&c[m1-1][i]!='2'||m2<n&&c[m2+1][i]!='2')break;
    if(i<=m4)
    {
        puts("No");
        return 0;
    }
    if(m1>1&&m3>1&&c[m1-1][m3-1]!='1'||m1>1&&m4<n&&c[m1-1][m4+1]!='1'||m2<n&&m3>1&&c[m2+1][m3-1]!='1'||m2<n&&m4<n&&c[m2+1][m4+1]!='1')
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}