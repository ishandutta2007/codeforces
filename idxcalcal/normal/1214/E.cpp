#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<tr1/unordered_map>
#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define rsz resize
#define sz(x) (int)(x).size()
#define lb lower_bound
#define rb upper_bound
#define all(x) (x).begin() (x).end()
using namespace std;
using namespace __gnu_pbds;
const int rlen=1<<18|1;
#define gc getchar
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline vector<char>Read(){
	char ch=gc();
	vector<char>res;
	res.push_back('0');
	while(!(ch=='#'||ch=='.'))ch=gc();
	while((ch=='#'||ch=='.'))res.pb(ch),ch=gc();
	return res;
}
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;	
}
inline char gch(){
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	return ch;
}
typedef pair<int,int> pii;
const int mod=998244353;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (int)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int fix(const int&x){return (x%mod+mod)%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline int sgn(int x){return (x>0)-(x<0);}
const double pi=acos(-1.0),eps=1e-16;
inline double sgn(double x){return (x>eps)-(x<-eps);}
const int N=2e5+5;
int n,id[N<<2],fa[N<<1],ft[N<<1];
struct F{int a,b,dis;friend inline bool operator<(F a,F b){return a.dis<b.dis;}}a[N];
vector<pii>e;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=(F){i*2-1,i*2,read()};
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int tot1=0,tot2=n,cur=n*2-1,len=n;
	for(ri i=1;i<n;++i)e.push_back(pii(i,i+1)),fa[i+1]=i;
	for(ri i=1;i<=n;++i)ft[i]=i;
	bool ff=1;
	for(ri i=1;i<=n;++i){
		id[++tot1]=a[i].a,id[++tot2]=a[i].b;
		fa[tot2]=tot2-1,ft[tot2]=ft[tot2-1];
		if(tot1>ft[tot2]){
			++len;
			++len;
			if(ff){
				ff=0;
				for(ri j=ft[tot2];j<n;++j)fa[j]=j+1;
			}
		}
		while(len!=a[i].dis)fa[tot2]=fa[fa[tot2]],--len;
		ft[tot2]=ft[fa[tot2]];
		e.push_back(pii(tot2,fa[tot2]));
	}
	for(ri i=e.size()-1;~i;--i)cout<<id[e[i].fi]<<' '<<id[e[i].se]<<'\n';
	return 0;
}