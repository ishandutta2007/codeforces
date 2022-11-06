#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
typedef pair<int,int> pii;
typedef long long ll;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
inline int Read(char*s){
	int top=0;
	char ch=gc();
	while(!isalpha(ch))ch=gc();
	while(isalpha(ch))s[++top]=ch,ch=gc();
	return top;
}
int n,c[5];
char s[100005];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	Read(s);
	for(ri i=1;i<=n;++i){
		if(s[i]=='z')++c[0];
		if(s[i]=='e')++c[1];
		if(s[i]=='r')++c[2];
		if(s[i]=='o')++c[3];
		if(s[i]=='n')++c[4];
	}
	for(ri i=1,up=min(c[4],min(c[3],c[1]));i<=up;++i)--c[4],--c[3],--c[1],cout<<1<<' ';
	for(ri i=1,up=min(min(c[0],c[1]),min(c[2],c[3]));i<=up;++i)cout<<0<<' ';
	return 0;
}