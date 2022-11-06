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
const int N=2e5+5;
int n;
bool vs[N];
ll a[N];
bool in[N];
vector<ll>vl[105];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	set<int>A,B;
	for(ri i=1;i<=n;++i){
		ll x=readl(),s=x,t=0;
		while(!(s&1))s>>=1,++t;
		vl[t].pb(x);
	}
	int mx=0;
	for(ri i=0;i<63;++i)mx=max(mx,(int)vl[i].size());
	cout<<n-mx<<'\n';
	bool ff=1;
	for(ri i=0;i<63;++i){
		if(vl[i].size()==mx&&ff){ff=0;continue;}
		for(ri j=0;j<vl[i].size();++j)cout<<vl[i][j]<<' ';
	}
	return 0;
}