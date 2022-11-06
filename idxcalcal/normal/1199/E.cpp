#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
inline int add(const int&a,const int&b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(const int&a,const int&b){return a>=b?a-b:a-b+mod;}
inline int mul(const int&a,const int&b){return (ll)a*b%mod;}
inline void Add(int&a,const int&b){a=a+b>=mod?a+b-mod:a+b;}
inline void Dec(int&a,const int&b){a=a>=b?a-b:a-b+mod;}
inline void Mul(int&a,const int&b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=3e5+5,M=5e5+5;
int n,m,vis[N],in[N];
pii e[M];
int main(){
	for(ri tt=read();tt;--tt){
		n=read(),m=read();
		vector<int>res;
		res.clear();
		for(ri i=1,up=3*n;i<=up;++i)vis[i]=0;
		int cnt=0;
		for(ri i=1;i<=m;++i){
			e[i].fi=read(),e[i].se=read();
			if(!vis[e[i].fi]&&!vis[e[i].se])vis[e[i].fi]=vis[e[i].se]=++cnt,res.push_back(i);
		}
		if(cnt>=n){
			puts("Matching");
			for(ri i=0;i<n;++i)cout<<res[i]<<' ';
			puts("");
			continue;
		}
		res.clear();
		for(ri i=1,up=n*3;i<=up;++i)if(!vis[i])res.push_back(i);
		puts("IndSet");
		for(ri i=0;i<n;++i)cout<<res[i]<<' ';
		puts("");
	}
	return 0;
}