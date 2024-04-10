#include<bits/stdc++.h>
using namespace std;
char s[505][505];
int r[505][505],c[505][505];
int main()
{
    int h,w,q;
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(s[i][j]=='.')
            {
                if(s[i][j-1]=='.') r[i][j]=1;
                if(s[i-1][j]=='.') c[i][j]=1;
            }
            r[i][j]+=r[i][j-1];
            c[i][j]+=c[i-1][j];
        }
    scanf("%d",&q);
    while(q--)
    {
        int x,y,ex,ey;
        scanf("%d%d%d%d",&x,&y,&ex,&ey);
        int ans=0;
        for(int i=x;i<=ex;i++) ans+=r[i][ey]-r[i][y];
        for(int i=y;i<=ey;i++) ans+=c[ex][i]-c[x][i];
        printf("%d\n",ans);
    }
}