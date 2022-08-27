#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
const int mo=1e9+7;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

class Bignum{
	private:
		vector<int>a;
		void clear(){a.resize(1);a[0]=0;}
		void set(int n){
			if(clear(),n){			
				int t;a.clear();
				while(n)a.push_back(n-(t=n/10000)*10000),n=t;
			}
		}
		void set(long long n){
			if(clear(),n){			
				long long t;a.clear();
				while(n)a.push_back(n-(t=n/10000)*10000),n=t;
			}
		}
		void clearzero(){
			int l=a.size();
			while(l>1 && a[l-1]==0)l--;
			a.resize(l);
		}
		void set(char*st){
			char c;vector<int> s;a.clear();
			while(((c=*(st++))<'0' || c>'9'));s.push_back(c-'0');
			while((c=*(st++))>='0'&&c<='9')s.push_back(c-'0');          
			int l=s.size();
			for (int i=l-1;i-3>=0;i-=4)a.push_back(s[i]+s[i-1]*10+s[i-2]*100+s[i-3]*1000);
			if(l&3){
				int tmp=0;
				for (int i=0;i<(l&3);i++)tmp=tmp*10+s[i];
				a.push_back(tmp);
			}
			clearzero();
		}
	public:
		Bignum(){clear();}
		Bignum(int n){set(n);}
		Bignum(long long n){set(n);}
		Bignum(char*s){set(s);}
		Bignum& operator=(int a){set(a);return *this;}
		Bignum& operator=(long long a){set(a);return *this;}
		Bignum& operator=(char *s){set(s);return *this;}
		int size()const{
			if(a.back()>=1000)return a.size()<<2;
			else if(a.back()>=100)return (a.size()<<2)-1;
			else if(a.back()>=10)return (a.size()<<2)-2;
			else return (a.size()<<2)-3;
		}
		long long toint()const{
			long long ans=0;
			for (int i=int(a.size())-1;i>=0;i--)ans=ans*10000+a[i];
			return ans;
		}
		int tostr(char *s)const{
			int tot=0;
			for (unsigned int i=0;i<a.size();i++)
				if(i+1==a.size()){
					int x=a[i];
					while(x)s[tot++]='0'+x%10,x/=10;
				}else{
					int x=a[i];
					for (int j=0;j<4;j++)s[tot++]='0'+x%10,x/=10;
				}
			if(tot==0)s[tot++]='0';
			for (int i=0,j=tot-1;i<j;i++,j--)swap(s[i],s[j]);
			s[tot]=0;
			return tot;
		}
		int toarr(int *s)const{
			int tot=0;
			for (unsigned int i=0;i<a.size();i++)
				if(i+1==a.size()){
					int x=a[i];
					while(x)s[tot++]=x%10,x/=10;
				}else{
					int x=a[i];
					for (int j=0;j<4;j++)s[tot++]=x%10,x/=10;
				}
			if(tot==0)s[tot++]=0;
			return tot;
		}
		int comp(const Bignum&x)const{
			if(a.size()<x.a.size())return 1;
			if(a.size()>x.a.size())return -1;
			for (int i=a.size()-1;i>=0;i--)
				if(a[i]<x.a[i])return 1;
				else if(a[i]>x.a[i])return -1;
			return 0;
		}
		bool operator<(const Bignum&x)const{return comp(x)==1;}
		bool operator>(const Bignum&x)const{return comp(x)==-1;}
		bool operator<=(const Bignum&x)const{return comp(x)!=-1;}
		bool operator>=(const Bignum&x)const{return comp(x)!=1;}
		bool operator!=(const Bignum&x)const{return comp(x)!=0;}
		bool operator==(const Bignum&x)const{return comp(x)==0;}	
		Bignum& operator+=(const Bignum&x){
			int l=max(a.size(),x.a.size())+1;
			a.resize(l);
			for (unsigned int i=0;i<x.a.size();i++)a[i]+=x.a[i];
			for (int i=0;i<l;i++)if(a[i]>=10000)a[i]-=10000,a[i+1]++;
			clearzero();return *this;
		}
		Bignum& operator-=(const Bignum&x){
			for (unsigned int i=0;i<x.a.size();i++)a[i]-=x.a[i];
			for (unsigned int i=0;i<a.size();i++)if(a[i]<0)a[i]+=10000,a[i+1]--;
			clearzero();return *this;
		}
		Bignum operator+(const Bignum&x)const{Bignum y=*this;y+=x;return y;}		
		Bignum operator-(const Bignum&x)const{Bignum y=*this;y-=x;return y;}		
		Bignum operator*(const Bignum&x)const{
			int l=a.size()+x.a.size();
			Bignum z;z.a.clear();
			vector<long long>tmp;tmp.resize(l);
			for (unsigned int i=0;i<x.a.size();i++)
				for (unsigned int j=0;j<a.size();j++)
					tmp[i+j]+=x.a[i]*a[j];
			for (int i=0;i<l;i++){
				long long t=tmp[i]/10000;
				z.a.push_back(int(tmp[i]-t*10000));
				t?tmp[i+1]+=t:0;
			}
			z.clearzero();return z;
		}
		Bignum operator*(long long x)const{
			if(x>=10000)return *this * Bignum(x);
			int l=a.size()+2;
			Bignum z;z.a.resize(l);
			for (unsigned int i=0;i<a.size();i++)z.a[i]=a[i]*x;
			for (int i=0,t;i<l;i++)z.a[i+1]+=(t=z.a[i]/10000),z.a[i]-=t*10000;
			z.clearzero();return z;
		}
		friend Bignum operator*(long long x,const Bignum&a){return a*x;}
		Bignum& operator*=(long long x){return *this=*this*x;}
		Bignum& operator*=(const Bignum&x){return *this=*this*x;}		
		Bignum operator/(const Bignum &x)const{
			Bignum b=*this,q,tmp;q.a.resize(b.a.size());	
			for(int i=int(b.a.size())-int(x.a.size());b>=x;i--,b.clearzero()){
				tmp.a.assign(b.a.begin()+i,b.a.end());				
				int l=0,r=10000-1,m;
				while(l<=r){
					m=(l+r)>>1;
					if(x*m<=tmp)l=m+1;
					else r=m-1;
				}
				for (unsigned int j=0;j<tmp.a.size();j++)b.a[j+i]=0;
				q.a[i]=r;tmp-=x*r;
				for (unsigned int j=0;j<tmp.a.size();j++)b.a[j+i]=tmp.a[j];
			}
			q.clearzero();return q;
		}
		Bignum operator%(const Bignum &x)const{return *this-*this/x*x;}
		Bignum& operator/=(const Bignum &x){return *this=*this/x;}
		Bignum& operator%=(const Bignum &x){return *this=*this%x;}

		Bignum& operator/=(long long x){
			if(x>(1ll<<40))return *this/=Bignum(x);
			else{
				if(x==1)return *this;
				long long cur=0;
				for (int i=int(a.size())-1;i>=0;i--){
					cur=cur*10000+a[i];
					a[i]=cur/x;
					cur%=x;
				}
				clearzero();
				return *this;
			}
		}
		Bignum operator/(long long x)const{
			if(x>(1ll<<40))return *this/Bignum(x);
			else{
				Bignum y=*this;y/=x;return y;
			}
		}
		long long operator%(long long x)const{
			if(x>(1ll<<40))return (*this%Bignum(x)).toint();
			else{
				if(x==1)return 0;
				long long ans=0;
				for (int i=int(a.size())-1;i>=0;i--)ans=(ans*10000+a[i])%x;
				return ans;
			}
		}
		int operator%(int x)const{
			return int(operator%((long long)x));
		}
		Bignum& operator%=(long long x){
			if(x>(1ll<<40))return *this%=Bignum(x);
			else return *this=*this%x;
		}
		int to2(int *s)const{
			int tot=0;
			vector<unsigned long long>t;
			for (unsigned int i=0;i<a.size();i++)t.push_back((unsigned long long)a[i]);
			while(!t.empty()){
				for (int i=int(t.size())-1;i>=0;i--){
					unsigned long long r=t[i]>>32;
					if(i==0){
						s[tot++]=int(t[i]&0xffffffff);
					}else{
						t[i-1]+=(t[i]&((unsigned long long)0xffffffff))*10000;
					}
					t[i]=r;
				}
				while(!t.empty() && t.back()==0)t.pop_back();
			}
			return tot;
		}
		bool input(){
			char c;vector<int> s;a.clear();
			while(((c=getchar())<'0' || c>'9') && c!=EOF);
			if(c==EOF){a.push_back(0);return 0;}
			s.push_back(c-'0');
			while((c=getchar())>='0'&&c<='9')s.push_back(c-'0');          
			int l=s.size();
			for (int i=l-1;i-3>=0;i-=4)a.push_back(s[i]+s[i-1]*10+s[i-2]*100+s[i-3]*1000);
			if(l&3){
				int tmp=0;
				for (int i=0;i<(l&3);i++)tmp=tmp*10+s[i];
				a.push_back(tmp);
			}
			clearzero();
			return 1;
		}
		void output()const{
			for (int i=int(a.size())-1;i>=0;i--)
				if(i==int(a.size())-1)printf("%d",a[i]);
				else printf("%04d",a[i]);
		}
		void outputln()const{
			output();putchar('\n');
		}
		friend Bignum max(const Bignum &a,const Bignum &b){return a>b?a:b;}
		friend Bignum min(const Bignum &a,const Bignum &b){return a<b?a:b;}
};
int n;
int a[333333];
int b[333333];
int r[333333];
//char str[33333];

int num[33333];int len;
int dv(int m){
	ll cur=0;
	for (int i=len-1;i>=0;i--){
		cur=cur*10+num[i];
		num[i]=cur/m;
		cur=cur%m;
	}
	while(len>=1 && num[len-1]==0)len--;
	return cur;
}

int f[3333333];//f[0..len-1]
int fne[3333333];
int tmpf[3333333];

void mulpo(int d){//mul (1+x+..+x^d)
	rep(i,len,len+d)f[i]=0;
	rep(i,1,len+d)upmo(f[i],f[i-1]);
	for (int i=len+d-1;i>=0;i--){
		int su=f[i]-(i-d-1<0?0:f[i-d-1]);
		f[i]=su;
		upmo(f[i],0);
	}
	len+=d;
}
Bignum rd;
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	//n=300000;
	rep(i,1,n){
		gn(a[i]);
		//a[i]=2;
	}
	a[n]=2e9;
	rep(i,1,n+1){
		gn(b[i]);
		//b[i]=1;
	}

	//gs(str);
	/*rep(i,0,10000)str[i]='0';
	str[10000]=0;
	str[0]='1';*/
	rd.input();

	//len=strlen(str);
	//rep(i,0,len)num[i]=str[len-i-1]-'0';

	int cur=1;int start=1;
	rep(i,1,n+1){
		cur*=a[i];
		if(i==n || 1ll*cur*a[i+1]>1e9){
			int rr=rd%cur;
			rd/=cur;
			rep(j,start,i+1){
				r[j]=rr%a[j];
				rr/=a[j];
			}
			cur=1;
			start=i+1;
		}
	}
	//debug("time: %d\n",int(clock()-_time_jc));
	f[0]=1;
	len=1;
	rep(i,1,n+1)if(i==1 || a[i-1]!=1){
		int j=i+1;
		while(j<=n && a[j-1]==1)j++;
		j--;
		//[i,j]

		rep(k,i,j+1)mulpo(b[k]);
		//debug("%d\n",len);

		int t,tt;
		for (t=r[j],tt=0;t<len;t+=a[j],tt++){
			fne[tt]=f[t];
		}
		len=tt;
		rep(k,0,len)f[k]=fne[k];
	}
	printf("%d\n",len>=1?f[0]:0);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}