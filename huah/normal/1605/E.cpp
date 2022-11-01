#pragma GCC optimize(2)
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
const int N=1e6+5,mod=998244353;
#define inf 0x3f3f3f3f
int n,u[N];
int tot,p[N];
bool vis[N];
ll a[N],b[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    u[1]=1;
    for(int i=1;i<=1000000;i++)
        for(int j=i+i;j<=1000000;j+=i)
        u[j]-=u[i];
    sc(n);
    rep(i,1,n) sc(a[i]);
    rep(i,1,n) sc(b[i]);
    rep(i,2,n) a[i]=b[i]-a[i];
    rep(i,2,n)
        for(int j=i+i;j<=n;j+=i) a[j]-=a[i];
    ll ans=0;
    vector<ll>v1(n+5),v2(n+5),p1(n+5),p2(n+5);
    int l1=0,l2=0;
    rep(i,2,n)
        if(u[i]==0) ans+=abs(a[i]);
        else if(u[i]==-1)
            v1[++l1]=a[i];
        else v2[++l2]=a[i];
    sort(v1.begin()+1,v1.begin()+1+l1);
    sort(v2.begin()+1,v2.begin()+1+l2);
    rep(i,1,l1) p1[i]=p1[i-1]+v1[i];
    rep(i,1,l2) p2[i]=p2[i-1]+v2[i];
    int q;sc(q);
    while(q--)
    {
        ll x;sc(x);
        x=x-a[1];
        ll res=ans+abs(x);
        //v1[i]-x>=0  v1[i]>=x
        //v2[i]>=-x;
        //v1[i]-x v2[i]+x
        int pos=lower_bound(v1.begin()+1,v1.begin()+1+l1,x)-v1.begin();
        res+=(p1[l1]-p1[pos-1]-x*(l1-pos+1))-(p1[pos-1]-x*(pos-1));
        pos=lower_bound(v2.begin()+1,v2.begin()+1+l2,-x)-v2.begin();
        res+=(p2[l2]-p2[pos-1]+x*(l2-pos+1))-(p2[pos-1]+x*(pos-1));
        out(res);
    }
}