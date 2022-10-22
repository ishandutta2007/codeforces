#include<cstdio>
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
char c[105][105];
int n,m,i,j,ans;
void dfs(int x,int y)
{
    c[x][y]='.';
    for(int i=0;i<4;i++)if(c[x+dx[i]][y+dy[i]]=='B')dfs(x+dx[i],y+dy[i]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",c[i]+1);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(c[i][j]=='B')
    {
        ans++;
        dfs(i,j);
    }
    printf("%d\n",ans);
    return 0;
}