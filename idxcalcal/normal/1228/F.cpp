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
typedef vector<int> poly;
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
namespace modular{
	const int mod=1e9+7;
	inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
	inline void Add(int&a,int b){a=add(a,b);}
	inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
	inline void Dec(int&a,int b){a=dec(a,b);}
	inline int mul(int a,int b){return (ll)a*b%mod;}
	inline void Mul(int&a,int b){a=(ll)a*b%mod;}
	inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=1<<18|5;
int n,m,siz[N],Fa[N];
vector<int>e[N],RT;
#define fail puts("0"),exit(0)
void dfs(int p,int ft){
	siz[p]=1;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==ft)continue;
		Fa[v]=p;
		dfs(v,p);
		siz[p]+=siz[v];
	}
	if(siz[p]*2==n)RT.pb(p),RT.pb(ft);
}
int ban,ad[N];
bool check(int p,int ft){
	if(siz[p]==1)return 1;
	if(p==ban){
		vector<pii>tp;
		for(ri i=0,v;i<e[p].size();++i){
			if((v=e[p][i])==ft)continue;
			tp.pb(pii(siz[v],v));
		}
		sort(tp.begin(),tp.end());
		if(tp[0].fi!=tp[1].fi)fail;
		if(tp[0].fi+tp[1].fi+1!=tp[2].fi)fail;
		return check(tp[0].se,p)&&check(tp[1].se,p)&&check(tp[2].se,p);
	}
	else{
		int son1=0,son2=0;
		for(ri i=0,v;i<e[p].size();++i){
			if((v=e[p][i])==ft)continue;
			if(!son1)son1=v;
			else son2=v;
		}
		if(!son2)return 0;
		if(siz[son1]+ad[son1]!=siz[son2]+ad[son2])return 0;
		return check(son1,p)&&check(son2,p);
	}
}
bool checkk(int p,int ft){
	if(siz[p]==1)return 1;
	if(p==ban){
		vector<pii>tp;
		for(ri i=0,v;i<e[p].size();++i){
			if((v=e[p][i])==ft)continue;
			tp.pb(pii(siz[v],v));
		}
		return tp[0].fi==1;
	}
	else{
		int son1=0,son2=0;
		for(ri i=0,v;i<e[p].size();++i){
			if((v=e[p][i])==ft)continue;
			if(!son1)son1=v;
			else son2=v;
		}
		if(!son2)return 0;
		if(siz[son1]+ad[son1]!=siz[son2]+ad[son2])return 0;
		return checkk(son1,p)&&checkk(son2,p);
	}
}
void dfss(int p,int ft){
	siz[p]=1;
	int son1=0,son2=0;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==ft)continue;
		if(!son1)son1=v;
		else son2=v;
		dfss(v,p),siz[p]+=siz[v];
	}
	if(siz[son1]!=siz[son2])fail;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	m=read(),n=(1<<m)-2;
	if(n==2)return cout<<2<<'\n'<<1<<' '<<2,0;
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	int ct1=0,ct2=0,ct3=0;
	for(ri i=1;i<=n;++i){
		if(e[i].size()>4)fail;
		if(e[i].size()==4)++ct1;
		if(e[i].size()==2)++ct2;
		if(e[i].size()==3)++ct3;
	}
	if(ct1>1)fail;
	if(ct1==1){
		if(ct2!=1)fail;
		int ps;
		for(ps=1;ps<=n;++ps)if(e[ps].size()==2)break;
		for(ri i=1;i<=n;++i)if(e[i].size()==4)ban=i;
		dfs(ps,0);
		int tp=ban;
		while(tp!=ps){
			ad[tp]=1;
			tp=Fa[tp];
		}
		if(!check(ps,0))fail;
		cout<<1<<'\n';
		cout<<ban;
		return 0;
	}
	if(ct2&&ct2!=2)fail;
	if(ct2==2){
		int a=0,b=0;
		for(ri i=1;i<=n;++i)if(e[i].size()==2){
			if(!a)a=i;
			else b=i;
		}
		dfs(a,0);
		ban=b;
		while(ban!=a){
			ad[ban]=1;
			ban=Fa[ban];
		}
		ban=b;
		if(checkk(a,0))return cout<<1<<'\n'<<ban,0;
		while(ban!=a){
			ad[ban]=0;
			ban=Fa[ban];
		}
		dfs(b,0);
		ban=a;
		while(ban!=b){
			ad[ban]=1;
			ban=Fa[ban];
		}
		ban=a;
		if(checkk(b,0))return cout<<1<<'\n'<<ban,0;
		fail;
	}
	if(!ct3)fail;
	dfs(1,0);
	if(RT.size()!=2)fail;
	dfss(RT[0],RT[1]),dfss(RT[1],RT[0]);
	cout<<2<<'\n';
	cout<<min(RT[0],RT[1])<<' '<<max(RT[0],RT[1]);
	return 0;
}