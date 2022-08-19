#include<bits/stdc++.h>
typedef long long ll,int64,LL;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	int read_int(){
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
	char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	int read_string(char*p){
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
}
using namespace algo;
int a,b,c,d,n;
char s[50][101];
int x[26];
void solve(){
	a=read_int();
	b=read_int();
	c=read_int();
	d=read_int();
	n=read_int();
	for(int i=0;i!=n;++i)
		x[i]=read_int();
	int cur=0,cnt=0;
	for(int i=0;i!=max(b,d);++i)
		memset(s[i],'.',(a+c)*sizeof(char));
	for(int i=0;i!=a+c;++i)
		if((i^a)&1)
			for(int j=i<a?b-1:d-1;~j;--j,++cnt==x[cur]?++cur,cnt=0:0)
				s[j][i]='a'+cur;
		else
			for(int j=0;j!=(i<a?b:d);++j,++cnt==x[cur]?++cur,cnt=0:0)
				s[j][i]='a'+cur;
	puts("YES");
	for(int i=0;i!=max(b,d);++i)
		puts(s[i]);
}
int main(){
	solve();
	return 0;
}