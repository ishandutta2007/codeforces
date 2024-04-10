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
const int N=5e5+5;
char s[N];
int n;
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=Read(s);
	int premn=26;
	for(ri i=1;i<=n;++i){
		int x=s[i]-'a';
		if(premn<x){
			puts("Ann");
		}
		else puts("Mike");
		premn=min(premn,x);
	}
	return 0;
}