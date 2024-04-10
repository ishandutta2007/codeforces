#include<bits/stdc++.h>
using namespace std;
const int M=3e5+9;
int n,q,sz=0;
int rt[M<<5],ls[M<<5],rs[M<<5],sum[M<<5];
void update(int&now,int las,int l,int r,int v){
	now=++sz;
	sum[now]=sum[las]+1;
	ls[now]=ls[las];
	rs[now]=rs[las];
	if(l==r)return;
	int mid=(l+r)>>1;
	if(v<=mid)update(ls[now],ls[las],l,mid,v);
	else update(rs[now],rs[las],mid+1,r,v);
}
int query(int le,int ri,int l,int r,int k){
	if(l==r)return sum[ri]-sum[le]>=k?l:-1;
	int mid=(l+r)>>1;
	int suml=sum[ls[ri]]-sum[ls[le]];
	int sumr=sum[rs[ri]]-sum[rs[le]];
	int ans=-1;
	if(suml>=k)ans=query(ls[le],ls[ri],l,mid,k);
	if(sumr>=k&&ans==-1)ans=query(rs[le],rs[ri],mid+1,r,k);
	return ans; 
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,v;i<=n;++i){
		scanf("%d",&v);
		update(rt[i],rt[i-1],1,n,v);
	}
	for(int i=1,l,r,k;i<=q;++i){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(rt[l-1],rt[r],1,n,(r-l+1)/k+1));
	}
	return 0;
}