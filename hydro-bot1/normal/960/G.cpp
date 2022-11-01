// Hydro submission #61938f75a8f5aa929e62c432@1637060469764
//       
// $${\binom{A+B-2}{A-1}}{n-1\brack A+B-2}$$
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
template<const ullt p=998244353,const ullt g=3>
class poly_NTT
{
    public:
		typedef mod_ullt<p>modint;
	private:
		std::vector<modint>V;
	public:
		class NTT
		{
			private:
				std::vector<uint>T;
				std::vector<modint>G;
			public:
				uint size(){return T.size();}
				voi bzr(uint len)
				{
					uint n=1;while(n<len)n<<=1;
					T.resize(n),G.resize(n),T[0]=0,G[0]=1;
                    modint w=power(g,(p-1)/n,p);
					for(uint i=1;i<n;i++)
						T[i]=((i&1)?n|T[i>>1]:T[i>>1])>>1,
						G[i]=G[i-1]*w;
				}
				voi ntt(std::vector<modint>&x,bol op)
				{
					uint n=size();if(x.size()<n)x.resize(n);
                    for(uint i=0;i<n;i++)if(T[i]<i)std::swap(x[i],x[T[i]]);
					for(uint i=1;i<n;i<<=1)for(uint j=0;j<n;j+=i<<1)for(uint k=0;k<i;k++)
					{
						modint t=x[i+j+k]*G[n/(2*i)*k];
						x[i+j+k]=x[j+k]-t,x[j+k]+=t;
					}
					if(op)
					{
						for(uint i=1;i*2<n;i++)std::swap(x[i],x[n-i]);
						modint t=modint(n).inv();
						for(uint i=0;i<n;i++)x[i]*=t;
					}
				}
		};
	public:
		poly_NTT(){}
		poly_NTT(uint n){V.resize(n);}
		poly_NTT(std::vector<modint>V):V(V){}
		voi bzr(){V.clear();}
		voi push(modint v){V.push_back(v);}
		voi pop(){V.pop();}
		voi cut_zero(){while(!V.empty()&&V.back().empty())V.pop_back();}
		voi chg_siz(uint n){V.resize(n);}
		voi chg_deg(uint n){V.resize(n+1);}
		bol empty(){return cut_zero(),V.empty();}
		uint size(){return V.size();}
		uint deg(){return V.size()-1;}
		modint val(uint n){return(n<size())?V[n]:0;}
        poly_NTT reverse()
        {
            poly_NTT ans;for(uint i=size()-1;~i;i--)ans.push(V[i]);
            return ans;
        }
		friend poly_NTT operator+(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]+=b[i];
			a.cut_zero();
			return a;
		}
		friend poly_NTT operator-(poly_NTT a,poly_NTT b)
		{
			if(a.size()<b.size())a.chg_siz(b.size());
			for(uint i=0;i<b.size();i++)a[i]-=b[i];
			a.cut_zero();
			return a;
		}
		friend poly_NTT operator*(poly_NTT a,poly_NTT b)
		{
            std::vector<modint>&A=a.V,&B=b.V;
            NTT s;s.bzr(A.size()+B.size());
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),a.cut_zero();
			return a;
		}
        poly_NTT inv(){return inv(size());}
        poly_NTT inv(uint prec)
        {
            std::vector<modint>ans;NTT s;
            ans.push_back(V[0].inv());
            for(uint tp=1;tp<=prec;tp<<=1)
            {
                std::vector<modint>f(tp<<1),t=ans;for(uint i=0;i<(tp<<1);++i)f[i]=val(i);
                s.bzr(tp<<1),s.ntt(f,0),s.ntt(t,0);for(uint i=0;i<(tp<<1);++i)f[i]=-f[i]*t[i]+1;
                s.ntt(f,1);for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
                s.ntt(f,0);for(uint i=(tp<<1)-1;~i;--i)f[i]*=t[i];
                s.ntt(f,1),ans.resize(tp<<1);for(uint i=0;i<tp;++i)ans[i+tp]=f[i];
            }
            ans.resize(prec);return ans;
        }
        poly_NTT diff()
        {
            poly_NTT ans;for(uint i=1;i<size();i++)ans.push(i*V[i]);
            return ans;
        }
        poly_NTT inte()
        {
            if(!size())return*this;
            poly_NTT ans(size()+1);ans[1]=1;
            for(uint i=2;i<=size();i++)ans[i]=-ans[p%i]*(p/i);
            for(uint i=1;i<=size();i++)ans[i]*=V[i-1];
            return ans;
        }
        poly_NTT ln(){return ln(size());}
        poly_NTT ln(uint prec)
        {
            poly_NTT a=this->diff()*this->inv(prec);
            a.chg_siz(prec);
            a=a.inte();
            a.chg_siz(prec);return a;
        }
        poly_NTT exp(){return exp(size());}
        poly_NTT exp(uint prec)
        {
            poly_NTT ans;std::vector<modint>Inv;ans.push(1),Inv.push_back(1);
            for(uint tp=1;tp<=prec;tp<<=1)
            {
                std::vector<modint>f,ff=ans.diff().V;
                for(uint i=0;i<(tp<<1);i++)f.push_back(val(i));
                f[0]=1;NTT s;s.bzr(tp<<2);s.ntt(ans.V,0),s.ntt(Inv,0);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.ntt(Inv,1),Inv.resize(tp);s.ntt(Inv,0);
                for(uint i=0;i<(tp<<2);i++)Inv[i]*=2-Inv[i]*ans[i];
                s.ntt(Inv,1),Inv.resize(tp<<1);s.ntt(Inv,0);s.ntt(ff,0);
                for(uint i=0;i<(tp<<2);i++)ff[i]*=Inv[i];
                s.ntt(ff,1);f=(f-poly_NTT(ff).inte()).V;s.ntt(f,0);
                for(uint i=0;i<(tp<<2);i++)ans[i]*=f[i];
                s.ntt(Inv,1),s.ntt(ans.V,1),ans.chg_siz(tp<<1);
            }
            ans.chg_siz(prec);
            return ans;
        }
    private:
        friend poly_NTT sub_mul(poly_NTT a,poly_NTT b)
        {
            a.cut_zero(),b.cut_zero();
            uint x=a.size(),y=b.size();
            b=b.reverse();
            std::vector<modint>&A=a.V,&B=b.V;
            NTT s;s.bzr(x+y);
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),B.clear();
            for(uint i=y-1;i<x+y-1;i++)B.push_back(a.val(i));
            b.cut_zero();
            return b;
        }
        voi mult_eval_dfs1(uint l,uint r,std::vector<modint>&X,uint u,std::vector<poly_NTT>&G)
        {
            if(l+1==r){G[u].push(1),G[u].push(-X[l]);return;}
            uint mid=(l+r)/2;
            mult_eval_dfs1(l,mid,X,u<<1,G),mult_eval_dfs1(mid,r,X,u<<1|1,G),G[u]=G[u<<1]*G[u<<1|1];
        }
        voi mult_eval_dfs2(uint l,uint r,std::vector<modint>&X,uint u,std::vector<poly_NTT>&G,std::vector<poly_NTT>&User)
        {
            User.back().chg_siz(r-l);
            if(l+1==r){X[l]=User.back().val(0);return;}
            uint mid=(l+r)/2;
            User.push_back(sub_mul(User.back(),G[u<<1|1])),mult_eval_dfs2(l,mid,X,u<<1,G,User);
            User.back()=sub_mul(User[User.size()-2],G[u<<1]),mult_eval_dfs2(mid,r,X,u<<1|1,G,User);
            User.pop_back();
        }
    public:
        voi mult_eval(std::vector<modint>&X)
        {
            if(X.empty())return;
            std::vector<poly_NTT>G(X.size()<<2),User;
            mult_eval_dfs1(0,X.size(),X,1,G);
            User.push_back(sub_mul(*this,G[1].inv(std::max<uint>(size(),X.size())+1)));
            mult_eval_dfs2(0,X.size(),X,1,G,User);
        }
	public:
		modint&operator[](uint n){return V[n];};
        poly_NTT&operator+=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]+=b[i];
			cut_zero();
			return*this;
        }
        poly_NTT&operator-=(poly_NTT b)
        {
			if(size()<b.size())chg_siz(b.size());
			for(uint i=0;i<b.size();i++)V[i]-=b[i];
			cut_zero();
			return*this;
        }
        poly_NTT&operator*=(poly_NTT b)
        {
            std::vector<modint>&A=V,&B=b.V;
            NTT s;s.bzr(A.size()+B.size());
            s.ntt(A,0),s.ntt(B,0);
            for(uint i=0;i<s.size();i++)A[i]*=B[i];
            s.ntt(A,1),cut_zero();
			return*this;
        }
};
const ullt Mod=998244353;
typedef mod_ullt<Mod>modint;
typedef poly_NTT<Mod,3>poly;
modint A[200005],B[200005];
poly Up(uint l,uint r) // (x+l)(x+l+1)(x+l+2)(x+l+3)..(x+r-1)
{
    if(l==r){poly ans;ans.push(1);return ans;}
    if(l+1==r){poly ans;ans.push(l),ans.push(1);return ans;}
    return Up(l,(l+r)>>1)*Up((l+r)>>1,r);
}
int main()
{
    uint n,a,b;scanf("%u%u%u",&n,&a,&b);
    if(!a||!b)return puts("0"),0;
    A[0]=1;for(uint i=1;i<=200000;i++)A[i]=A[i-1]*i;
    B[200000]=A[200000].inv();for(uint i=200000;i;i--)B[i-1]=B[i]*i;
    (A[a+b-2]*B[a-1]*B[b-1]*Up(0,n-1).val(a+b-2)).println();
    return 0;
}