#include<bits/stdc++.h>
typedef unsigned long long ull;
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
const int N=2e5+5,mod=998244353;
int n,m,p;
char s[N][66];
int a[N];
int vis[1<<15];
int bit[1<<15];
int ans=0;
vector<int>res;
void cal(int id)
{
    memset(vis,0,sizeof(vis));
    vector<int>v;
    for(int i=0;i<m;i++)
        if(s[id][i]=='1') v.push_back(i);
    int up=(1<<v.size())-1;
    for(int i=1;i<=n;i++)
    {
        int res=0;
        for(int j=0;j<v.size();j++)
            if(s[i][v[j]]=='1') res|=1<<j;
        vis[res]++;
    }
    for(int i=0;i<=up;i++)
    {
        int x=up^i;
        for(int j=x;j;j=(j-1)&x)
            vis[i]+=vis[j^i];
        if(vis[i]>=(n+1)/2&&bit[i]>ans)
        {
            ans=bit[i];
            res.clear();
            for(int j=0;j<v.size();j++)
                if(i>>j&1) res.push_back(v[j]);
        }
    }
}
int main()
{
    srand(time(0));
    for(int i=1;i<1<<15;i++)
        bit[i]=bit[i^(i&-i)]+1;
    sc(n,m,p);
    rep(i,1,n) sc(s[i]);
    rep(i,1,n) a[i]=i;
    random_shuffle(a+1,a+1+n);
    random_shuffle(a+1,a+1+n);
    random_shuffle(a+1,a+1+n);
    rep(i,1,min(10,n)) cal(a[i]);
    int ans[88];
    memset(ans,0,sizeof(ans));
    for(int x:res) ans[x]=1;
    for(int i=0;i<m;i++) printf("%d",ans[i]);
    putchar('\n');
}