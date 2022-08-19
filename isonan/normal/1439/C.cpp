#include <cstdio>
#include <algorithm>

int n,q,a[200001];
int se[2000001],siz[2000001];
long long sum[2000001];
int lazy[2000001];
void build(int root,int l,int r){
	if(r==l){
		se[root]=a[l];
		sum[root]=a[l];
		siz[root]=1;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	siz[root]=r-l+1;
	se[root]=std::min(se[root<<1],se[root<<1|1]);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}
void pushdown(int x,int y){
	se[x]=y;
	sum[x]=1ll*y*siz[x];
	lazy[x]=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
int findfirst(int root,int l,int r,int x){
	if(se[root]>x)return n+1;
	if(l==r)return l;
	spread(root);
	if(se[root<<1]<=x)return findfirst(root<<1,l,(l+r)>>1,x);
	else return findfirst(root<<1|1,((l+r)>>1)+1,r,x);
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
	sum[root]=sum[root<<1]+sum[root<<1|1];
}
int R;
bool full;
int getsum(int root,int l,int r,int e,int y){
//	printf("getsum %d %d %d %d\n",l,r,e,y);
	spread(root);
	if(r<e)return 0;
	if(l>=e){
		if(sum[root]<=y){
			R=r;
			return sum[root];
		}
		else{
			full=0;
			if(l==r)return 0;
			else if(sum[root<<1]<=y){
				R=(l+r)>>1;
				return getsum(root<<1|1,((l+r)>>1)+1,r,e,y-sum[root<<1])+sum[root<<1];
			}
			else{
				return getsum(root<<1,l,(l+r)>>1,e,y);
			}
		}
	}
	int tem=getsum(root<<1,l,(l+r)>>1,e,y);
	if(full)return tem+getsum(root<<1|1,((l+r)>>1)+1,r,e,y-tem);
	else return tem;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	build(1,1,n);
	for(int i=1,t,x,y;i<=q;i++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			int r=findfirst(1,1,n,y);
			update(1,1,n,r,x,y);
		}
		else{
			int ans=0;
			for(;;){
				full=1;
				R=1;
				int r=std::max(findfirst(1,1,n,y),x);
				if(r==n+1)break;
				y-=getsum(1,1,n,r,y);
				ans+=R-r+1;
//				printf("%d %d %d\n",r,R,y);
				x=R+1;
			}
			printf("%d\n",ans);
		}
	}
}