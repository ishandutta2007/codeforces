#include <bits/stdc++.h>
#define int long long
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;
int t,n,m,f[600100],orig[600100],cnt,prev[600100],mn[600100],l[600100],r[600100],a[600100];
int vis[600100];
struct BIT{
	long long c[600100];
	void update(int ind,long long num){
		for(;ind<=cnt;ind+=ind&-ind)c[ind]=std::min(c[ind],num);
	}
	long long query(int ind){
		long long tot=1e18;
		for(;ind;ind-=ind&-ind)tot=std::min(tot,c[ind]);
		return tot;
	}
}b1,b2;
signed main(){
	scanf("%lld",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%lld%lld",&n,&m);
		cnt=0;
		for(int i=1;i<=n;++i)scanf("%lld",a+i),orig[++cnt]=a[i];
		std::sort(a+1,a+n+1);
		for(int i=1;i<=m;++i){
			scanf("%lld%lld",l+i,r+i);
			orig[++cnt]=l[i];
			orig[++cnt]=r[i];
		}
		std::sort(orig+1,orig+cnt+1);
		cnt=std::unique(orig+1,orig+cnt+1)-orig-1;
		for(int i=1;i<=cnt;++i)vis[i]=0;
		for(int i=1;i<=n;++i)a[i]=std::lower_bound(orig+1,orig+cnt+1,a[i])-orig,vis[a[i]]=i;
		for(int i=1;i<=m;++i)l[i]=std::lower_bound(orig+1,orig+cnt+1,l[i])-orig;
		for(int i=1;i<=m;++i)r[i]=std::lower_bound(orig+1,orig+cnt+1,r[i])-orig;
		for(int i=1;i<=cnt;++i)b1.c[i]=b2.c[i]=1e18;
		mn[0]=cnt+1;
		for(int i=1,now=0;i<=cnt;++i){
			if(vis[i])now=i;
			prev[i]=now;
			mn[i]=cnt+1;
		}
		for(int i=1;i<=m;++i){
			if(prev[l[i]]!=prev[r[i]]||vis[l[i]]||vis[r[i]])continue;
			else mn[l[i]-1]=std::min(mn[l[i]-1],r[i]);
		}
		for(int i=cnt-1;~i;--i)mn[i]=std::min(mn[i],mn[i+1]);
		long long ans=1e18;
		if(mn[0]==cnt+1)ans=0;
		else b1.update(mn[0],-orig[mn[0]]),b2.update(mn[0],-2ll*orig[mn[0]]);
		if(mn[0]>a[1])b1.update(a[1],-orig[a[1]]),b2.update(a[1],-2ll*orig[a[1]]);
		b1.update(1,-orig[1]),b2.update(1,-2ll*orig[1]);
		for(int i=1;i<=cnt;++i){
			if(!prev[i])continue;
			int x=prev[i];
			long long v=std::min(2ll*orig[i]-orig[x]+b1.query(x),orig[i]+orig[x]+b2.query(x));
			// printf("%d %lld %d %d\n",i,v,prev[i],mn[i]);
			if(mn[i]==cnt+1){
				ans=std::min(ans,v);
			}
			else b1.update(mn[i],v-orig[mn[i]]),b2.update(mn[i],v-2ll*orig[mn[i]]);
			if(prev[i]&&vis[prev[i]]<n){
				int u=a[vis[prev[i]]+1];
				if(mn[i]>u)b1.update(u,v-orig[u]),b2.update(u,v-2ll*orig[u]);
			}
		}
		printf("%lld\n",ans);
	}
}