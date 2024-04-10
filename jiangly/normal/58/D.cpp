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
	template<class T>const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
}
using namespace algo;
const int MAXN=10000,MAXL=12;
int n,suml,ln;
int len[MAXN];
char s[MAXN][MAXL];
char d;
struct cmp1{
	bool operator()(int a,int b){
		return strcmp(s[a],s[b])<0;
	}
};
std::set<int,cmp1>pos[MAXL];
struct cmp2{
	bool operator()(int a,int b){
		s[a][len[a]]=d;
		s[b][len[b]]=d;
		bool ans=(strcmp(s[a],s[b])<0);
		s[a][len[a]]=0;
		s[b][len[b]]=0;
		return ans;
	}
};
std::set<int,cmp2>st;
void solve(){
	n=read_int();
	for(int i=0;i!=n;++i)
		suml+=(len[i]=read_string(s[i]));
	d=read_char();
	for(int i=0;i!=n;++i){
		pos[len[i]].insert(i);
		st.insert(i);
	}
	ln=suml/(n>>1);
	for(int i=0;i!=(n>>1);++i){
		int u=*st.begin();
		printf("%s%c",s[u],d);
		st.erase(u);
		pos[len[u]].erase(u);
		u=*pos[ln-len[u]].begin();
		st.erase(u);
		pos[len[u]].erase(u);
		puts(s[u]);
	}
}
int main(){
	solve();
	return 0;
}