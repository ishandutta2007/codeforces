#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef unsigned long long Ull;
typedef unsigned int uii;
typedef tr1::unordered_map<int,int>::iterator It;
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
namespace modular{
	const int mod=376544743;
	inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
	inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Add(int&a,int b){a=a+b<mod?a+b:a+b-mod;}
	inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
	inline int Inv(int a){return ksm(a,mod-2);}
	inline void fix(int&a){a=(a%mod+mod)%mod;}
}
using namespace modular;
template<typename T>inline void ckmin(T&a,T b){a>b?a=b:0;}
template<typename T>inline void ckmax(T&a,T b){a<b?a=b:0;}
const int N=1e5+5;
int cur=0,a[N],n,K,cnt[N],ql,qr;
ll f[2][N],res=0;
inline void move(int l,int r){
	while(qr<r)++qr,res+=cnt[a[qr]],++cnt[a[qr]];
	while(qr>r)--cnt[a[qr]],res-=cnt[a[qr]],--qr;
	while(ql<l)--cnt[a[ql]],res-=cnt[a[ql]],++ql;
	while(ql>l)--ql,res+=cnt[a[ql]],++cnt[a[ql]];
}
inline ll calc(int x,int p){
	move(x,p);
	return f[cur^1][x-1]+res;
}
inline void solve(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R){
		for(ri i=l;i<=r;++i)f[cur][i]=calc(L,i);
		return;
	}
	int mid=l+r>>1,ps=L;
	ll tmp=calc(ps,mid),t;
	for(ri i=ps+1;i<=R&&i<=mid;++i)if((t=calc(i,mid))<tmp){
		tmp=t;
		ps=i;
	}
	f[cur][mid]=tmp;
	solve(l,mid-1,L,ps);
	solve(mid+1,r,ps,R);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),K=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	ql=1,qr=0;
	f[cur=0][0]=0;
	for(ri i=1;i<=n;++i)f[cur][i]=1e18;
	for(ri i=1;i<=K;++i){
		cur^=1;
		solve(1,n,1,n);
	}
	cout<<f[cur][n];
	return 0;
}