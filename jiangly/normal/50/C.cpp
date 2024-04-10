#include<bits/stdc++.h>
const int MAXN=100000,inf=1e9;
namespace FastIO{
	const int BUF_SIZE=1<<22;
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
template<class T>const T&min(const T&a,const T&b){
	return a<b?a:b;
}
template<class T>const T&max(const T&a,const T&b){
	return a>b?a:b;
}
int n;
int Max[2],Min[2];
void solve(){
	for(int i=0;i<2;++i){
		Min[i]=inf;
		Max[i]=-inf;
	}
	n=read_int();
	for(int i=0;i<n;++i){
		int x=read_int(),y=read_int();
		Max[0]=max(Max[0],x+y);
		Min[0]=min(Min[0],x+y);
		Max[1]=max(Max[1],x-y);
		Min[1]=min(Min[1],x-y);
	}
	printf("%d\n",Max[0]-Min[0]+Max[1]-Min[1]+4);
}
int main(){
	solve();
	return 0;
}