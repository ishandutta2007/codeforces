// Hydro submission #625a1834cc64917dc4671e40@1650071605423
// 10^8 < 998244353
//  998244353 
//  + 
// 
// O*(2^n)
// 

#include <algorithm>
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
        inline ullt chg(ullt w){return(w<p)?w:w-p;}
        inline mod_ullt _chg(ullt w){mod_ullt ans;ans.v=(w<p)?w:w-p;return ans;}
    public:
        mod_ullt():v(0){}
        mod_ullt(ullt v):v(v%p){}
        bol empty(){return!v;}
        inline ullt val(){return v;}
        friend bol operator<(mod_ullt a,mod_ullt b){return a.v<b.v;}
        friend bol operator>(mod_ullt a,mod_ullt b){return a.v>b.v;}
        friend bol operator<=(mod_ullt a,mod_ullt b){return a.v<=b.v;}
        friend bol operator>=(mod_ullt a,mod_ullt b){return a.v>=b.v;}
        friend bol operator==(mod_ullt a,mod_ullt b){return a.v==b.v;}
        friend bol operator!=(mod_ullt a,mod_ullt b){return a.v!=b.v;}
        inline friend mod_ullt operator+(mod_ullt a,mod_ullt b){return a._chg(a.v+b.v);}
        inline friend mod_ullt operator-(mod_ullt a,mod_ullt b){return a._chg(a.v+a.chg(p-b.v));}
        inline friend mod_ullt operator*(mod_ullt a,mod_ullt b){return a.v*b.v;}
        friend mod_ullt operator/(mod_ullt a,mod_ullt b){return b._power(p-2)*a.v;}
        inline mod_ullt operator-(){return _chg(p-v);}
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
        voi print()
        {
            static chr C[20];uint tp=0;
            ullt w=v;do C[tp++]=w%10+'0',w/=10;while(w);
            while(tp--)putchar(C[tp]);
        }
        voi println(){print(),putchar('\n');}
        mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
    public:
        inline ullt&operator()(){return v;}
        inline mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
        inline mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
        inline mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
        mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
        mod_ullt&operator++(){return v=chg(v+1),*this;}
};
const ullt Mod=998244353;
typedef mod_ullt<Mod>modint;
const uint Siz=35;
struct Mat
{
    modint M[Siz][Siz];uint n;
    Mat():n(0){}
    Mat(uint n):n(n){}
    modint*operator[](uint n){return M[n];}
    voi bzr(){resize(0);}
    voi resize(uint s)
    {
        for(uint i=s;i<n;i++)for(uint j=0;j<n;j++)M[i][j]=M[j][i]=0;
        n=s;
    }
    modint det()
    {
        Mat A=*this;
        modint ans(1);
        for(uint i=0;i<n;i++)
        {
            {
                uint j;for(j=i;j<n&&!A[j][i]();j++);
                if(j==n)return 0;
                if(i!=j)
                {
                    ans=-ans;
                    for(uint k=0;k<n;k++)std::swap(A[i][k],A[j][k]);
                }
            }
            modint qaq=A[i][i];
            ans*=qaq;qaq=qaq.inv();
            for(uint j=0;j<n;j++)A[i][j]*=qaq;
            for(uint j=0;j<n;j++)if(A[j][i]()&&i!=j)
            {
                qaq=A[j][i];
                for(uint k=0;k<n;k++)A[j][k]-=A[i][k]*qaq;
            }
        }
        for(uint i=0;i<n;i++)ans*=A[i][i];
        return ans;
    }
};
typedef std::pair<uint,uint>Pair;
std::vector<Pair>E;
Mat M;
modint P[35],Q[35];
modint binom(uint n,uint m){return P[n]*Q[m]*Q[n-m];}
int main()
{
    P[0]=1;for(uint i=1;i<=30;i++)P[i]=P[i-1]*i;
    Q[30]=P[30].inv();for(uint i=30;i;i--)Q[i-1]=Q[i]*i;
    uint n,m,k;
    scanf("%u%u%u",&n,&m,&k);
    if(n==1)puts(k==1?"1":"0");
    else if(n==2)puts(m==1&&k==2?"1":"0");
    else
    {
        if(!k||k>=n)return puts("0"),0;
        uint u,v;while(m--)scanf("%u%u",&u,&v),E.push_back(Pair(u-1,v-1));
        modint ans;
        for(uint i=0;i<(1u<<n)-1;i++)if(__builtin_popcount(i)>=k)
        {
            modint now;
            std::vector<uint>Leaf,Any,Back(n);
            for(uint j=0;j<n;j++)
                if(i>>j&1)Back[j]=Leaf.size(),Leaf.push_back(j);
                else Back[j]=Any.size(),Any.push_back(j);
            std::vector<modint>Time(Leaf.size());
            M.bzr();
            M.resize(Any.size());
            for(auto e:E)
            {
                if((i>>e.first&1)&&!(i>>e.second&1))
                    Time[Back[e.first]]++;
                else if(!(i>>e.first&1)&&(i>>e.second&1))
                    Time[Back[e.second]]++;
                else if(!(i>>e.first&1)&&!(i>>e.second&1))
                {
                    u=Back[e.first],v=Back[e.second];
                    M[u][u]+=1,M[v][v]+=1,
                    M[u][v]-=1,M[v][u]-=1;
                }
            }
            M.resize(Any.size()-1);
            now=M.det();
            for(auto t:Time)now*=t;
            uint w=__builtin_popcount(i);
            ans+=((w-k)&1)?-binom(w,k)*now:binom(w,k)*now;
        }
        ans.println();
    }
    return 0;
}