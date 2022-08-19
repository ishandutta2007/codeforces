#include <cstdio>
#include <vector>
#include <algorithm>

int t,n,m,a[100010];
long long se[1000010],mn[1000010];
std::vector<int>b[100010];
int k[100010];
long long sum[100010];
void build(int root,int l,int r){
	if(l==r){
		se[root]=mn[root]=(l<n);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=se[root<<1]+se[root<<1|1];
	mn[root]=std::min(mn[root<<1]+se[root<<1|1],mn[root<<1|1]);
}
void set(int root,int l,int r,int e,int x){
	if(l==r){
		se[root]+=x,mn[root]+=x;
		return;
	}
	if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e,x);
	else set(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=se[root<<1]+se[root<<1|1];
	mn[root]=std::min(mn[root<<1]+se[root<<1|1],mn[root<<1|1]);
}
void check(int x,int v){
	int l=1,r=n,mid,ans=n+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(1ll*a[mid]*k[x]>=sum[x])ans=mid,r=mid-1;
		else l=mid+1;
		// printf("%d %d %d\n",l,r,mid);
	}
	// printf("check %d %d %d\n",x,v,ans);
	if(ans<=n)set(1,1,n,ans,v);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		std::sort(a+1,a+n+1);
		++n;
		a[n]=0x7f7f7f7f;
		build(1,1,n);
		for(int i=1,k;i<=m;++i){
			scanf("%d",&k);
			b[i].resize(k);
			sum[i]=0;
			::k[i]=k;
			for(int j=0;j<k;++j)scanf("%d",&b[i][j]),sum[i]+=b[i][j];
			check(i,-1);
		}
		for(int i=1;i<=m;++i){
			check(i,1);
			for(int j=0;j<k[i];++j){
				--k[i];
				sum[i]-=b[i][j];
				check(i,-1);
				// printf("%d %d\n",k[i],sum[i]);
				if(mn[1]<0)putchar('0');
				else putchar('1');
				check(i,1);
				++k[i];
				sum[i]+=b[i][j];
			}
			check(i,-1);
		}
		putchar('\n');
	}
}