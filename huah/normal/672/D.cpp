#pragma GCC optimize(2)
#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define nep(i,r,l) for(int i=r;i>=l;--i)
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
const int N=5e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
int n,k;
static char pbuf[1<<16],*p1=pbuf,*p2=pbuf,obuf[1<<16],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1<<16,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1<<16)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr()
{
    int in=0;bool f=false;char ch;
    while(!isdigit(ch=getchar()))f|=(ch=='-');
    do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
    return f?-in:in;
}
template<class T>
void qw(T out)
{
    if(out>9)qw(out/10);
    putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    n=qr();k=qr();
    ll sum=0;
    rep(i,1,n) a[i]=qr(),sum+=a[i];
    sort(a+1,a+1+n);
    int flag=sum%n!=0;
    sum=sum/n;
    ll s=0;
    rep(i,1,n) if(a[i]>sum) s+=a[i]-sum;
    if(k>=s)
    {
        sum=0;
        rep(i,1,n) sum+=a[i];
        out(sum%n!=0);
        return 0;
    }
    s=0;
    nep(i,n,1)
    if(s+1ll*(a[i]-max(1ll*a[i-1],sum))*(n-i+1)<=k) s+=1ll*(a[i]-max(1ll*a[i-1],sum))*(n-i+1);
    else
    {
        int t=(k-s)/(n-i+1);
        s+=t*(n-i+1);
        for(int j=n;j>=i;--j) a[j]=a[i]-t;
        for(int j=i;j<=i+(k-s)-1;++j) a[j]-=1;
        break;
    }
    s=0;
    sum+=flag;
    rep(i,1,n)
    if(s+1ll*(min(sum,1ll*a[i+1])-a[i])*i<=k) s+=1ll*(min(sum,1ll*a[i+1])-a[i])*i;
    else
    {
        int t=(k-s)/i;
        s+=t*i;
        for(int j=1;j<=i;++j) a[j]=a[i]+t;
        for(int j=i-(k-s)+1;j<=i;++j) a[j]+=1;
        break;
    }
    out(a[n]-a[1]);
}