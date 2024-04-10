#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=1005;
char s[N][N],e[N][N];
bool vis[N][N],vv[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n,m,t,si,tot=1,id[N][N],dp[N*N];
vector<int>v[N];
void dfs(int x,int y)
{
    si++;vis[x][y]=id[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int xx=dx[i]+x,yy=dy[i]+y;
        if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]!=s[x][y]||vis[xx][yy]) continue;
        dfs(xx,yy);
    }
}
void Dp(int nn,int mm,int dx,int dy)
{
    dp[1]=0;
    for(int i=nn;i>=1&&i<=n;i-=dx)
        for(int j=mm;j>=1&&j<=m;j-=dy)
    {
        if(i+dx>=1&&i+dx<=n)
            dp[id[i][j]]=min(dp[id[i][j]],dp[id[i+dx][j]]+1);
        if(j+dy>=1&&j+dy<=m)
            dp[id[i][j]]=min(dp[id[i][j]],dp[id[i][j+dy]]+1);
    }
}
void tran()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        bool flag=false;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(i==4&&j==1) cout<<x<<' '<<y<<endl;
            if(x<1||x>n||y<1||y>m) continue;
            if(s[x][y]==s[i][j]) flag=true;
        }
        if(!flag) e[i][j]=s[i][j],vv[i][j]=0;
        else e[i][j]=s[i][j]=='1'?'0':'1',vv[i][j]=1;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) s[i][j]=e[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(vv[i][j]) cout<<"?";
            else cout<<s[i][j];
            if(j==m) cout<<endl;
        }
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(!vis[i][j])
        {
            si=0;
            dfs(i,j);
            if(si==1) id[i][j]=++tot;
        }
    //tran();tran();tran();tran();
    //return 0;
    memset(dp,inf,sizeof(dp));
    Dp(1,1,-1,-1);
    Dp(1,m,-1,1);
    Dp(n,1,1,-1);
    Dp(n,m,1,1);
    for(int i=1;i<=t;i++)
    {
        int x,y;ll k;
        scanf("%d%d%lld",&x,&y,&k);
        int f=dp[id[x][y]];
        if(f==inf||k<=f) printf("%c\n",s[x][y]);
        else
        {
            k-=f;
            if(k&1) printf("%c\n",s[x][y]=='0'?'1':'0');
            else printf("%c\n",s[x][y]);
        }
    }
}