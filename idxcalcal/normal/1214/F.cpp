#include<bits/stdc++.h>
#define int long long
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
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m,vl[N],res[N];
pii a[N],b[N];
ll sum[N];
inline void update1(int l,int r,int id,int vl){
	if(l>r)return;
	int L=(l+n-id)%n,R=(r+n-id)%n;
	if(L>R){
		sum[L]+=vl;
		sum[n]-=vl;
		sum[0]+=vl;
		sum[R+1]-=vl;
	}
	else{
		sum[L]+=vl;
		sum[R+1]-=vl;
	}
}
inline void update2(int l,int r,int id,int vl){
	if(l>r)return;
	int L=(id+n-r)%n,R=(id+n-l)%n;
	if(L>R){
		sum[L]+=vl;
		sum[n]-=vl;
		sum[0]+=vl;
		sum[R+1]-=vl;
	}
	else{
		sum[L]+=vl;
		sum[R+1]-=vl;
	}
}
signed main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	m=read(),n=read();
	for(ri i=1;i<=n;++i)a[i]=pii(read(),i);
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i)b[i]=pii(read(),i);
	sort(b+1,b+n+1);
	for(ri i=1;i<=n;++i)vl[i]=2*b[i].fi;
	for(ri i=1,p1,p2,p3;i<=n;++i){
		p1=upper_bound(vl+1,vl+n+1,2*a[i].fi-m)-vl;
		update1(1,p1-1,i,-a[i].fi);
		p2=upper_bound(vl+1,vl+n+1,2*a[i].fi)-vl;
		update1(p1,p2-1,i,a[i].fi);
		p3=upper_bound(vl+1,vl+n+1,2*a[i].fi+m)-vl;
		update1(p2,p3-1,i,-a[i].fi);
		update1(p3,n,i,m+a[i].fi);
	}
	for(ri i=1;i<=n;++i)vl[i]=2*a[i].fi;
	for(ri i=1,p1,p2,p3;i<=n;++i){
		p1=upper_bound(vl+1,vl+n+1,2*b[i].fi-m-1)-vl;
		update2(1,p1-1,i,-b[i].fi);
		p2=upper_bound(vl+1,vl+n+1,2*b[i].fi-1)-vl;
		update2(p1,p2-1,i,b[i].fi);
		p3=upper_bound(vl+1,vl+n+1,2*b[i].fi+m-1)-vl;
		update2(p2,p3-1,i,-b[i].fi);
		update2(p3,n,i,b[i].fi+m);
	}
	ll ans=1e18;
	int pos=0;
	for(ri i=0;i<n;++i){
		if(sum[i]<ans){
			ans=sum[i];
			pos=i;
		}
		sum[i+1]+=sum[i];
	}
	cout<<ans<<'\n';
	for(ri i=1,j=pos+1;i<=n;++i,j=j==n?1:j+1)res[a[i].se]=b[j].se;
	for(ri i=1;i<=n;++i)cout<<res[i]<<' ';
	return 0;
}