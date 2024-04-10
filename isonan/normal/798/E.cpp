#include <cstdio>
#include <cassert>

int n,a[500001],b[500001];
int se[5000001];
int cmp(int lhs,int rhs){
	return b[lhs]>b[rhs]?lhs:rhs;
}
void build(int root,int l,int r){
	if(l==r){
		se[root]=l;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=cmp(se[root<<1],se[root<<1|1]);
}
void del(int root,int l,int r,int e){
	if(l==r){
		se[root]=0;
		return;
	}
	if((l+r)>>1>=e)del(root<<1,l,(l+r)>>1,e);
	else del(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=cmp(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return cmp(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
bool vis[500001];
int ans[500001],now;
void tarjan(int x){
	assert(!vis[x]);
	vis[x]=1;
	del(1,1,n,x);
	if(b[x]>=1&&b[x]<=n&&!vis[b[x]])tarjan(b[x]);
	for(;;){
		int y=query(1,1,n,1,a[x]-1);
		if(b[y]<=x)break;
		tarjan(y);
	}
	// printf("%d %d\n",x,now);
	ans[x]=++now;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)b[i]=n+1;
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		if(~a[i])b[a[i]]=i;
		else a[i]=n+1;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i)if(!vis[i])tarjan(i);
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}