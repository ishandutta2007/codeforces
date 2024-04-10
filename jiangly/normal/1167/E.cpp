// remote judge by luogu
// the 4th time
#include<bits/stdc++.h>
typedef long long ll,int64,LL;
const int inf=1e9;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	inline char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	inline int read_int(){
		int ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	inline char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	inline int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
namespace algo{
	template<class T>inline const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>inline const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
	template<class T>inline void swap(T&a,T&b){
		T c=a;
		a=b;
		b=c;
	}
	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	inline int sq(int x){
		return x*x;
	}
}
using namespace algo;
const int MAXN=1000000;
int n,x;
int a[MAXN],pre[MAXN],suf[MAXN],g[MAXN],f[MAXN];
bool cmp(int i,int j){
	return a[i]!=a[j]?a[i]<a[j]:i<j;
}
void solve(){
	n=read_int();
	x=read_int();
	for(int i=0;i!=n;++i)
		a[i]=read_int()-1;
	pre[0]=a[0];
	for(int i=1;i!=n;++i)
		pre[i]=max(pre[i-1],a[i]);
	suf[n-1]=a[n-1];
	for(int i=n-2;~i;--i)
		suf[i]=min(suf[i+1],a[i]);
	memset(g,0x3f,sizeof(g));
	for(int i=0;i!=n;++i)
		g[a[i]]=min(g[a[i]],suf[i]);
	int maxl=0;
	for(;maxl!=x-1&&g[maxl]>=maxl;++maxl);
	memset(g,-1,sizeof(g));
	for(int i=0;i!=n;++i)
		g[a[i]]=max(g[a[i]],pre[i]);
	int minr=x-1;
	for(;minr!=0&&g[minr]<=minr;--minr);
	ll ans=0;
	for(int i=0;i<=maxl;++i){
		minr=max(minr,max(i,i?g[i-1]:0));
		ans+=x-minr;
	}
	printf("%I64d\n",ans);
}
int main(){
	solve();
	return 0;
}