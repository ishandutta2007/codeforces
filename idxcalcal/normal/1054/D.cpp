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
const int N=2e5+5;
int n,a[N],all,k;
set<int>S;
map<int,int>cnt;
int ss[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	all=(1<<k)-1;
	ll ans=0;
	++cnt[0];
	for(ri i=1;i<=n;++i)a[i]=read();
	for(ri i=1,t;i<=n;++i){
		ss[i]=ss[i-1]^a[i],t=ss[i-1]^all^a[i];
		if(cnt[ss[i]]+(!a[i])>(cnt[t]+(!(a[i]^all))))a[i]^=all;
		ss[i]=ss[i-1]^a[i];
		ans+=cnt[ss[i]]+(!a[i]);
		++cnt[ss[i]];
	}	cout<<(ll)n*(n+1)/2-ans;
	return 0;
}