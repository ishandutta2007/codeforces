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
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(bool*s){
	int top=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))s[++top]=ch^48,ch=gc();
	return top;
}
const int N=5e5+5;
int n,K;
ll f[N][2];
vector<pii>e[N];
void dfs(int p,int ft){
	ll ss=0;
	f[p][0]=f[p][1]=0;
	vector<ll>q;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i].fi)==ft)continue;
		dfs(v,p);
		ss+=f[v][0];
		q.pb(f[v][1]+e[p][i].se-f[v][0]);
	}
	f[p][0]=f[p][1]=ss;
	sort(q.begin(),q.end());
	for(ri i=q.size()-1,ct1=K,ct2=K-1;ct1&&~i;--i,--ct1,--ct2){
		if(q[i]<=0)break;
		f[p][0]+=q[i];
		if(ct2)f[p][1]+=q[i];
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read(),K=read();
		for(ri i=1;i<=n;++i)e[i].clear();
		for(ri i=1,u,v,w;i<n;++i){
			u=read(),v=read(),w=read();
			e[u].pb(pii(v,w));
			e[v].pb(pii(u,w));
		}
		dfs(1,0);
		cout<<f[1][0]<<'\n';
	}
	return 0;
}