#include <cstdio>
#include <algorithm>

struct triplet{
	int l,r,sum;
	inline void set(int x,int y){l=r=x;sum=y;}
	inline void flip(){sum=-sum;}
};
struct point{
	triplet Lmn,Rmn,Wmn,Lmx,Rmx,Wmx,Tot;
	inline void flip(){
		std::swap(Lmx,Lmn);
		std::swap(Rmx,Rmn);
		std::swap(Wmx,Wmn);
		Lmn.flip(),Rmn.flip(),Wmn.flip(),Lmx.flip(),Rmx.flip(),Wmx.flip(),Tot.flip();
	}
	inline void set(int x,int y){Lmn.set(x,y),Rmn.set(x,y),Wmn.set(x,y),Lmx.set(x,y),Rmx.set(x,y),Wmx.set(x,y),Tot.set(x,y);}
}num[600001];
bool lazy[600001];
int n,m,chn[21][2];
triplet merge(triplet a,triplet b){return (triplet){a.l,b.r,a.sum+b.sum};}
triplet min(triplet a,triplet b){return a.sum>b.sum?b:a;}
triplet max(triplet a,triplet b){return a.sum<b.sum?b:a;}
point merge(point a,point b){
	return (point){
		min(a.Lmn,merge(a.Tot,b.Lmn)),
		min(b.Rmn,merge(a.Rmn,b.Tot)),
		min(min(a.Wmn,b.Wmn),merge(a.Rmn,b.Lmn)),
		max(a.Lmx,merge(a.Tot,b.Lmx)),
		max(b.Rmx,merge(a.Rmx,b.Tot)),
		max(max(a.Wmx,b.Wmx),merge(a.Rmx,b.Lmx)),
		merge(a.Tot,b.Tot)
	};
}
void pushdown(int x){if(!x)return;num[x].flip();lazy[x]^=1;}
void spread(int x){if(lazy[x])pushdown(x<<1),pushdown(x<<1|1),lazy[x]=0;}
void build(int root,int l,int r){
	if(l==r){
		int tem;
		scanf("%d",&tem);
		num[root].set(l,tem);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	num[root]=merge(num[root<<1],num[root<<1|1]);
}
void update(int root,int l,int r,int el,int er){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er);
	update(root<<1|1,((l+r)>>1)+1,r,el,er);
	num[root]=merge(num[root<<1],num[root<<1|1]);
}
point query(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return num[root];
	spread(root);
	if(((l+r)>>1)>=er)return query(root<<1,l,(l+r)>>1,el,er);
	if(((l+r)>>1)<el)return query(root<<1|1,((l+r)>>1)+1,r,el,er);
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void change(int root,int l,int r,int e,int x){
	if(l==r){
		num[root].set(l,x);
		return;
	}
	spread(root);
	if((l+r)>>1>=e)change(root<<1,l,(l+r)>>1,e,x);
	else change(root<<1|1,((l+r)>>1)+1,r,e,x);
	num[root]=merge(num[root<<1],num[root<<1|1]);
}
void dfs(int root,int l,int r){
	printf("%d (%d %d %d) (%d %d %d) (%d %d %d)\n",root,num[root].Lmx.l,num[root].Lmx.r,num[root].Lmx.sum,num[root].Rmx.l,num[root].Rmx.r,num[root].Rmx.sum,num[root].Wmx.l,num[root].Wmx.r,num[root].Wmx.sum);
	if(l==r)return;
	spread(root);
	dfs(root<<1,l,(l+r)>>1);
	dfs(root<<1|1,((l+r)>>1)+1,r);
}
int main(){
	scanf("%d",&n);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1,opt,l,r,k;i<=m;i++){
		scanf("%d",&opt);
		if(opt==0){
			scanf("%d%d",&l,&r);
			change(1,1,n,l,r);
		}
		else{
			scanf("%d%d%d",&l,&r,&k);
			int ans=0;
			for(int j=1;j<=k;j++)chn[j][0]=chn[j][1]=0;
			for(int j=1;j<=k;j++){
				point now=query(1,1,n,l,r);
				if(now.Wmx.sum<0)break;
//				printf("%d\n",now.Wmx.sum);
				ans+=now.Wmx.sum;
				chn[j][0]=now.Wmx.l;
				chn[j][1]=now.Wmx.r;
//				printf("%d %d\n",chn[j][0],chn[j][1]);
				update(1,1,n,chn[j][0],chn[j][1]);
//				dfs(1,1,n);
			}
			for(int j=1;j<=k;j++)if(chn[j][0])update(1,1,n,chn[j][0],chn[j][1]);
			printf("%d\n",ans);
		}
	}
}