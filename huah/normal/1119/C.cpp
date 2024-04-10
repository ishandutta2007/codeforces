#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,y=0,a[505][505],b[505][505];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&b[i][j]);
    bool flag=true;
    for(int i=1;i<=n&&flag;i++)
        for(int j=1;j<=m&&flag;j++)
    {
        if(a[i][j]!=b[i][j])
        {
            if(i==n||j==m) {flag=false;break;}
            a[i][j]^=1;a[i+1][j]^=1;
            a[i][j+1]^=1;a[i+1][j+1]^=1;
        }
    }
    printf(flag?"Yes":"No");
}