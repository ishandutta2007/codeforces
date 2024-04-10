#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int mod=1e9+7;
typedef long long ll;
inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)<mod?a:(a-=mod);}
inline void Dec(int&a,int b){(a-=b)<0?(a+=mod):a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))if(p&1)Mul(ret,a);return ret;}
typedef pair<int,int> pii;
const int N=5005;
int n,m,f[2015][N],a[2015][N],g[N],vis[N];
struct F{int vl,id;friend inline bool operator<(F a,F b){return a.vl>b.vl;}}aa[N];
inline void movee(int p){for(ri i=1;i<=n;++i)a[i-1][p]=a[i][p];a[n][p]=a[0][p];}
inline void trans(int id){
	int up=1<<n;
	memcpy(g,f[id-1],sizeof(int)*up);
	for(ri k=0;k<n;++k){
		for(ri s=0;s<up;++s)if(!(s>>k&1)){
			g[s^(1<<k)]=max(g[s^(1<<k)],g[s]+a[k+1][id]);
		}
	}
	for(ri s=0;s<up;++s)f[id][s]=max(f[id][s],g[s]);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read(),m=read();
		for(ri i=1;i<=n;++i)for(ri j=1;j<=m;++j)a[i][j]=read();
		for(ri t,j=1;j<=m;++j){
			t=0;
			for(ri i=1;i<=n;++i)t=max(t,a[i][j]);
			aa[j]=(F){t,j};
		}
		sort(aa+1,aa+m+1);
		for(ri i=1;i<=m;++i)vis[i]=0;
		for(ri i=1,Up=min(m,50);i<=Up;++i)vis[aa[i].id]=1;
		f[0][0]=0;
		int up=1<<n;
		for(ri i=1;i<=m;++i){
			if(!vis[i]){
				memcpy(f[i],f[i-1],sizeof(int)*up);
				continue;
			}
			memset(f[i],0,sizeof(int)*up);
			for(ri j=1;j<=n;++j){
				movee(i);
				trans(i);
			}
		}
		cout<<f[m][up-1]<<'\n';
	}
	return 0;
}