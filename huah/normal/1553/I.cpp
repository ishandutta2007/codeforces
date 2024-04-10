#include <bits/stdc++.h>
#include<windows.h>
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
const int N=2e5+5,mod=998244353,G=3,Gi=332748118;
ll inv[N],f[N],invf[N];
namespace Polynomial 
{
    using Poly = std::vector<int>;
    constexpr int P(998244353),G(3);
    inline void inc(int &x, int y) { (x+=y)>=P?x-=P:0;}
    inline int sum(int x,int y){return x+y>=P?x+y-P:x+y;}
    inline int sub(int x,int y){return x<y?x-y+P:x-y;}
    inline int fpow(int x,int k=P-2)
    {
        int r=1;
        for(;k;k>>=1,x=1ll*x*x%P)
            if(k&1) r=1ll*r*x%P;
        return r;
    }
    std::vector<int> w;
    void getOmega(int k)
    {
        w.resize(k);
        w[0]=1;
        int base=fpow(G,(P-1)/(k << 1));
        for(int i=1;i<k;i++) w[i]=1LL*w[i-1]*base%P;
    }
    void dft(int *a,int n) 
    {
        assert((n&n-1)==0);
        for(int k=n>>1;k;k>>=1) 
        {
            getOmega(k);
            for(int i=0;i<n;i+=k<<1) 
                for (int j=0;j<k;j++) 
                {
                    int y=a[i+j+k];
                    a[i+j+k]=(1ll*a[i+j]-y+P)*w[j]%P;
                    inc(a[i+j],y);
                }
        }
    }
    void dft(Poly &a) {dft(a.data(),a.size());}
    void idft(int *a,int n) 
    {
        assert((n&n-1)==0);
        for (int k=1;k<n;k<<=1) 
        {
            getOmega(k);
            for(int i=0;i<n;i+=k<<1)
            for(int j=0;j<k;j++) 
            {
                int x=a[i+j],y=1ll*a[i+j+k]*w[j]%P;
                a[i+j]=sum(x,y),a[i+j+k]=sub(x,y);
            }
        }
        for (int i=0,inv=P-(P-1)/n;i<n;i++)
            a[i]=1ll*a[i]*inv%P;
        std::reverse(a+1,a+n);
    }
    void idft(Poly &a) {idft(a.data(), a.size());}
    Poly operator*(Poly a, Poly b) 
    {
        int len=a.size()+b.size()-1;
        if (a.size()<=8||b.size()<=8) 
        {
            Poly c(len);
            for (size_t i=0;i<a.size();i++)
            for (size_t j=0;j<b.size();j++)
                c[i+j]=(c[i+j]+1ll*a[i]*b[j])%P;
            return c;
        }
        int n=1<<std::__lg(len-1)+1;
        a.resize(n),b.resize(n);
        dft(a),dft(b);
        for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%P;
        idft(a);
        a.resize(len);
        return a;
    }
    Poly operator+(Poly a, Poly b) 
    {
        a.resize(std::max(a.size(),b.size()));
        for (int i=0;i<b.size();i++) inc(a[i],b[i]);
        return a;
    }
    Poly operator*(Poly a, int x) 
    {
        for(int i=0;i<a.size();i++) a[i]=1ll*a[i]*x%P;
        return a;
    }
    Poly operator-(Poly a, Poly b) 
    {
        a.resize(std::max(a.size(), b.size()));
        for (int i=0;i<b.size();i++) inc(a[i],P-b[i]);
        return a;
    }
    Poly shift(Poly a, int x) 
    {
        if(x<0) 
            return -x>a.size()?Poly():Poly(a.begin()-x,a.end());
        a.insert(a.begin(),x,0);
        return a;
    }
    Poly polyInv(Poly &a,int n)
    {
        if(n==1) {Poly b(1);b[0]=fpow(a[0],P-2);return b;}
        Poly b=polyInv(a,(n+1)/2);
        Poly c=Poly(a.begin(),a.begin()+std::min(n,int(a.size())));
        int len=1;
        while(len<n<<1) len<<=1;
        b.resize(len);c.resize(len);
        dft(b);dft(c);
        for(int i=0;i<len;i++) b[i]=(2+P-1ll*b[i]*c[i]%P)%P*b[i]%P;
        idft(b);
        b.resize(n);
        return b;
    }
    void Derivation(Poly &a)
    {
        if(a.size()==0) return;
        for(int i=0;i+1<a.size();i++)
            a[i]=1ll*a[i+1]*(i+1)%P;
        a.pop_back();
    }
    void Integral(Poly &a)
    {
        for(int i=0;i<a.size();i++)
            a[i]=1ll*a[i]*inv[i+1]%P;
        a.insert(a.begin(),0);
    }
    void polyIn(Poly &a,int n)
    {
        Poly b=polyInv(a,n);
        Derivation(a);
        a.resize(n);
        a=a*b;
        Integral(a);
        a.resize(n);
    }
    Poly polyExp(Poly a,int n)
    {
        if(n==1){Poly b;b.push_back(1);return b;}
        Poly b=polyExp(a,(n+1)/2);
        Poly c=b;
        // rep(i,0,n-1) e[i]=b[i];
        polyIn(b,n);
        for(int i=0;i<b.size();i++) b[i]=((i==0)+P-b[i]+a[i])%P;
        b=b*c;
        b.resize(n);
        return b;
    }
    Poly polyPow(Poly &a,int n,int k,int phik,bool flag=false)
    {
        ll s=0;
        while(s<n&&a[s]==0) s++;
        if(s==n) return a;
        a=shift(a,-s);
        a.resize(n);
        int g=a[0];
        ll invg=fpow(g,P-2);
        for(int i=0;i<n;i++) a[i]=a[i]*invg%P;
        polyIn(a,n);
        for(int i=0;i<n;i++) a[i]=1ll*a[i]*k%P;
        Poly b=polyExp(a,n);
        g=fpow(g,phik);
        for(int i=0;i<n;i++) b[i]=1ll*b[i]*g%P;
        s*=k+(flag?P:0);
        for(int i=n-1;i>=0;i--) b[i]=i-s>=0?b[i-s]:0;
        return b;
    }
}  // namespace Polynomial
using namespace Polynomial;
void init()
{
  f[0]=f[1]=invf[0]=invf[1]=inv[1]=1;
  rep(i,2,N-1) f[i]=f[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod,invf[i]=invf[i-1]*inv[i]%mod;
}
char s[N];
int n,m,a[N],b[N];
Poly p[N<<1][2][2];
void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
struct node
{
  Poly a[2][2];
};
node cal(int l,int r)
{
  if(r-l+1<=3)
  {
    node ans;
    assert(l!=r);
    if(l+1==r)
    {
      ans.a[0][0].resize(2);
      add(ans.a[0][0][1],2);
      ans.a[b[l]==1][b[r]==1].resize(3);
      add(ans.a[b[l]==1][b[r]==1][2],b[l]*b[r]);
    }
    if(l+2==r)
    {
      ans.a[0][0].resize(2);
      add(ans.a[0][0][1],2);
      ans.a[0][b[r]==1].resize(3);
      add(ans.a[0][b[r]==1][2],2*b[r]);
      ans.a[b[l]==1][0].resize(3);
      add(ans.a[b[l]==1][0][2],2*b[l]);
      ans.a[b[l]==1][b[r]==1].resize(4);
      add(ans.a[b[l]==1][b[r]==1][3],b[l]*b[l+1]*b[r]);
    }
    return ans;
  }
  node ans;
  int m=(l+r)>>1;
  node x=cal(l,m);
  node y=cal(m+1,r);
  for(int l1=0;l1<=1;l1++)
    for(int r2=0;r2<=1;r2++)
    {
      int lx=max(x.a[l1][0].size(),x.a[l1][1].size())-1;
      int ly=max(y.a[0][r2].size(),y.a[1][r2].size())-1;
      if(lx<0||ly<0) continue;
      ans.a[l1][r2]=ans.a[l1][r2]+(x.a[l1][0]+x.a[l1][1])*(y.a[0][r2]+y.a[1][r2]);
      ans.a[l1][r2]=ans.a[l1][r2]+shift((x.a[l1][0]+x.a[l1][1]*2)*(y.a[0][r2]+y.a[1][r2]*2),-1)*inv[2];
    }
  return ans;
}
int main() 
{
  // DWORD begin=GetTickCount(),end;
  init();
  sc(n);rep(i,1,n) sc(a[i]);
  rep(i,1,n)
  {
    int j=i+a[i]-1;
    if(j>n)
    {
      out(0);return 0;
    }
    rep(k,i+1,j)
    if(a[k]!=a[i])
    {
      out(0);return 0;
    }
    b[++m]=min(a[i],2);
    i=j;
  }
  if(m==1)
  {
    out(1);return 0;
  }
  node ans=cal(1,m);
  ll res=0;
  rep(tl,0,1)
    rep(tr,0,1)
    for(int i=1;i<ans.a[tl][tr].size();i++)
    res=(res+1ll*ans.a[tl][tr][i]*f[i]%mod*(((m-i)&1)?-1:1))%mod;
  res=(res+mod)%mod;
  out(res);
  // end=GetTickCount();cout<<(end-begin)<<"ms"<<endl;
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/