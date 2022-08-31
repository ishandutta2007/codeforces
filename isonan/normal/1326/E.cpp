#include <cstdio>
#include <algorithm>

int n,p[4000001],q[4000001];
int mx;
int se[4000001],mn[4000001],lazy[4000001],pos[4000001];
void pushdown(int root,int x){
	se[root]+=x;
	mn[root]+=x;
	lazy[root]+=x;
}
void spread(int root){
	if(lazy[root]){
		pushdown(root<<1,lazy[root]);
		pushdown(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
}
void update(int root,int l,int r,int el,int er,int x){
	spread(root);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	mn[root]=std::max(mn[root<<1],mn[root<<1|1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i),pos[p[i]]=i;
	for(int i=1;i<=n;i++)scanf("%d",q+i);
	update(1,1,n,1,pos[n],1);
	for(int i=1,ans=n;i<=n;i++){
		printf("%d ",ans);
		if(i<n){
			update(1,1,n,1,q[i],-1);
			while(mn[1]<=0){
				--ans;
				update(1,1,n,1,pos[ans],1);
			}
		}
	}
}