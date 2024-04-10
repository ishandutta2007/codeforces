#include <cstdio>
#include <algorithm>

int se[8000001],lazy[8000001],mn[8000001];
void pushdown(int x,int y){
	mn[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
void pushup(int root){
	mn[root]=std::min(mn[root<<1],mn[root<<1|1]);
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
	pushup(root);
}
int query(int root,int l,int r){
	spread(root);
	if(mn[root]>=0)return -1;
	if(l==r)return l;
	if(mn[root<<1|1]>=0)return query(root<<1,l,((l+r)>>1));
	else return query(root<<1|1,((l+r)>>1)+1,r);
}
int a[1000001],b[1000001],n,m,q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		update(1,1,1000000,1,a[i],-1);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		update(1,1,1000000,1,b[i],1);
	}
	scanf("%d",&q);
	for(int i=1,opt,t1,t2;i<=q;i++){
		scanf("%d%d%d",&opt,&t1,&t2);
		if(opt==1){
			update(1,1,1000000,1,a[t1],1);
			update(1,1,1000000,1,t2,-1);
			a[t1]=t2;
		}
		else{
			update(1,1,1000000,1,b[t1],-1);
			update(1,1,1000000,1,t2,1);
			b[t1]=t2;
		}
		printf("%d\n",query(1,1,1000000));
	}
}