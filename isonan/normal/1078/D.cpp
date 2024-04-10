#include <cstdio>
#include <algorithm> 

int n,r[100001],ans[100001];
struct point{
	int l,r;
	bool good(){
		return l==1&&r==n;
	}
}In[100001][17],se[1000001],now[100001];
point merge(point a,point b){
	if(a.good()||b.good())return (point){1,n};
	if(b.l<=b.r)std::swap(a,b);
	if(a.l>a.r){
		if((b.l<=a.r+1)||(a.l<=b.r+1))return (point){1,n};
		return (point){std::min(a.l,b.l),std::max(a.r,b.r)};
	}
	else if(b.l>b.r){
		if(a.l<=b.r+1&&a.r>=b.l-1)return (point){1,n};
		if(a.l<=b.r+1)return (point){b.l,std::max(a.r,b.r)};
		else return (point){std::min(a.l,b.l),b.r};
	}
	else{
		if(a.r<b.r)std::swap(a,b);
		if(b.l==1&&a.r==n&&b.r>=a.l-1)return (point){1,n};
		if(a.r==n&&b.l==1)return (point){a.l,b.r};
		return (point){std::min(a.l,b.l),std::max(a.r,b.r)};
	}
}
void build(int root,int l,int r,int i){
	if(l==r){
		se[root]=In[l][i];
		return;
	}
	build(root<<1,l,(l+r)>>1,i);
	build(root<<1|1,((l+r)>>1)+1,r,i);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
point query(int root,int l,int r,int el,int er){
	if(el<=l&&er>=r)return se[root];
	int mid=(l+r)>>1;
	if(el>mid)return query(root<<1|1,((l+r)>>1)+1,r,el,er);
	else if(er<=mid)return query(root<<1,l,(l+r)>>1,el,er);
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
point get(point a){
	if(a.l<=a.r)return query(1,1,n,a.l,a.r);
	else return merge(query(1,1,n,a.l,n),query(1,1,n,1,a.r));
}
point span(int x,int y){
	if((y<<1)+1>=n)return (point){1,n};
	int l=(x-y)>0?(x-y):(x-y+n),r=(x+y)<=n?x+y:(x+y-n);
	return (point){l,r};
}
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",r+i),In[i][0]=span(i,r[i]),now[i]=(point){i,i};
	for(int j=1;j<=16;j++){
		build(1,1,n,j-1);
		for(int i=1;i<=n;i++){
			if(In[i][j-1].good())In[i][j]=In[i][j-1];
			In[i][j]=get(In[i][j-1]);
		}
	}
	for(int j=16;~j;--j){
		build(1,1,n,j);
		for(int i=1;i<=n;i++){
			point tem=get(now[i]);
			if(!tem.good())ans[i]+=(1<<j),now[i]=tem;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]+1);
}