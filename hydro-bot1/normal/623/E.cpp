// Hydro submission #625a17e237de167dd82d1f91@1650071523256
#include <algorithm>
#include <math.h>
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
class mod_ullt//,
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
		voi read(){v=0;chr c;do c=getchar();while(c>'9'||c<'0');do v=c-'0'+v*10,c=getchar();while(c>='0'&&c<='9');v%=p;}
		voi print(){_print(v);}
		voi println(){_print(v),putchar('\n');}
		mod_ullt operator++(int){mod_ullt ans=*this;return v=chg(v+1),ans;}
	public:
		mod_ullt&operator+=(mod_ullt b){return*this=_chg(v+b.v);}
		mod_ullt&operator-=(mod_ullt b){return*this=_chg(v+chg(p-b.v));}
		mod_ullt&operator*=(mod_ullt b){return*this=v*b.v;}
		mod_ullt&operator/=(mod_ullt b){return*this=b._power(p-2)*v;}
		mod_ullt&operator++(){return v=chg(v+1),*this;}
};
template<const ullt p=998244353>
class Inv_ullt
{
    public:
        voi bzr(ullt n){V.clear();V.push_back(0);if(n){V.push_back(1);for(ullt i=2;i<=n;++i)V.push_back(-V[p%i]*(p/i));}}
		mod_ullt<p>inv(ullt n){return V[n];}mod_ullt<p>operator[](ullt n){return V[n];}std::vector<mod_ullt<p> >I(){return V;}
    private:std::vector<mod_ullt<p> >V;
};
template<const ullt p=998244353,const ullt g=3>
class poly_NTT
{
	public:
		typedef mod_ullt<p>modint;
	private:
        std::vector<modint>V;
		voi mult_evel_dfs1(uint l,uint r,std::vector<modint>&Q,std::vector<std::vector<poly_NTT> >&B)
		{
			uint len=r-l;if(len==1){poly_NTT w;w.push(-Q[l]),w.push(1),B[l].push_back(w);return;}
			mult_evel_dfs1(l,l+(len>>1),Q,B),mult_evel_dfs1(l+(len>>1),r,Q,B),B[l].push_back(B[l].back()*B[l+(len>>1)].back());
		}
		voi mult_evel_dfs2(poly_NTT P,uint l,uint r,std::vector<modint>&Q,std::vector<std::vector<poly_NTT> >&B)
		{
			uint len=r-l;
			if(len<512){for(uint i=l;i<r;i++){const modint w=Q[i];Q[i]=0;for(uint j=P.deg();~j;--j)Q[i]=Q[i]*w+P[j];}return;}
			B[l].pop_back();mult_evel_dfs2(P%B[l].back(),l,l+(len>>1),Q,B),mult_evel_dfs2(P%B[l+(len>>1)].back(),l+(len>>1),r,Q,B);
		}
	public:
		class NTT_ullt
		{
		    private:
		        std::vector<uint>V;uint len;modint inv;
		        std::vector<modint>G;
		    public:
		    	NTT_ullt(){V.clear(),len=0,inv=0;}
		        uint length(){return len;}
		        voi bzr(uint length)
		        {
		            len=1;while(length){length>>=1,len<<=1;}
                    inv=modint(len).inv(),V.resize(len),G.resize(len),V[0]=0,G[0]=1;
                    modint w=power(g,(p-1)/len,p);
                    for(uint i=1;i<len;++i)
                        V[i]=((i&1)?(V[i>>1]|len)>>1:(V[i>>1]>>1)),G[i]=G[i-1]*w;
		        }
		        voi ntt(std::vector<modint>&x,bol opt)
		        {
		        	if(x.size()<len)x.resize(len);
		        	modint tmp;uint k;
		            for(uint i=0;i<len;++i)if(V[i]<i)std::swap(x[i],x[V[i]]);
		            for(k=1;(k<<1)<=len;k<<=1)
						for(uint i=0;i<len;i+=(k<<1))for(uint j=0;j<k;++j)tmp=x[i+j+k]*G[len/(k<<1)*j],x[i+j+k]=x[i+j]-tmp,x[i+j]+=tmp;
		            if(opt){uint l=1,r=len-1;while(l<r)std::swap(x[l++],x[r--]);for(uint i=0;i<len;++i)x[i]*=inv;}
		        }
		        voi ntt(std::vector<modint>&x,bol opt,std::vector<modint>&from)
		        {
		        	if(x.size()<len)x.resize(len);
		        	modint c,tmp;uint k;
		            for(uint i=0;i<from.size()&&i<len;++i)x[V[i]]=from[i];
		            for(k=1;(k<<1)<=len;k<<=1)
		            {
		                const modint gn(power(g,(p-1)/(k<<1),p));
						for(uint i=0;i<len;i+=(k<<1)){c=1;for(uint j=0;j<k;++j,c*=gn)tmp=x[i+j+k]*c,x[i+j+k]=x[i+j]-tmp,x[i+j]+=tmp;}
		            }
		            if(opt){uint l=1,r=len-1;while(l<r)std::swap(x[l++],x[r--]);for(uint i=0;i<len;++i)x[i]*=inv;}
		        }
		};
	public:
		poly_NTT(){V.clear();}
		poly_NTT(std::vector<ullt>V){this->V.clear();for(uint i=0;i<V.size();++i)this->V.push_back(modint(V[i]));}
		poly_NTT(std::vector<modint>V){this->V=V,cut_zero();}
		bol empty(){return cut_zero(),!size();}
		voi bzr(){V.clear();}
		voi push(modint v){V.push_back(v);}
		voi push(ullt v){V.push_back(modint(v));}
		voi pop(){V.pop_back();}
		modint val(uint n){return(n<V.size())?V[n]:modint();}
		uint deg(){return V.size()-1;}
		uint size(){return V.size();}
        poly_NTT operator+(poly_NTT b){uint n=size();if(b.size()<n)b.chg_siz(n);for(uint i=0;i<n;++i)b[i]+=V[i];b.cut_zero();return b;}
        poly_NTT operator-(poly_NTT b){uint n=size();if(b.size()<n)b.chg_siz(n);for(uint i=0;i<b.size();++i)b[i]=val(i)-b[i];b.cut_zero();return b;}
        poly_NTT operator*(poly_NTT b)
        {
            if(empty()||b.empty())return poly_NTT();
            std::vector<modint>v1,v2;NTT_ullt s;uint len;
            s.bzr(deg()+b.deg()+1),len=s.length(),s.ntt(v1,0,V),s.ntt(v2,0,b.V);
			for(uint i=0;i<len;++i)v1[i]*=v2[i];
			s.ntt(v1,1);return v1;
        }
        poly_NTT operator*(modint v){if(empty()||v.empty())return poly_NTT();uint n=size();poly_NTT w=*this;for(uint i=0;i<n;++i)w[i]*=v;return w;}
        poly_NTT operator*(const ullt v){return*this*modint(v);}
        poly_NTT operator-(){return*this*(p-1);}
        poly_NTT inv(){return inv(size());}
        poly_NTT inv(const uint prec)//2 
        {
            std::vector<modint>ans(prec<<1),f;NTT_ullt s;
            ans[0]=V[0].inv();uint tp=1;
            while(tp<prec)
            {
                s.bzr((tp<<=1)-1),s.ntt(f,0,V),s.ntt(ans,0);for(uint i=0;i<tp;++i)f[i]=-f[i]*ans[i]+1;
                s.ntt(f,1),tp>>=1;for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
                s.ntt(f,0);for(uint i=(tp<<1)-1;~i;--i)f[i]*=ans[i];
                s.ntt(f,1),s.ntt(ans,1);for(uint i=0;i<tp;++i)ans[tp+i]=f[i];tp<<=1;
            }
            ans.resize(prec);
            return ans;
        }
        poly_NTT diff(){uint n=size();poly_NTT ans;for(uint i=1;i<n;++i)ans.push(V[i]*i);return ans;}
        poly_NTT inte(){uint n=size();poly_NTT ans;ans.push(0);Inv_ullt<p>I;I.bzr(n);for(uint i=0;i<n;++i)ans.push(V[i]*I[i+1]);return ans;}
        poly_NTT inte(Inv_ullt<p>&I){uint n=size();poly_NTT ans;ans.push(0);for(uint i=0;i<n;++i)ans.push(V[i]*I[i+1]);return ans;}
        poly_NTT ln(){return(this->diff()*this->inv()).inte().chg_deg_ed(deg());}
        poly_NTT ln(Inv_ullt<p>&I){return(this->diff()*this->inv()).inte(I).chg_deg_ed(deg());}
        poly_NTT ln(const uint prec){return(this->diff()*this->inv(prec)).inte().chg_deg_ed(prec-1);}
        poly_NTT ln(Inv_ullt<p>&I,const uint prec){return(this->diff()*this->inv(prec)).inte(I).chg_deg_ed(prec-1);}
        poly_NTT exp(){return exp(size());}
        poly_NTT exp(const uint prec)
        {
            NTT_ullt s;
            std::vector<modint>ans,Inv,f;ans.push_back(1),Inv.push_back(1);
            uint tp=1;
        	for(uint k=2;k<(prec<<1);k<<=1)
            {
				if(k>2)tp=k>>2,Inv.resize(k>>2);
				while(tp<k)
	            {
	                tp<<=1;
					f=ans,f.resize(tp);
					Inv.resize(tp);
					s.bzr(tp-1),s.ntt(f,0),s.ntt(Inv,0);
	                for(uint i=0;i<tp;++i)f[i]=-f[i]*Inv[i]+1;
					s.ntt(f,1),tp>>=1;
					for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
	                s.ntt(f,0);
					for(uint i=(tp<<1)-1;~i;--i)f[i]*=Inv[i];
					s.ntt(f,1),s.ntt(Inv,1);
					for(uint i=0;i<tp;++i)Inv[tp+i]=f[i];
					tp<<=1;
	            }
        		f=(poly_NTT(ans).diff()*Inv).inte().chg_deg_ed(k-1).V;
                f.resize(k<<1);f[0]=1;
        		for(uint i=1;i<k;++i)f[i]=val(i)-f[i];
                ans.resize(k<<1);
				if(k>2)s.bzr((k<<1)-1);
                s.ntt(ans,0),s.ntt(f,0);
        		for(uint i=0;i<(k<<1);i++)ans[i]*=f[i];
                s.ntt(ans,1);
                while(ans.size()>k)ans.pop_back();
        	}
        	while(ans.size()>prec)ans.pop_back();
        	return ans;
        }
        poly_NTT exp(Inv_ullt<p>&I){return exp(I,size());}
        poly_NTT exp(Inv_ullt<p>&I,const uint prec)
        {
            NTT_ullt s;
            std::vector<modint>ans,Inv,f;ans.push_back(1),Inv.push_back(1);
            uint tp=1;
        	for(uint k=2;k<(prec<<1);k<<=1)
            {
				if(k>2)tp=k>>2,Inv.resize(k>>2);
				while(tp<k)
	            {
	                tp<<=1;
					f=ans,f.resize(tp);
					Inv.resize(tp);
					s.bzr(tp-1),s.ntt(f,0),s.ntt(Inv,0);
	                for(uint i=0;i<tp;++i)f[i]=-f[i]*Inv[i]+1;
					s.ntt(f,1),tp>>=1;
					for(uint i=0;i<tp;++i)f[i]=f[i+tp],f[i+tp]=0;
	                s.ntt(f,0);
					for(uint i=(tp<<1)-1;~i;--i)f[i]*=Inv[i];
					s.ntt(f,1),s.ntt(Inv,1);
					for(uint i=0;i<tp;++i)Inv[tp+i]=f[i];
					tp<<=1;
	            }
        		f=(poly_NTT(ans).diff()*Inv).inte(I).chg_deg_ed(k-1).V;
                f.resize(k<<1);f[0]=1;
        		for(uint i=1;i<k;++i)f[i]=val(i)-f[i];
                ans.resize(k<<1);
				if(k>2)s.bzr((k<<1)-1);
                s.ntt(ans,0),s.ntt(f,0);
        		for(uint i=0;i<(k<<1);i++)ans[i]*=f[i];
                s.ntt(ans,1);
                while(ans.size()>k)ans.pop_back();
        	}
        	while(ans.size()>prec)ans.pop_back();
        	return ans;
        }
        poly_NTT _power(const ullt index)
        {
			poly_NTT f,w;if(!index)return f.push(1),f;uint t=0,n=size();
			while(t<n&&V[t].empty())++t;
			if(t==n)return*this;
			modint v=V[t].inv();t*=index;if(t>=n)return poly_NTT();
			for(uint i=t/index;i<t/index+n-t;++i)w.push(v*V[i]);
			w=(w.ln()*index).exp(),v=V[t/index]._power(index),f=std::vector<modint>(t);
			for(uint i=t;i<n;i++)f.push(w[i-t]*v);
			return f;
		}
        poly_NTT _power(Inv_ullt<p>&I,const ullt index)
        {
			poly_NTT f,w;if(!index)return f.push(1),f;uint t=0,n=size();
			while(t<n&&V[t].empty())++t;
			if(t==n)return*this;
			modint v=V[t].inv();t*=index;if(t>=n)return poly_NTT();
			for(uint i=t/index;i<t/index+n-t;++i)w.push(v*V[i]);
			w=(w.ln(I)*index).exp(I),v=V[t/index]._power(index);
			f=std::vector<modint>(t);for(uint i=t;i<n;i++)f.push(w[i-t]*v);
			return f;
		}
        poly_NTT _power(const ullt index1,const ullt index2)//index mod p, index mod (p-1)
        {
			poly_NTT f,w;uint t=0,n=size();while(t<n&&V[t].empty())++t;if(t==n)return index1?*this:(f.push(1),f);
			modint v=V[t].inv();if(index1==0){f.push(V[t]._power(index2));return f;}t*=index1;if(t>=n)return poly_NTT();
			for(uint i=t/index1;i<t/index1+n-t;++i)w.push(v*V[i]);
			w=(w.ln()*index1).exp(),v=V[t/index1]._power(index2),f=std::vector<modint>(t);
			for(uint i=t;i<n;i++)f.push(w[i-t]*v);
			return f;
		}
		poly_NTT sqrt(){return sqrt(size());}
		poly_NTT sqrt(const uint prec)
		{
		    if(empty())return poly_NTT();
            poly_NTT ans;ans.push(V[0].sqrt());
            modint f=(p+1)>>1;uint tp=1;
            while(tp<prec)ans=(ans+ans.inv(tp<<=1)**this)*f,ans.chg_deg(tp);
            return ans.chg_siz(prec),ans;
        }
        poly_NTT reverse(){poly_NTT ans;for(uint i=deg();~i;--i)ans.push(V[i]);return ans;}
        poly_NTT operator/(poly_NTT b)
        {
            cut_zero(),b.cut_zero();uint m=size(),n=b.deg();if(m<=n)return poly_NTT();
            poly_NTT f=this->reverse()*b.reverse().inv(m-n);f.chg_siz((m>n)?m-n:0);return f.reverse();
        }
        poly_NTT operator%(poly_NTT b){poly_NTT f=*this-*this/b*b;f.cut_zero();return f;}
        poly_NTT sin(){modint i=modint(p-1).sqrt();poly_NTT w=(*this*i).exp();return(w.inv()-w)*i*((p+1)>>1);}
        poly_NTT cos(){modint i=modint(p-1).sqrt();poly_NTT w=(*this*i).exp();return(w.inv()+w)*((p+1)>>1);}
        poly_NTT asin(){poly_NTT q;q.push(1);return(diff()*(q-*this**this).chg_deg_ed(deg()).sqrt().inv()).inte().chg_deg_ed(deg());}
        poly_NTT atan(){poly_NTT q;q.push(1);return(diff()*(q+(*this**this).chg_deg_ed(deg())).inv()).inte().chg_deg_ed(deg());}
        voi mult_eval(std::vector<modint>&Q)//multipoint evaluation
        {
            uint m=Q.size();
            while(Q.size()<size())Q.push_back(0);
        	std::vector<std::vector<poly_NTT> >B(Q.size());
			mult_evel_dfs1(0,Q.size(),Q,B);
			mult_evel_dfs2(*this,0,Q.size(),Q,B);
            Q.resize(m);
		}
	    voi cut_zero(){while(!V.empty()&&V.back().empty())V.pop_back();}
	    voi chg_siz(const uint siz){while(V.size()<siz)V.push_back(0);while(V.size()>siz)V.pop_back();}
	    voi chg_deg(const uint d){chg_siz(d+1);}
	    poly_NTT chg_deg_ed(const uint d){poly_NTT ans=*this;return ans.chg_deg(d),ans;}
	public:
		mod_ullt<p>&operator[](const uint n){return V[n];}
		poly_NTT&operator=(std::vector<ullt>V){this->V.clear();for(uint i=0;i<V.size();++i)this->V.push_back(modint(V[i]));return*this;}
		poly_NTT&operator=(const std::vector<modint>V){this->V=V;return*this;}
        poly_NTT&operator+=(const poly_NTT b){return*this=*this+b;}
        poly_NTT&operator-=(const poly_NTT b){return*this=*this-b;}
        poly_NTT&operator*=(const poly_NTT b){return*this=*this*b;}
        poly_NTT&operator*=(const modint b){return*this=*this*b;}
        poly_NTT&operator*=(const ullt b){return*this=*this*b;}
        poly_NTT&operator/=(const poly_NTT b){return*this=*this/b;}
        poly_NTT&operator%=(const poly_NTT b){return*this=*this%b;}
};
const dbl Pi=acos(-1);
class cpx
{
    public:
        dbl a,b;
        cpx():a(0),b(0){}
        cpx(dbl a):a(a),b(0){}
        cpx(dbl a,dbl b):a(a),b(b){}
        voi unit(dbl alpha){a=cos(alpha),b=sin(alpha);}
        cpx friend operator+(cpx a,cpx b){return cpx(a.a+b.a,a.b+b.b);}
        cpx friend operator-(cpx a,cpx b){return cpx(a.a-b.a,a.b-b.b);}
        cpx operator-(){return cpx(-a,-b);}
        cpx friend operator*(cpx a,cpx b){return cpx(a.a*b.a-a.b*b.b,a.b*b.a+b.b*a.a);}
        cpx friend operator/(cpx a,ullt v){return cpx(a.a/v,a.b/v);}
        cpx conj(){return cpx(a,-b);}
        cpx mul_i(){return cpx(-b,a);}
        cpx div_i(){return cpx(b,-a);}
    public:
        cpx&operator=(ullt v){return a=v,b=0,*this;}
        cpx&operator+=(cpx v){return*this=*this+v;}
        cpx&operator-=(cpx v){return*this=*this-v;}
        cpx&operator*=(cpx v){return*this=*this*v;}
        cpx&operator/=(ullt v){return a/=v,b/=v,*this;}
        dbl&real(){return a;}
        dbl&imag(){return b;}
};
ullt Mod=1000000007;
ullt chg(ullt v){return(v<Mod)?v:v-Mod;}
class poly
{
    private:
        std::vector<ullt>V;
        voi mult_evel_dfs1(uint l,uint r,std::vector<ullt>&Q,std::vector<std::vector<poly> >&B)
		{
			uint len=r-l;
			if(len==1){poly w;w.push(chg(Mod-Q[l])),w.push(1),B[l].push_back(w);return;}
			mult_evel_dfs1(l,l+(len>>1),Q,B),mult_evel_dfs1(l+(len>>1),r,Q,B),B[l].push_back(B[l].back()*B[l+(len>>1)].back());
		}
		voi mult_evel_dfs2(poly P,uint l,uint r,std::vector<ullt>&Q,std::vector<std::vector<poly> >&B)
		{
			uint len=r-l;
			if(len<512)
			{
				for(uint i=l;i<r;i++){const ullt w=Q[i];Q[i]=0;for(uint j=P.deg();~j;--j)Q[i]=(Q[i]*w+P[j])%Mod;}
				return;
			}
			B[l].pop_back(),mult_evel_dfs2(P%B[l].back(),l,l+(len>>1),Q,B),mult_evel_dfs2(P%B[l+(len>>1)].back(),l+(len>>1),r,Q,B);
		}
    public:
        class FFT
        {
            private:
                std::vector<uint>V;std::vector<cpx>G;uint len;
            public:
                uint length(){return len;}
                voi bzr(uint length)
                {
                    uint p=0;len=1,V.clear(),G.clear();
                    while(length){p++,len<<=1,length>>=1;}
                    V.resize(len),G.resize(len);
                    for(uint i=0;i<len;++i)V[i]=((i&1)?(V[i>>1]|len)>>1:(V[i>>1]>>1)),G[i].unit(Pi*2/len*i);
                }
                voi fft(std::vector<cpx>&y,bol op)
                {
                    if(y.size()<len)y.resize(len);
                    for(uint i=0;i<len;i++)if(V[i]<i)std::swap(y[i],y[V[i]]);
                    for(uint h=2;h<=len;h<<=1)for(uint j=0;j<len;j+=h)for(uint k=j;k<j+(h>>1);k++){cpx u=y[k],t=G[len/h*(k-j)]*y[k+h/2];y[k]=u+t,y[k+h/2]=u-t;}
                    if(op){uint l=1,r=len-1;while(l<r)std::swap(y[l++],y[r--]);for(uint i=0;i<len;i++)y[i]/=len;}
                }
				voi fft_fft(std::vector<cpx>&a,std::vector<cpx>&b,bol op)
				{
                    if(a.size()<len)a.resize(len);
                    if(b.size()<len)b.resize(len);
					for(uint i=0;i<len;i++)a[i]+=b[i].mul_i();
					fft(a,op),b[0]=a[0].conj();for(uint i=1;i<len;i++)b[i]=a[len-i].conj();
					for(uint i=0;i<len;i++){cpx p=a[i],q=b[i];a[i]=(p+q)/2llu,b[i]=(p-q).div_i()/2llu;}
				}
        };
    public:
		poly(){V.clear();}
		poly(std::vector<ullt>V){for(uint i=0;i<V.size();i++)push(V[i]%Mod);cut_zero();}
		bol empty(){return cut_zero(),!size();}
		voi bzr(){V.clear();}
		voi push(ullt v){V.push_back(v%Mod);}
		voi pop(){V.pop_back();}
		ullt val(uint n){return(n<V.size())?V[n]:0;}
		uint deg(){return V.size()-1;}
		uint size(){return V.size();}
		voi add(uint p,ullt v)
		{
			if(size()<=p)chg_deg(p);
			V[p]=(V[p]+v)%Mod;
		}
		poly friend operator+(poly a,ullt v){a.add(0,v);return a;}
		poly friend operator+(poly a,poly b)
		{
			uint len=std::max(a.size(),b.size());
			a.chg_siz(len),b.chg_siz(len);
			for(uint i=0;i<len;i++)a[i]=chg(a[i]+b[i]);
			a.cut_zero();
			return a;
		}
		poly friend operator-(poly a,poly b)
		{
			uint len=std::max(a.size(),b.size());
			a.chg_siz(len),b.chg_siz(len);
			for(uint i=0;i<len;i++)a[i]=chg(a[i]+Mod-b[i]);
			a.cut_zero();
			return a;
		}
		poly operator-()
		{
			cut_zero();uint len=size();
			poly ans;ans.chg_siz(len);
			for(uint i=0;i<len;i++)ans[i]=chg(Mod-V[i]);
			return ans;
		}
		poly friend operator*(poly a,poly b)
		{
            FFT s;poly p;
			uint n=a.deg(),m=b.deg(),len;
            s.bzr(n+m+1),len=s.length();
		    std::vector<cpx>v1(len),v2(len),v3(len),v4(len);
		    for(uint i=0;i<len;i++)v3[i]=cpx(a.val(i)&32767),v1[i]=cpx(a.val(i)>>15),v4[i]=cpx(b.val(i)&32767),v2[i]=cpx(b.val(i)>>15);
		    s.fft_fft(v1,v2,0),s.fft_fft(v3,v4,0);
			for(uint i=0;i<len;i++)v4[i]=(v3[i]+v1[i].mul_i())*v4[i],v2[i]=(v3[i]+v1[i].mul_i())*v2[i];
		    s.fft(v2,1),s.fft(v4,1),p.chg_deg(n+m);for(uint i=0;i<=n+m;i++)p[i]=(((ullt)(v2[i].b+.5)%Mod<<30)+((ullt)(v2[i].a+v4[i].b+.5)%Mod<<15)+(ullt)(v4[i].a+.5))%Mod;
		    p.cut_zero();
            return p;
		}
        poly inv(){return inv(size());}
        poly inv(uint prec)
        {
        	poly ans,f,tmp,w;
        	llt x,y;
        	exgcd<llt>(val(0),Mod,x,y);
        	ans.push(x%(llt)Mod+(llt)Mod),f.push(val(0));
			for(uint k=1;k<prec;k<<=1)
			{
				for(uint i=k;i<(k<<1);++i)f.push(val(i));
				tmp=f*ans,tmp.chg_siz(k<<1),w.bzr();for(uint i=0;i<k;++i)w.push(tmp[i+k]);
				w*=ans;for(uint i=0;i<k;++i)ans.push(Mod-w[i]);
			}
			return ans;
        }
	    poly diff(){uint n=size();poly ans;for(uint i=1;i<n;++i)ans.push(V[i]*i);return ans;}
        poly inte()
        {
        	uint n=size();
        	poly ans;
        	ans.chg_deg(n);
        	ullt k=1;llt x,y;
        	std::vector<ullt>W;W.push_back(1),W.push_back(1);
        	for(uint i=2;i<n;++i)W.push_back(k=(k*i)%Mod);
        	exgcd<llt>(k*n%Mod,Mod,x,y);
        	k=chg(x%(llt)Mod+(llt)Mod);
        	for(uint i=n;i;--i)ans[i]=V[i-1]*k%Mod*W[i-1]%Mod,k=k*i%Mod;
        	return ans;
        }
		poly ln(){return(this->diff()*this->inv()).inte().chg_deg_ed(deg());}
		poly exp(){return exp(size());}
        poly exp(uint prec)
        {
            poly m;m.push(1);
            if(empty())return m;
            uint tp=1;
            while(tp<prec)m*=*this-(m.diff()*m.inv(tp<<=1)).inte()+1,m.chg_siz(tp);
            m.chg_siz(prec);
            return m;
        }
        poly reverse(){poly ans;for(uint i=deg();~i;--i)ans.push(V[i]);return ans;}
        poly operator/(poly b)
        {
            cut_zero(),b.cut_zero();uint m=size(),n=b.deg();if(m<=n)return poly();
            poly f=this->reverse()*b.reverse().inv(m-n);f.chg_siz((m>n)?m-n:0);return f.reverse();
        }
        poly operator%(poly b){poly f=*this-*this/b*b;f.cut_zero();return f;}
        voi mult_eval(std::vector<ullt>&Q)
        {
            uint m=Q.size();while(Q.size()<size())Q.push_back(0);
        	std::vector<std::vector<poly> >B(Q.size());
			mult_evel_dfs1(0,Q.size(),Q,B);
			mult_evel_dfs2(*this,0,Q.size(),Q,B);
            Q.resize(m);
		}
	    voi cut_zero(){while(!V.empty()&&!V.back())V.pop_back();}
	    voi chg_siz(const uint siz){while(V.size()<siz)V.push_back(0);while(V.size()>siz)V.pop_back();}
	    voi chg_deg(const uint d){chg_siz(d+1);}
	    poly chg_deg_ed(const uint d){poly ans=*this;return ans.chg_deg(d),ans;}
	public:
        ullt&operator[](uint num){return V[num];}
		poly&operator=(std::vector<ullt>V){bzr();for(uint i=0;i<V.size();i++)push(V[i]%Mod);cut_zero();return*this;}
		poly&operator=(std::vector<cpx>V){bzr();for(uint i=0;i<V.size();i++)push((llt)(V[i].a+.5)%(llt)Mod+(llt)(Mod));cut_zero();return*this;}
		poly&operator+=(poly b){return*this=*this+b;}
		poly&operator-=(poly b){return*this=*this-b;}
		poly&operator*=(poly b){return*this=*this*b;}
		poly&operator/=(poly b){return*this=*this/b;}
		poly&operator%=(poly b){return*this=*this%b;}
};
typedef mod_ullt<1000000007>modint;
ullt k;
// f_n(x)=\prod{i=0;n-1;exp(2^ix)-1}
// f_{2n}(x)=f_n(x)*f_n(x*2^n)
poly f(ullt n)
{
	if(n==1)
	{
		poly ans;
		ans.push(0),ans.push(1);
		ans=ans.exp(k+1);
		ans[0]=0;
//		for(uint i=0;i<=k;i++)modint(ans[i]).println();
//		puts("-------------");
		return ans;
	}
	poly ans=f(n>>1),g;
	g=ans;modint w=modint(2)._power(n>>1),p(1);
	g.chg_deg(k);
	for(uint i=0;i<=k;i++,p*=w)g[i]=g[i]*p.val()%Mod;
	ans*=g,ans.chg_deg(k);
//	for(uint i=0;i<=k;i++)modint(ans[i]).println();
//	puts("-------------");
	if(n&1)g.bzr(),g.push(0),g.push(modint(2)._power(n-1).val()),g=g.exp(k+1),g[0]=0,ans*=g,ans.chg_deg(k);
	return ans;
}
modint A[114514];
int main()
{
	ullt n;scanf("%llu%llu",&n,&k);
	if(n>k)return puts("0"),0;
	poly w=f(n);
//	for(uint i=0;i<=k;i++)modint(w[i]).println();
	A[0]=1;
	for(uint i=1;i<=k;i++)A[i]=A[i-1]*i;
	modint ans(0);
	for(uint i=n;i<=k;i++)
		ans+=A[k-i].inv()*w[i];
	ans*=A[k];
	ans.println();
	return 0;
}