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
const int MAXN=300;
int t,n;
int p[MAXN];
void solve(){
    n=read_int();
    for(int i=0;i<n;++i)
        p[i]=read_int();
    std::sort(p,p+n);
    ll x=1ll*p[0]*p[n-1];
    for(int i=0;i<n;++i)
    	if(1ll*p[i]*p[n-i-1]!=x)
    		return void(puts("-1"));
    int cnt=0;
    bool is_sq=0;
    for(int i=2;1ll*i*i<=x;++i){
        cnt+=x%i==0;
        is_sq=1ll*i*i==x;
    }
    if(n==(cnt<<1)-is_sq)
        printf("%I64d\n",x);
    else
        puts("-1");
}
int main(){
    t=read_int();
    for(;t;--t)
        solve();
	return 0;
}