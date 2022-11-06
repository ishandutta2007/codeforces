#include<bits/stdc++.h>
#define ri register int
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
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
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
const int N=3e5+5;
int a[N],n;
ll sta[N];
inline int sgn(ll x){return (x>0ll)-(x<0ll);}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	ll res=0,sum=0;
	for(ri i=1;i<=n;++i){
		a[i]=read(),sta[i]=readl();
		sum+=a[i];
	}
	if(sum<0)for(ri i=1;i<=n;++i)a[i]=-a[i];
	for(ri s=0;s<62;++s){
		ll ss=0;
		for(ri i=1;i<=n;++i)if((sta[i]>>s&1)&&(sta[i]<(1ll<<s+1)))ss+=a[i];
		if(ss>0){
			res|=1ll<<s;
			for(ri i=1;i<=n;++i)if(sta[i]>>s&1)a[i]=-a[i];
		}
	}
	cout<<res;
	return 0;
}