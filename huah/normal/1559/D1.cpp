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
const int N=5e5+5,mod=1e9+7,G=3,Gi=332748118;
char s[N];
int f1[N],f2[N];
int getf(int x,int *f){return f[x]==x?x:f[x]=getf(f[x],f);}
int n,m1,m2;
int main() 
{
    sc(n,m1,m2);
    rep(i,1,n) f1[i]=f2[i]=i;
    while(m1--)
    {
        int u,v;sc(u,v);
        u=getf(u,f1);
        v=getf(v,f1);
        if(u!=v) f1[u]=v;
    }
    while(m2--)
    {
        int u,v;sc(u,v);
        u=getf(u,f2);
        v=getf(v,f2);
        if(u!=v) f2[u]=v;
    }
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(getf(i,f1)!=getf(j,f1)&&getf(i,f2)!=getf(j,f2))
        {
            ans.push_back({i,j});
            f1[getf(i,f1)]=getf(j,f1);
            f2[getf(i,f2)]=getf(j,f2);
        }
    printf("%d\n",int(ans.size()));
    for(pair<int,int>&x:ans)
        printf("%d %d\n",x.first,x.second);
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/