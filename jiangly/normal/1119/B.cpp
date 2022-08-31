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
    template<class T>inline void fill(T*a,T*b,const T&c){
        for(;a!=b;*a++=c);
    }
}
using namespace algo;
const int MAXN=1000;
int n,h;
int a[MAXN],p[MAXN];
bool check(int x){
    int cur=0;
    ll tot=0;
    for(int i=0;i<n;++i)
        if(p[i]<x&&++cur&1)
            tot+=a[p[i]];
    return tot<=h;
}
void solve(){
    n=read_int();
    h=read_int();
    for(int i=0;i<n;++i)
        a[i]=read_int();
    for(int i=0;i<n;++i)
        p[i]=i;
    std::sort(p,p+n,[](int i,int j){return a[i]>a[j];});
    int l=1,r=n;
    for(;l!=r;){
        int mid=l+r+1>>1;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    printf("%d\n",l);
}
int main(){
    solve();
	return 0;
}