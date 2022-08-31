#include <cstdio>
#include <algorithm>
#define int long long

int n;
struct point{
	int x,y;
}num[200010];
int se[2000010];
int orig[200010];
void update(int root,int l,int r,int e){
	if(l==r){
		se[root]=1;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=se[root<<1]+se[root<<1|1];
}
int query(int root,int l,int r,int el,int er){
	if(el>er)return 0;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
bool cmp(point a,point b){
	return a.y>b.y||(a.y==b.y&&a.x<b.x);
}
long long Cn2(long long n){
	return (n*(n+1))>>1ll;
}
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&num[i].x,&num[i].y),orig[i]=num[i].x;
	std::sort(orig+1,orig+n+1);
	int lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)num[i].x=std::lower_bound(orig+1,orig+lim+1,num[i].x)-orig;
	std::sort(num+1,num+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;){
		int j=i+1;
		ans-=Cn2(query(1,1,lim,1,num[i].x-1));
		for(;num[j].y==num[i].y&&j<=n;j++){
			ans-=Cn2(query(1,1,lim,num[j-1].x+1,num[j].x-1));
		}
		for(int k=i;k<j;k++)update(1,1,lim,num[k].x);
		ans-=Cn2(query(1,1,lim,num[j-1].x+1,lim));
		i=j;
		ans+=Cn2(se[1]);
	}
	printf("%I64d\n",ans);
}