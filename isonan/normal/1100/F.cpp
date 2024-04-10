#include <cstdio>
#include <cstring>
#include <vector>

struct basis{
	int Base[21];
	basis(){memset(Base,0,sizeof Base);}
	void add(int x){
		for(int i=20;~i;--i)
			if(x&(1<<i)){
				if(!Base[i]){
					Base[i]=x;
					return;
				}
				x^=Base[i];
			}
	}
	int getmx(){
		int ans=0;
		for(int i=20;~i;--i)
			if(ans<(ans^Base[i]))ans^=Base[i];
		return ans;
	}
	void print(){
		for(int i=20;~i;--i)printf("%d ",Base[i]);putchar('\n');
	}
}num[500001];
basis merge(basis a,basis b){for(int i=20;~i;--i)if(b.Base[i])a.add(b.Base[i]);return a;}
int a[500001],ans[500001],n,q;
struct query{int l,r,orig;}queries[500001],tem[500001];
void solve(int l,int r,int el,int er){
	if(el>er)return;
	if(l==r){
		for(int i=el;i<=er;i++)ans[queries[i].orig]=a[l];
		return;
	} 
	int mid=(l+r)>>1;
	num[mid]=basis();
	num[mid].add(a[mid]);
	for(int i=mid+1;i<=r;i++){
		num[i]=num[i-1];
		num[i].add(a[i]);
	}
	for(int i=mid-1;i>=l;i--){
		num[i]=num[i+1];
		num[i].add(a[i]);
	}
	int x=el,y=er;
	for(int i=el;i<=er;i++){
		if(queries[i].r<=mid)tem[x++]=queries[i];
		else if(queries[i].l>mid)tem[y--]=queries[i];
		else ans[queries[i].orig]=merge(num[queries[i].r],num[queries[i].l]).getmx();
	}
	for(int i=el;i<x;i++)queries[i]=tem[i];
	for(int i=er;i>y;i--)queries[i]=tem[i];
	solve(l,mid,el,x-1);
	solve(mid+1,r,y+1,er);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d",&queries[i].l,&queries[i].r),queries[i].orig=i;
	solve(1,n,1,q);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}