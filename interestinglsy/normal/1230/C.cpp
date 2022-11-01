#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=10;
const int M=55;

int n,m,ans;
int ex[M],ey[M],col[N];
bool vis[N][N];

int calc()
{
    int sum=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=m;++i)
    {
        if(vis[col[ex[i]]][col[ey[i]]]) continue;
        vis[col[ex[i]]][col[ey[i]]]=vis[col[ey[i]]][col[ex[i]]]=true,sum++;
    }
    return sum;
}
void dfs(int x)
{
    if(x>n)
    {
        ans=max(ans,calc());
        return;
    }
    for(int i=1;i<=6;++i)
    {
        col[x]=i;
        dfs(x+1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d%d",&ex[i],&ey[i]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}