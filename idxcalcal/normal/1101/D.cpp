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
int mod;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline void Add(int&a,int b){a=add(a,b);}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline void Dec(int&a,int b){a=dec(a,b);}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=2e5+5;
int n,a[N],tim[N],timm[N];
vector<pii>E[N];
vector<int>e[N];
int dist=0,len[N];
void dfs(int p,int ft,int ct){
	len[p]=1;
	timm[p]=ct;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==ft)continue;
		dfs(v,p,ct);
		dist=max(dist,len[p]+len[v]);
		len[p]=max(len[p],len[v]+1);
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i){
		a[i]=read();
		if(a[i]>1){
			dist=1;
		}
	}
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		E[__gcd(a[u],a[v])].pb(pii(u,v));
	}
	for(ri i=2;i<=200000;++i){
		vector<int>t;
		for(ri j=i;j<=200000;j+=i){
			for(ri u,v,k=0;k<E[j].size();++k){
				u=E[j][k].fi,v=E[j][k].se;
				if(tim[u]!=i){
					t.pb(u);
					tim[u]=i;
					e[u].clear();
				}
				if(tim[v]!=i){
					t.pb(v);
					tim[v]=i;
					e[v].clear();
				}
				e[u].pb(v),e[v].pb(u);
			}
		}
		for(ri k=0;k<t.size();++k){
			if(timm[t[k]]!=i)dfs(t[k],0,i);
		}
		t.clear();
	}
	cout<<dist;
	return 0;
}