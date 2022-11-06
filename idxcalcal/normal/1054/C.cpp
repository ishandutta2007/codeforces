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
int n,l[N],r[N],vl[N],du[N];
vector<int>e[N];
bool vis[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i){
		l[i]=read();
		if(l[i]>i-1)return puts("NO"),0;
	}
	for(ri i=1;i<=n;++i){
		r[i]=read();
		if(r[i]>n-i)return puts("NO"),0;
	}
	vector<int>q;
	for(ri i=1;i<=n;++i)if(!(l[i]+r[i]))q.push_back(i),vl[i]=n,vis[i]=1;
	int tot=n;
	while(q.size()){
		--tot;
		while(q.size()){
			int x=q.back();
			q.pop_back();
			for(ri i=1;i<x;++i){
				if(vis[i])continue;
				--r[i];
				if(r[i]<0)return puts("NO"),0;
			}
			for(ri i=x+1;i<=n;++i){
				if(vis[i])continue;
				--l[i];
				if(l[i]<0)return puts("NO"),0;
			}
		}
		for(ri i=1;i<=n;++i){
			if(vis[i])continue;
			if(!(l[i]+r[i]))q.push_back(i),vl[i]=tot,vis[i]=1;
		}
	}
	for(ri i=1;i<=n;++i)if(!vis[i])return puts("NO"),0;
	puts("YES");
	for(ri i=1;i<=n;++i)cout<<vl[i]<<' ';
	return 0;
}