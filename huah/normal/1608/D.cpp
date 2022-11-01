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
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e5+5,mod=998244353;
string s[N];
int n;
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
    Poly shift(Poly a, int x) 
    {
        if(x<0) 
            return -x>a.size()?Poly():Poly(a.begin()-x,a.end());
        a.insert(a.begin(),x,0);
        return a;
    }
}  // namespace Polynomial
using namespace Polynomial;
Poly cal(int l,int r)
{
  if(l==r)
  {
    Poly ans(3);
    if(s[l]=="??") ans[1]=2,ans[0]=ans[2]=1;
    else if(s[l]=="BB") ans[0]=1;
    else if(s[l]=="WW") ans[2]=1;
    else if(s[l]=="WB"||s[l]=="BW") ans[1]=1;
    else if(s[l][0]=='W'||s[l][1]=='W') ans[1]=ans[2]=1;
    else ans[0]=ans[1]=1;
    return ans;
  }
  int m=(l+r)>>1;
  return cal(l,m)*cal(m+1,r);
}
int getres()
{
  int ans=1;
  rep(i,1,n)
    if(s[i]=="??") ans=ans*2%mod;
    else if(s[i]=="BB"||s[i]=="WW") return 0;
  return ans;
}
int getans()
{
  int ans=cal(1,n)[n];
  ans=(ans+mod-getres())%mod;
  return ans;
}
int cal(string t)
{
  rep(i,1,n)
  {
    rep(j,0,1)
    if(s[i][j]!='?'&&s[i][j]!=t[j]) return 0;
  }
  return 1;
}
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out", "w", stdout);
  // n=100000;
  // rep(i,1,n) s[i]="??";
  cin>>n;
  rep(i,1,n) cin>>s[i];
  out((getans()+cal("BW")+cal("WB"))%mod);
}