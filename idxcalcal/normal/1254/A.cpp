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
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(ch!='.'&&ch!='R')ch=gc();
	while(ch=='.'||ch=='R')s[++top]=ch,ch=gc();
	return top;
}

//File
inline void file(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
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
	inline int add(csi&a,csi&b){return a+b<mod?a+b:a+b-mod;}
	inline int dec(csi&a,csi&b){return a<b?a-b+mod:a-b;}
	inline int mul(csi&a,csi&b){return (ll)a*b%mod;}
	inline void Add(int&a,csi&b){a=a+b<mod?a+b:a+b-mod;}
	inline void Dec(int&a,csi&b){a=a<b?a-b+mod:a-b;}
	inline void Mul(int&a,csi&b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,1),1);return ret;}
	inline int Inv(csi&a){return ksm(a,mod-2);}
	inline void fix(int&a){a=(a%mod+mod)%mod;}
}
using namespace modular;

//My sol
const int N=205;
int n,m,K,a[N*N];
pii nxt[N][N];
char s[N][N],res[N][N];
char str[64];

//Main
int main(){
	file();
	for(ri i=1;i<=26;++i)str[i]='a'+i-1,str[i+26]='A'+i-1;
	for(ri i=1;i<=10;++i)str[i+52]='0'+i-1;
	for(ri tt=read();tt;--tt){
		n=read(),m=read(),K=read();
		int tot=0;
		for(ri i=1;i<=n;++i){
			Read(s[i]);
			for(ri j=1;j<=m;++j)res[i][j]='.';
			for(ri j=1;j<=m;++j)if(s[i][j]=='R')++tot;
			if(i&1){
				for(ri j=1;j<m;++j)nxt[i][j]=pii(i,j+1);
				nxt[i][m]=pii(i+1,m);
			}
			else{
				for(ri j=m;j>1;--j)nxt[i][j]=pii(i,j-1);
				nxt[i][1]=pii(i+1,1);
			}
		}
		for(ri i=1;i<=tot%K;++i)a[i]=tot/K+1;
		for(ri i=tot%K+1;i<=K;++i)a[i]=tot/K;
		int px=1,py=1,idxx=1;
		for(ri i=1;i<=K;++i){
			int nx,ny,cnt=s[px][py]=='R';
			res[px][py]=str[idxx];
			while(cnt!=a[i]){
				nx=nxt[px][py].fi,ny=nxt[px][py].se;
				px=nx,py=ny;
				cnt+=s[px][py]=='R';
				res[px][py]=str[idxx];
			}
			nx=nxt[px][py].fi,ny=nxt[px][py].se;
			px=nx,py=ny;
			++idxx;
		}
		--idxx;
		for(ri i=1;i<=n;++i,puts(""))for(ri j=1;j<=m;++j)cout<<(res[i][j]=='.'?str[idxx]:res[i][j]);
	}
	return 0;
}