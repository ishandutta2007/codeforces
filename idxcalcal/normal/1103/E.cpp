#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
typedef unsigned long long ull;
const ull inv_5=57646075230342349ull;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=1e5+5;
int n,a[N],mx=0,lim;
ull c[20];
struct cp{
	ull a[10];
	inline void clear(){for(ri i=0;i<10;++i)a[i]=0;}
	inline ull&operator[](const int&k){return a[k];}
	inline const ull&operator[](const int&k)const{return a[k];}
	friend inline cp operator*(cp a,cp b){
		for(ri i=0;i<10;++i)for(ri j=0;j<10;++j)c[i+j]+=a[i]*b[j];
		for(ri i=0;i<10;++i)a[i]=c[i]+c[i+10],c[i]=c[i+10]=0;
		return a;
	}
	friend inline void operator*=(cp&a,cp b){a=a*b;}
	friend inline cp operator^(cp a,int p){
		cp res;
		res.clear(),res[0]=1;
		for(;p;p>>=1,a=a*a)if(p&1)res=res*a;
		return res;
	}
	inline cp fix(){
		cp res=*this;
		for(ri i=0;i<10;++i)res[i]=(res[i]>>1)*inv_5;
		return res;
	}
	inline ull val(){return (a[0]-a[2]+a[7]-a[5])%(1ull<<58);}
}f[N<<1];
inline void dwt(cp*f){
	cp s[10];
	for(ri i=1;i<lim;i*=10)for(ri j=0,len=i*10;j<lim;j+=len)
	for(ri k=0;k<i;++k){
		for(ri ps,p=0;p<10;++p){
			s[p].clear();
			for(ri ps,q=0;q<10;++q){
				ps=p*q%10;
				for(ri o=0;o+ps<10;++o)s[p][o+ps]+=f[j+k+q*i][o];
				for(ri o=10-ps;o<10;++o)s[p][o+ps-10]+=f[j+k+q*i][o];
			}
		}
		for(ri p=0;p<10;++p)f[j+k+p*i]=s[p];
	}
}
inline void idwt(cp*f){
	static cp s[10];
	for(ri i=1;i<lim;i*=10)for(ri j=0,len=i*10;j<lim;j+=len)
	for(ri k=0;k<i;++k){
		for(ri ps,p=0;p<10;++p){
			s[p].clear();
			for(ri ps,q=0;q<10;++q){
				ps=p*q%10;
				ps=ps?10-ps:0;
				for(ri o=0;o+ps<10;++o)s[p][o+ps]+=f[j+k+q*i][o];
				for(ri o=10-ps;o<10;++o)s[p][o+ps-10]+=f[j+k+q*i][o];
			}
		}
		for(ri p=0;p<10;++p)f[j+k+p*i]=s[p].fix();
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)++f[a[i]=read()][0],mx=max(mx,a[i]);
	for(lim=10;lim<mx;lim*=10);
	dwt(f);
	for(ri i=0;i<lim;++i)f[i]=f[i]^n;
	idwt(f);
	for(ri i=0;i<n;++i)cout<<f[i].val()<<'\n';
	return 0;
}