#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
	#undef gc
}
typedef pair<int,int> pii;
typedef long long ll;
inline ll readl(){
	#define gc getchar
	ll ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
	#undef gc
}
const int mod=998244353;
typedef vector<int> poly;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:a-=mod;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=1e5+5;
int n,pre[N],dis[129][129],f[129][129];
vector<int>pos[N];
int vl[N],sig=0;
inline int find(int x){return lower_bound(vl+1,vl+sig+1,x)-vl;}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i){
		ll x;
		x=readl();
		vector<int>t;
		for(ri j=63;~j;--j){
			if(!(x>>j&1))continue;
			pos[j].push_back(i);
		}
	}
	for(ri j=0;j<64;++j){
		if(pos[j].size()>2)return cout<<3,0;
		if(pos[j].size()<2)continue;
		vl[++sig]=pos[j][0];
		vl[++sig]=pos[j][1];
	}
	sort(vl+1,vl+sig+1),sig=unique(vl+1,vl+sig+1)-vl-1;
	memset(dis,0x3f,sizeof(dis)),memset(f,0x3f,sizeof(f));
	for(ri j=0;j<64;++j){
		if(pos[j].size()>2)return cout<<3,0;
		if(pos[j].size()<2)continue;
		int a=find(pos[j][0]),b=find(pos[j][1]);
		dis[a][b]=dis[b][a]=1;
		f[a][b]=f[b][a]=1;
	}
	int ans=dis[0][0],tmp=ans;
	n=sig;
	for(int k=1;k<=n;++k){
	    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
	        if(i!=j&&j!=k&&k!=i)ans=min((ll)ans,(ll)dis[i][j]+f[i][k]+f[k][j]);
	    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
	        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans==tmp)puts("-1");
	else cout<<ans;
	return 0;
}