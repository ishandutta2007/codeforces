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
const int N=1e5+5;
int n,a[N],m=0,ps[N],top=0;
ll pre[N];

//Main
int main(){
	file();
	n=read();
	for(ri i=1;i<=n;++i){
		a[i]=read(),m+=a[i];
		if(a[i])ps[++top]=i,pre[top]=pre[top-1]+i;
	}
	if(!m){
		puts("0");
		return 0;
	}
	if(m==1){
		puts("-1");
		return 0;
	}
	ll _res=1e18;
	for(ri i=2;;++i){
		if(i>m)break;
		if(m%i)continue;
		ll res=0;
		for(ri l=1,r=i;l<=top;l+=i,r+=i){
			int _mid=l+r>>1;
			ll mn=1e18;
			for(ri mid=_mid-1;mid<=_mid+1;++mid){
				if(mid<l||mid>r)continue;
				ckmin(mn,(ll)ps[mid]*(mid-l+1)-(pre[mid]-pre[l-1])+(pre[r]-pre[mid])-(ll)ps[mid]*(r-mid));
			}
			res+=mn;
		}
		ckmin(_res,res);
	}
	cout<<_res;
	return 0;
}