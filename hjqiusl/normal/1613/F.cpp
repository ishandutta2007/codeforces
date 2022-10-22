//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}

int n,ru[N];
#define ad(x,y) (x=(x+y)%mod)
namespace bn
{
    #define M 5000005
    int fac[M],inv[M];
    int quickPower(int x,int y)
    {
        int res=1;
        while (y)
        {
            if(y&1)res=res*x%mod;
            x=x*x%mod;
            y>>=1;
        }
        return res;
    }
    int C(int x,int y)
    {
        if (x<y||y<0) return 0;
        return fac[x]*inv[x-y]%mod*inv[y]%mod;
    }
    void Init(int n)
    {
        fac[0]=1;
        for (int i=1;i<=n;i++)
            fac[i]=fac[i-1]*i%mod;
        inv[n]=quickPower(fac[n],mod-2);
        for (int i=n;i>=1;i--)
            inv[i-1]=inv[i]*i%mod;
    }
};
const int g=3,gi=332748118;
namespace Poly
{
    unsigned long long buf[N];
    int rev[N];
    inline int quickPower(int x,int y)
    {
        int res=1;
        while (y)
        {
            if(y&1)res=res*x%mod;
            x=x*x%mod;
            y>>=1;
        }
        return res;
    }
    inline void init(int n)
    {
    }
    inline void NTT(poly &a,int n,int tp)
    {
        for (int i=0;i<n;i++)
            if (i<rev[i]) swap(a[i],a[rev[i]]);
        for (int i=0;i<n;i++) buf[i]=a[i];
        int tt=0;
        for (int i=1;i<n;i<<=1)
        {
            int gg=quickPower((tp)?g:gi,(mod-1)/(i<<1));
            for (int j=0;j<n;j+=(i<<1))
            {
                int gnow=1;
                for (int k=0;k<i;k++,gnow=gnow*gg%mod)
                {
                    int x=buf[j+k],y=buf[j+i+k]%mod*gnow%mod;
                    buf[j+k]=(x+y);
                    buf[i+j+k]=(x-y+mod);
                }
            }
            tt++;
            if (tt%20==0)
            {
                for (int j=0;j<n;j++) buf[j]%=mod;
            }
        }
        for (int j=0;j<n;j++) a[j]=buf[j]%mod;
        if (!tp)
        {
            int nn=bn::inv[n]*bn::fac[n-1]%mod;
            for (int i=0;i<n;i++) a[i]=a[i]*nn%mod;
        }
    }
    inline poly mul(poly a,poly b)
    {
        int n=a.size(),m=b.size();
        int t=1ll<<max((int)ceil(log2(n+m)),1ll);
        // for (int i=1;i<=t-n;i++) a.push_back(0);
        // for (int i=1;i<=t-m;i++) b.push_back(0);
        // for (int i=0;i<t;i++)
            // rev[i]=(rev[i>>1]>>1)|((i&1)<<(max((int)ceil(log2(n+m)),1ll)-1));
        NTT(a,t,1);
        NTT(b,t,1);
        for (int i=0;i<t;i++) a[i]=a[i]*b[i]%mod;
        NTT(a,t,0);
        return a;
    }
    inline int work(poly &a,poly &b)
    {
        int n=a.size(),m=b.size();
        int t=1ll<<max((int)ceil(log2(n+m)),1ll);
        for (int i=1;i<=t-n;i++) a.push_back(0);
        for (int i=1;i<=t-m;i++) b.push_back(0);
        for (int i=0;i<t;i++)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(max((int)ceil(log2(n+m)),1ll)-1));
        return t;
    }
         
};
using namespace Poly;
poly solve(int l,int r)
{
    if (l==r) 
    {
        poly res;
        res.push_back(1);
        res.push_back((mod+ru[l])%mod);
        return res;
    }
    int mid=l+(r-l)/2;
    poly x,y;
    x=solve(l,mid);
    y=solve(mid+1,r);
    int t=work(x,y);
    NTT(x,t,1);
    NTT(y,t,1);
    for (int i=0;i<x.size();i++) x[i]=x[i]*y[i]%mod;
    NTT(x,t,0);
    return x;
}

void BellaKira()
{
    n=read();
    bn::Init(8*n);
    init(8*n);
    for (int i=1;i<n;i++)
    {
        int x=read(),y=read();
        ru[x]++;
        ru[y]++;
    }
    for (int i=2;i<=n;i++) ru[i]--;
    poly now=solve(1,n);
    for (int i=0;i<now.size();i++)
    {
        now[i]=now[i]*bn::fac[n-i]%mod;
    }
    int ans=now[0];
    for (int i=1;i<now.size();i++)
        if (i&1) ans=(ans-now[i]+mod)%mod;
    else ans=(ans+now[i])%mod;
    writeln(ans);
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/