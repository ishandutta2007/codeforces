#include <bits/stdc++.h>
using namespace std;

const int MAX=505;

char a[MAX][MAX];
int f[MAX][MAX];

int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    for (int i=0;i<=w;i++) a[0][i]='#';
    for (int i=1;i<=h;i++) a[i][0]='#';
    for (int i=1;i<=h;i++) scanf("%s",a[i]+1);
    for (int i=1;i<=h;i++)
        for (int j=1;j<=w;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            if (a[i][j]=='.')
            {
                if (a[i-1][j]=='.') f[i][j]++;
                if (a[i][j-1]=='.') f[i][j]++;
            }
        }
    int q;
    scanf("%d",&q);
    for (int r1,c1,r2,c2;q--;)
    {
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        int ans=f[r2][c2]-f[r1-1][c2]-f[r2][c1-1]+f[r1-1][c1-1];
        for (int j=c1;j<=c2;j++)
            if (a[r1][j]=='.'&&a[r1-1][j]=='.') ans--;
        for (int j=r1;j<=r2;j++)
            if (a[j][c1]=='.'&&a[j][c1-1]=='.') ans--;
        printf("%d\n",ans);
    }
    return 0;
}