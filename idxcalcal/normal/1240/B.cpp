#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(bool*s){
	int top=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))s[++top]=ch^48,ch=gc();
	return top;
}
const int N=3e5+5;
int n,a[N],pmn[N],pmx[N],b[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read();
		for(ri i=1;i<=n;++i)a[i]=read(),pmn[i]=0x3f3f3f3f,pmx[i]=-0x3f3f3f3f,b[i]=a[i];
		sort(b+1,b+n+1);
		int m=unique(b+1,b+n+1)-b-1;
		for(ri i=1;i<=n;++i){
			pmn[a[i]]=min(pmn[a[i]],i);
			pmx[a[i]]=max(pmx[a[i]],i);
		}
		int len=1,mxlen=1;
		for(ri i=2;i<=m;++i){
			if(pmn[b[i]]>pmx[b[i-1]]){
				++len;
			}
			else len=1;
			mxlen=max(mxlen,len);
		}
		cout<<m-mxlen<<'\n';
	}
	return 0;
}