// Hydro submission #619390b901410992b68798f6@1637060793845
// Each of you have a good future, however, I can only be the tears.
#include <stdio.h>
#include <vector>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T power(T base,T index,T mod){return((index<=1)?(index?base:1):(power(base*base%mod,index>>1,mod)*power(base,index&1,mod)))%mod;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(!b)return y=0,x=1,a;T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}
template<const ullt p=998244353>
class mod_ullt
{
    private:
        ullt v;
        ullt chg(ullt w){return(w<p)?w:w-p;}
        mod_ullt _chg(ullt w){mod_ullt ans;ans.v=(w<p)?w:w-p;return ans;}
        voi _print(ullt v){if(v>=10)_print(v/10);putchar('0'+v%10);}
    public:
        mod_ullt():v(0){}
        mod_ullt(ullt v):v(v%p){}
        bol empty(){return!v;}
        ullt val(){return v;}
        bol friend operator<(mod_ullt a,mod_ullt b){return a.v<b.v;}
        bol friend operator>(mod_ullt a,mod_ullt b){return a.v>b.v;}
        bol friend operator<=(mod_ullt a,mod_ullt b){return a.v<=b.v;}
        bol friend operator>=(mod_ullt a,mod_ullt b){return a.v>=b.v;}
        bol friend operator==(mod_ullt a,mod_ullt b){return a.v==b.v;}
        bol friend operator!=(mod_ullt a,mod_ullt b){return a.v!=b.v;}
        mod_ullt friend operator+(mod_ullt a,mod_ullt b){return a._chg(a.v+b.v);}
        mod_ullt friend operator-(mod_ullt a,mod_ullt b){return a._chg(a.v+a.chg(p-b.v));}
        mod_ullt friend operator*(mod_ullt a,mod_ullt b){return a.v*b.v;}
        mod_ullt friend operator/(mod_ullt a,mod_ullt b){return b._power(p-2)*a.v;}
        mod_ullt friend operator-(mod_ullt a){return a._chg(p-a.v);}
        mod_ullt sqrt()
        {
            if(power(v,(p-1)>>1,p)!=1)return 0;
            mod_ullt b=1;do b++;while(b._power((p-1)>>1)==1);
            ullt t=p-1,s=0,k=1;while(!(t&1))s++,t>>=1;
            mod_ullt x=_power((t+1)>>1),e=_power(t);
            while(k<s)
            {
                if(e._power(1llu<<(s-k-1))!=1)x*=b._power((1llu<<(k-1))*t);
                e=_power(p-2)*x*x,k++;
            }
            return _min(x,-x),x;
        }
        mod_ullt inv(){return _power(p-2);}
        mod_ullt _power(ullt index){mod_ullt ans(1),w(v);while(index){if(index&1)ans*=w;w*=w,index>>=1;}return ans;}
        voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=(c-'0'+v*10)%p,c=getchar();while(c>='0'&&c<='9');v%=p;}
        voi print(){_print(v);}
        voi println(){_print(v),putchar('\n');}
        mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
    public:
        ullt&operator()(){return v;}
        mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
        mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
        mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
        mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
        mod_ullt&operator++(){return v=chg(v+1),*this;}
};
const ullt Mod=1000000007;
typedef mod_ullt<Mod>modint;
modint A[1000010],B[1000010],Val[1000010],Pre[1000010],Suf[1000010];
std::vector<ullt>P;
modint op(uint t){return(t&1)?modint(Mod-1):modint(1);}
int main()
{
#ifdef MYEE
    freopen("QAQ.out","w",stdout);
#endif
    A[0]=1;for(uint i=1;i<=1000002;i++)A[i]=A[i-1]*i;
    B[1000002]=A[1000002].inv();for(uint i=1000002;i;i--)B[i-1]=B[i]*i;
    uint n,k;scanf("%u%u",&n,&k);Val[1]=1;
    for(ullt i=2;i<=k+1;i++)
    {
        if(Val[i].empty()){P.push_back(i),Val[i]=modint(i)._power(k);for(ullt j=i*i;j<=k+1;j*=i)Val[j]=Val[j/i]*Val[i];}
        for(auto p:P)if(i%p&&i*p<=k+1)for(ullt t=p;i*t<=k+1;t*=p)Val[i*t]=Val[i]*Val[t];else break;
    }
    for(uint i=2;i<=k+1;i++)Val[i]+=Val[i-1];
    Pre[0]=Suf[k+1]=1;
    for(uint i=1;i<=k+1;i++)Pre[i]=Pre[i-1]*(n-modint(i-1));
    for(uint i=k;~i;i--)Suf[i]=Suf[i+1]*(n-modint(i+1));
    modint ans(0);
    for(uint i=0;i<=k+1;i++)ans+=Val[i]*Pre[i]*Suf[i]*B[k+1-i]*B[i]*op(k+1-i);
    ans.println();
    return 0;
}