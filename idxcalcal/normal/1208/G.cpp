#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
}
typedef long long ll;
const int N=2e6+5;
int n,k,pri[N],tot=0,phi[N];
bool vis[N];
inline void init(){
	phi[1]=1;
	for(ri i=2;i<=n;++i){
		if(!vis[i])pri[++tot]=i,phi[i]=i-1;
		for(ri j=1;j<=tot&&i*pri[j]<=n;++j){
			vis[i*pri[j]]=1;
			if(i==i/pri[j]*pri[j]){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read(),k=read();
	if(k==1)return puts("3"),0;
	init();
	sort(phi+3,phi+n+1);
	ll ans=0;
	for(ri i=3,j=1;j<=k;++j,++i)ans+=phi[i];
	cout<<ans+2;
	return 0;
}