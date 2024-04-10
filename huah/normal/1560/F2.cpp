#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=1e5+5,mod=1e9+7;
bool judge(int n,int k)
{
    bool vis[10];memset(vis,false,sizeof(vis));
    while(n) vis[n%10]=true,n/=10;
    int ans=0;
    rep(i,0,9) ans+=vis[i];
    return ans<=k;
}
void sol(int cas)
{
    int n,m,k;sc(n,k);
    if(judge(n,k))
    {
        out(n);return;
    }
    int tot=0,num[20];
    m=n;
    while(n)
    {
        num[++tot]=n%10;
        n/=10;
    }
    int st[20];
    st[tot+1]=0;
    for(int i=tot;i>=1;i--) st[i]=st[i+1]|(1<<num[i]);
    for(int i=1;i<=tot;i++)
    {
        int x=num[i];
        for(int j=x+1;j<=9;j++)
        {
            int s=st[i+1]|(1<<j);
            if(__builtin_popcount(s)<=k)
            {
                int g=0;
                for(int h=0;h<=9;h++)
                    if(__builtin_popcount(s|(1<<h))<=k)
                    {
                        g=h;break;
                    }
                for(int k=tot;k>i;k--)
                    putchar(num[k]+'0');
                putchar(j+'0');
                for(int k=i-1;k>=1;k--) putchar(g+'0');
                putchar('\n');
                return;
            }
        }
    }
}
int main()
{
    // freopen("1.in","r",stdin);
    srand(time(0));
    int t=1,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        sol(++cas);
    }
}