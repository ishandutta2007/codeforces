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
const int N=1e5+5,mod=998244353;
int n,m,L[N],R[N],l[N],r[N],f[N];
int dp[51][N];
void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
int cal(int m)
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
    {
        if(i&&j) add(dp[i][j],dp[i][j-1]);
        if(i+1<=n)
        {
            if(j+l[i+1]<=m)
                add(dp[i+1][j+l[i+1]],dp[i][j]);
            if(j+r[i+1]+1<=m)
                add(dp[i+1][j+r[i+1]+1],mod-dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++) add(ans,dp[n][i]);
    return ans;
}
int main() 
{
    sc(n,m);
    rep(i,1,n) sc(L[i],R[i]);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            l[j]=L[j]/i+(L[j]%i!=0);
            r[j]=R[j]/i;
        }
        f[i]=cal(m/i);
    }
    for(int i=m;i>=1;i--)
        for(int j=i+i;j<=m;j+=i)
        add(f[i],mod-f[j]);
    printf("%d\n",f[1]);
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/