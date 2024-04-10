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
const int N=1<<21|5;
int cnt[N],a[N],n,lst[N],ans=0;
inline void update(int vl,int ps){
	if(cnt[vl]>=2||lst[vl]==ps)return;
	lst[vl]=ps,++cnt[vl];
	for(ri i=21;~i;--i)if(vl>>i&1)update(vl^(1<<i),ps);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	for(ri i=1;i<=n;++i)a[i]=read();
	for(ri t,res,i=n;i;--i){
		if(i<=n-2){
			t=((1<<22)-1)^a[i],res=0;
			for(ri j=21;~j;--j)if(t>>j&1)if(cnt[res|(1<<j)]==2)res|=1<<j;
			ans=max(ans,res|a[i]);
		}
		update(a[i],i);
	}
	cout<<ans;
	return 0;
}