// remote judge by luogu
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
const int MAXN=500000;
int n,m;
int fa[MAXN],sz[MAXN];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(){
	n=read_int();
	for(int i=0;i!=n;++i){
		fa[i]=i;
		sz[i]=1;
	}
	m=read_int();
	for(int i=0;i!=m;++i){
		int k=read_int();
		int last=-1;
		for(int i=0;i!=k;++i){
			int x=read_int()-1;
			if(~last&&find(last)!=find(x)){
				sz[fa[last]]+=sz[fa[x]];
				fa[fa[x]]=fa[last];
			}
			last=x;
		}
	}
	for(int i=0;i!=n;++i)
		printf("%d ",sz[find(i)]);
}
int main(){
	solve();
	return 0;
}