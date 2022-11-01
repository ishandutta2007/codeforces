#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
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
const int N=1e2+5,mod=1e9+7;
int n,m;
char s[N][N];
int vis[2];
int main()
{

    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n,m);
        rep(i,1,n) sc(s[i]+1);
        memset(vis,0,sizeof(vis));
        rep(i,1,n)
            rep(j,1,m)
            if(s[i][j]=='R') vis[(i+j)&1]|=1;
            else if(s[i][j]=='W') vis[(i+j)&1]|=2;
        if(vis[0]==3||vis[1]==3||vis[0]==vis[1]&&vis[0])
            printf("NO\n");
        else if(!vis[0]&&!vis[1])
        {
            printf("YES\n");
            rep(i,1,n)
            {
                rep(j,1,m)
                {
                    putchar(((i+j)&1)?'W':'R');
                }
                putchar('\n');
            }
        }
        else
        {
            if(vis[0]==0)
            {
                if(vis[1]==1) vis[0]=2;
                else vis[0]=1;
            }
            else if(vis[0]==1) vis[1]=2;
            else vis[1]=1;
            printf("YES\n");
            rep(i,1,n)
            {
                rep(j,1,m)
                {
                    putchar(vis[(i+j)&1]==1?'R':'W');
                }
                putchar('\n');
            }
        }
    }
}