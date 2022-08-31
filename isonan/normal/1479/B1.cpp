#include <cstdio>
#include <algorithm>

int n,a[100001];
int se[2000001];
int lazy[2000001];
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
void set(int root,int l,int r,int e,int x){
	if(l==r){
		se[root]=std::min(se[root],x);
		return;
	}
	spread(root);
	if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e,x);
	else set(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	spread(root);
	if(el>r||er<l)return 0x7f7f7f7f;
	if(el<=l&&er>=r)return se[root];
	return std::min(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void build(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r)se[root]=x;
	if(l==r)return;
	build(root<<1,l,(l+r)>>1,el,er,x);
	build(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int main(){
	scanf("%d",&n);
	build(1,0,n,1,n,0x7f7f7f7f);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		int x=std::min(std::min(query(1,0,n,0,a[i]-1),query(1,0,n,a[i]+1,n)),query(1,0,n,a[i],a[i])+1);
		if(i>1&&a[i]==a[i-1])update(1,0,n,0,n,1);
		set(1,0,n,a[i-1],x);
	}
	printf("%d\n",n-query(1,0,n,0,n));
}