#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=1e5+5;
const long double eps=1e-10;
inline int sgn(long double x){return (x>eps)-(x<-eps);}
const int mod=1e9+7;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
template<class T>struct modular{
	T vl;
	explicit operator T()const{return vl;}
	modular(){vl=0;}
	modular(const ll&v){vl=v>=-mod&&v<=mod?v:v%mod,vl<0?vl+=mod:0;}
	friend inline bool operator==(const modular&a,const modular&b){return a.vl==b.vl;}
	friend inline bool operator!=(const modular&a,const modular&b){return a.vl!=b.vl;}
	friend inline bool operator<(const modular&a,const modular&b){return a.vl<b.vl;}
	friend inline bool operator>(const modular&a,const modular&b){return a.vl>b.vl;}
	friend inline bool operator<=(const modular&a,const modular&b){return a.vl<=b.vl;}
	friend inline bool operator>=(const modular&a,const modular&b){return a.vl>=b.vl;}
	inline modular operator-()const{return mod-vl;}
	friend inline modular operator+(const modular&a,const modular&b){return modular(a.vl+b.vl<mod?a.vl+b.vl:a.vl+b.vl-mod);}
	friend inline void operator+=(modular&a,const modular&b){a=a+b;}
	friend inline modular operator-(const modular&a,const modular&b){return modular(a.vl<b.vl?a.vl-b.vl+mod:a.vl-b.vl);}
	friend inline void operator-=(modular&a,const modular&b){a=a-b;}
	friend inline modular operator*(const modular&a,const modular&b){return modular((ll)a.vl*b.vl%mod);}
	friend inline void operator*=(modular&a,const modular&b){a=a*b;}
	friend inline modular operator^(modular a,ll p){modular ans=1;for(;p;p>>=1,a*=a)if(p&1)ans*=a;return ans;}
	friend inline void operator^=(modular&a,const ll&p){a=a^p;}
	friend inline modular operator^(modular a,int p){modular ans=1;for(;p;p>>=1,a*=a)if(p&1)ans*=a;return ans;}
	friend inline void operator^=(modular&a,const int&p){a=a^p;}	
	friend inline modular inv(const modular&a){return a^(mod-2);}
	friend inline modular operator/(const modular&a,const modular&b){return modular(a*inv(b));}
	friend inline void operator/=(modular&a,const modular&b){a=a/b;}	
};
typedef modular<int> mi;
struct F{
	mi x,y;
	F(mi x=mi(0),mi y=mi(0)):x(x),y(y){}
	friend inline F operator+(F a,F b){return F(a.x+b.x,a.y+b.y);}
	friend inline void operator+=(F&a,F b){a=a+b;}
	friend inline F operator-(F a,F b){return F(a.x-b.x,a.y-b.y);}
	friend inline void operator-=(F&a,F b){a=a-b;}
	friend inline F operator/(F a,mi b){return F(a.x/b,a.y/b);}
	friend inline void operator/=(F&a,mi b){a=a/b;}
	friend inline F operator*(F a,mi b){return F(a.x*b,a.y*b);}
	friend inline void operator*=(F&a,mi b){a=a*b;}
	friend inline bool operator<(F a,F b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
	friend inline bool operator==(F a,F b){return a.x==b.x&&a.y==b.y;}
	inline mi mod()const{return x*x+y*y;}
}a[N],G,O1,O2;
int W;
inline int rd(){return rand()|(rand()<<15);}
struct cp{
	int x,y;
	cp(int x=0,int y=0):x(x),y(y){}
	friend inline cp operator*(cp a,cp b){return cp(add(mul(a.x,b.x),mul(W,mul(a.y,b.y))),add(mul(a.x,b.y),mul(a.y,b.x)));}
	friend inline cp operator^(cp a,ll p){cp res=cp(1,0);for(;p;p>>=1,a=a*a)if(p&1)res=res*a;return res;}
};
inline int Sqrt(int x){
	if(x==0)return 0;
	if(ksm(x,(mod-1)>>1)==mod-1)return -1;
	int a;
	while(1){
		a=(rd()%mod+mod)%mod,W=dec(mul(a,a),x);
		if(ksm(W,(mod-1)>>1)==mod-1){
			int res=(cp(a,1)^((mod+1)>>1)).x;
			return min(res,mod-res);
		}
	}
}
int n;
inline mi sq(mi x){return x*x;}
inline ll fix(mi x){
	int res=(int)x;
	if(res>abs(res-mod))res-=mod;
	return res;
}
vector<pair<ll,ll> >res;
ll d[N],_d[N];
inline ll dist(ll x,ll y,ll a,ll b){return (x-a)*(x-a)+(y-b)*(y-b);}
inline void check(F pt,ll dis){
	ll dx=fix(pt.x),dy=fix(pt.y);
	if(dist(dx,dy,(int)a[1].x,(int)a[1].y)!=dis)return;
	for(ri i=1;i<=n;++i)_d[i]=dist(dx,dy,(int)a[i].x,(int)a[i].y);
	sort(_d+1,_d+n+1);
	for(ri i=1;i<=n;++i)if(_d[i]!=d[i])return;
	res.pb(make_pair(dx,dy));
}
inline void modify(F o1,mi r1,F o2,mi r2,ll dis){
	mi a=(o1.x-o2.x)*2,b=(o1.y-o2.y)*2,c=r2-r1+o1.mod()-o2.mod();
	if(a!=0){
		b=b/a,c=c/a;
		mi A=b*b+1,B=(b*o1.x-b*c-o1.y)*2,C=(c-o1.x)*(c-o1.x)+o1.y*o1.y-r1,delta;
		B/=A,C/=A;
		delta=B*B-C*4;
		int res=Sqrt(delta.vl);
		mi x,y;
		if(res==-1)return;
		y=(-B+res)/2,x=c-y*b;
		check(F(x,y),dis);
		y=(-B-res)/2,x=c-y*b;
		check(F(x,y),dis);
	}
	else{
		mi y=c/b;
		int s=Sqrt((r1-sq(o1.y-y)).vl);
		if(s==-1)return;
		check(F(o1.x+s,y),dis);
		check(F(o1.x-s,y),dis);
	}
}
mi dall=mi(0),Dall=mi(0),R1,R2;
int main(){
	srand(time(NULL));
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i].x=read(),a[i].y=read(),G=G+a[i],dall-=a[i].mod();
	G=G/mi(n);
	if(a[1]==G)swap(a[1],a[2]);
	O1=G;
	O2=a[1];
	dall+=n*G.mod();
	for(ri tt=read();tt;--tt){
		Dall=dall;
		for(ri i=1;i<=n;++i)d[i]=readl(),Dall+=d[i];
		sort(d+1,d+n+1);
		res.clear();
		R1=Dall/n;
		for(ri i=1;i<=n;++i){
			if(i!=1&&d[i]==d[i-1])continue;
			R2=d[i];
			modify(O1,R1,O2,R2,d[i]);
		}
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		cout<<res.size()<<' ';
		for(ri i=0;i<res.size();++i)cout<<res[i].fi<<' '<<res[i].se<<' ';
		puts("");
	}
	return 0;
}