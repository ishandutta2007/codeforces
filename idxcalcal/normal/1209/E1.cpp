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
#define gc getchar
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
const int N=5005;
int n,m,f[N][N],a[N][N];
inline void movee(int p){for(ri i=1;i<=n;++i)a[i-1][p]=a[i][p];a[n][p]=a[0][p];}
inline int DP(int p,int s){int res=0;for(ri i=0;i<n;++i)if(s>>i&1)res+=a[i+1][p];return res;}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri up,tt=read();tt;--tt){
		n=read(),m=read();
		for(ri i=1;i<=n;++i)for(ri j=1;j<=m;++j)a[i][j]=read();
		f[0][0]=0;
		up=1<<n;
		for(ri i=1;i<=m;++i){
			for(ri s=0;s<up;++s)f[i][s]=0;
			for(ri s=0;s<up;++s){
				for(ri j=1;j<=n;++j){
					movee(i);
					for(ri ns=0;ns<up;++ns)if(!(ns&s))f[i][ns^s]=max(f[i][ns^s],f[i-1][s]+DP(i,ns));
				}
			}
		}
		cout<<f[m][up-1]<<'\n';
	}
	return 0;
}