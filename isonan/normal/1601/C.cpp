#include <cstdio>
#include <algorithm>

int t,n,m,a[1000001],b[1000001];
int orig[2000001],lim;
int c[2000001];
int se[10000001],lazy[10000001];
void pushdown(int x,int y){
	se[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int root,int l,int r){
	se[root]=lazy[root]=0;
	if(l==r){
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
void update(int ind,int num){
	for(;ind<=lim;ind+=ind&-ind)c[ind]+=num;
}
int query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
std::pair<int,int>ord[1000001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		lim=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i),orig[++lim]=a[i];
		for(int i=1;i<=m;++i)scanf("%d",b+i),orig[++lim]=b[i];
		std::sort(b+1,b+m+1);
		std::sort(orig+1,orig+lim+1);
		lim=std::unique(orig+1,orig+lim+1)-orig-1;
		for(int i=1;i<=n;++i)a[i]=std::lower_bound(orig+1,orig+lim+1,a[i])-orig;
		for(int i=1;i<=m;++i)b[i]=std::lower_bound(orig+1,orig+lim+1,b[i])-orig;
		long long ans=0;
		for(int i=1;i<=lim;++i)c[i]=0;
		for(int i=n;i;--i){
			ans+=query(a[i]-1);
			update(a[i],1);
		}
		lim=n+1;
		for(int i=1;i<=lim;++i)c[i]=0;
		build(1,1,n+1);
		for(int i=1;i<=n;++i){
			update(1,1,n+1,i+1,n+1,1);
			ord[i]=std::make_pair(a[i],i);
		}
		std::sort(ord+1,ord+n+1);
		for(int i=1,l=1,r=1;i<=m;++i){
			while(l<=n&&ord[l].first<=b[i]){
				update(1,1,n+1,ord[l].second+1,n+1,-1);
				++l;
			}
			while(r<=n&&ord[r].first<b[i]){
				update(1,1,n+1,1,ord[r].second,1);
				++r;
			}
			ans+=se[1];
		}
		printf("%lld\n",ans);
	}
}