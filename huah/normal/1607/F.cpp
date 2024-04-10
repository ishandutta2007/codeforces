#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2005,mod=1e9+7,bs=320;
#define inf 0x3f3f3f3f
int n,m;
char s[N][N];
pair<int,int>to[N][N];
int d[N][N],ans[N][N];
int top;
pair<int,int>st[N*N];
bool vis[N][N];
int getans(int x,int y)
{
    if(ans[x][y]) return ans[x][y];
    top=0;
    st[++top]={x,y};
    vis[x][y]=true;
    while(!ans[st[top].first][st[top].second])
    {
        pair<int,int>nex=to[st[top].first][st[top].second];
        if(nex.first==0&&nex.second==0)
        {
            for(int i=top;i>=1;i--) ans[st[i].first][st[i].second]=top-i+1;
            break;
        }
        else if(vis[nex.first][nex.second])
        {
            for(int i=top;i>=1;i--)
                if(st[i]==nex)
                {
                    for(int j=i;j<=top;j++) ans[st[j].first][st[j].second]=top-i+1;
                    for(int j=i-1;j>=1;j--) ans[st[j].first][st[j].second]=top-j+1;
                    return ans[x][y];
                }
            for(int i=top;i>=1;i--)
                ans[st[i].first][st[i].second]=top-i+1+ans[nex.first][nex.second];
            return ans[x][y];
        }
        else
        {
            vis[nex.first][nex.second]=true;
            st[++top]=nex;
        }
    }
    return ans[x][y];
}
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        rep(i,1,n) sc(s[i]+1);
        rep(i,1,n) rep(j,1,m) ans[i][j]=vis[i][j]=0;
        rep(i,1,n)
            rep(j,1,m)
            {
                int x=i,y=j;
                if(s[i][j]=='L') y--;
                else if(s[i][j]=='R') y++;
                else if(s[i][j]=='U') x--;
                else x++;
                if(x>=1&&x<=n&&y>=1&&y<=m)
                    to[i][j]={x,y};
                else to[i][j]={0,0};
            }
        int mx=-1,x,y;
        rep(i,1,n)
            rep(j,1,m)
            {
                int res=getans(i,j);
                if(res>mx) mx=res,x=i,y=j;
            }
        out(x,y,mx);
    }
}