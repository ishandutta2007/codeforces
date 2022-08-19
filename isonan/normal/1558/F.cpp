#include <cstdio>
#include <algorithm>

int t;
int n,a[200001],p[200001];
int se[2000001],lazy[2000001];
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
	lazy[root]=0;
	se[root]=r-1;
	if(l==r)return;
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
	se[root]=std::max(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	spread(root);
	return std::max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int L[200001],R[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),p[a[i]]=i;
		build(1,1,n);
		for(int i=2;i<=n;i+=2)update(1,1,n,i,i,1);
		L[n+1]=n+1;
		for(int i=n;i;--i)L[i]=std::min(L[i+1],p[i]);
		R[0]=0;
		for(int i=1;i<=n;++i)R[i]=std::max(R[i-1],p[i]);
		int ans=0;
		for(int i=1;i<=n;++i){
			int x=p[i];
			update(1,1,n,1,x-1,1);
			update(1,1,n,x+1,n,-1);
			update(1,1,n,x,x,((x&1)?1:-1));
			ans=std::max(ans,query(1,1,n,L[i+1],R[i]));
		}
		printf("%d\n",ans);
	}
}