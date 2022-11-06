#include<bits/stdc++.h>
#define ri register int
using namespace std;

//MoBan
namespace MoBan{
//Type
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long Ull;
typedef unsigned int uii;
typedef const int csi;

// Pair
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
#define fi first
#define se second

//Vector
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pli> vli;
typedef vector<pil> vil;
#define pb push_back

//Map
typedef map<int,int> mii;
typedef map<ll,int> mli;
typedef map<int,bool> mbi;

//Set
typedef set<int> si;
typedef set<pii> sii;
typedef set<pli> sli;
typedef set<pil> sil;
typedef set<pll> sll;
#define ins insert
#define del erase

const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)

//Input
inline int read(){
	bool f=1;
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	while(isalpha(ch))s[++top]=ch,ch=gc();
	return top;
}

//File
inline void file(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	freopen("lx.out","w",stdout);
	#endif
}

//Functions
template<typename T>inline void ckmax(T&a,T b){a<b?a=b:0;}
template<typename T>inline void ckmin(T&a,T b){a>b?a=b:0;}
}
using namespace MoBan;

//Modular
namespace modular{
	const int mod=1e9+7;
	inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
	inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Add(int&a,int b){a=a+b<mod?a+b:a+b-mod;}
	inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
	inline int Inv(csi&a){return ksm(a,mod-2);}
	inline int fix(csi&a){return (a%mod+mod)%mod;}
}
using namespace modular;

//My sol
const int N=5e5+5,inf=1e9+7;
int n,a[N],ft[N],m,ans[N],sum[N],idx[N],vl[N],pre[N],top=0,pw[N],ipw[N],ss[N];
pii stk[N];
vector<pii>qry[N];
inline int find(int x){return ft[x]^x?ft[x]=find(ft[x]):x;}
inline int calc(int l,int r){return mul(ipw[l],dec(ss[r],ss[l-1]));}

//Main
signed main(){
	file();
	n=read(),m=read();
	pw[0]=ipw[0]=1;
	for(ri i=1;i<=n;++i){
		a[i]=read(),ft[i]=i;
		pw[i]=add(pw[i-1],pw[i-1]);
		ipw[i]=mul(ipw[i-1],mod+1>>1);
	}
	for(ri i=1,l,r;i<=m;++i){
		l=read(),r=read();
		qry[r].pb(pii(l,i));
	}
	for(ri i=1;i<=n;++i){
		ss[i]=add(ss[i-1],mul(pw[i],fix(a[i])));
		idx[i]=++top;
		stk[top]=pii(i,i);
		sum[top]=a[i];
		vl[top]=fix(a[i]);
		while(top>1&&sum[top]>0){
			int fx=find(stk[top].fi),fy=find(stk[top-1].fi);
			ft[fx]=fy;
			if(stk[top-1].se-stk[top-1].fi+1>=30||sum[top]==inf||sum[top-1]==inf)sum[top-1]=inf;
			else sum[top-1]=min((ll)inf,(((ll)sum[top])<<(stk[top-1].se-stk[top-1].fi+1))+sum[top-1]);
			vl[top-1]=add(mul(pw[stk[top-1].se-stk[top-1].fi+1],vl[top]),vl[top-1]);
			stk[top-1].se=stk[top].se;
			--top;
		}
		pre[top]=add(pre[top-1],vl[top]);
		for(ri res=0,j=0,l,r,L,R,id;j<qry[i].size();++j){
			l=qry[i][j].fi,r=i,id=qry[i][j].se;
			L=idx[find(l)],R=idx[find(r)];
			ans[id]=add(calc(l,stk[L].se),mul(2,dec(pre[R],pre[L])));
		}
	}
	for(ri i=1;i<=m;++i)cout<<ans[i]<<'\n';
	return 0;
}