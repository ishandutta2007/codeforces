#include<bits/stdc++.h>
using namespace std;
int a[101][101][11];
int main()
{
    int n,q,c;
    scanf("%d%d%d",&n,&q,&c);
    while(n--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y][z]++;
    }
    for(int i=1;i<=100;i++)
        for(int j=2;j<=100;j++)
            for(int k=0;k<=c;k++) a[i][j][k]+=a[i][j-1][k];
    for(int i=1;i<=100;i++)
        for(int j=2;j<=100;j++)
            for(int k=0;k<=c;k++) a[j][i][k]+=a[j-1][i][k];
    while(q--)
    {
        int t,x,y,xx,yy,ans=0;
        scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
        for(int i=0;i<=c;i++)
            ans+=(i+t)%(c+1)*(a[xx][yy][i]-a[xx][y-1][i]-a[x-1][yy][i]+a[x-1][y-1][i]);
        printf("%d\n",ans);
    }
}