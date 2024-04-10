#include <bits/stdc++.h>
using namespace std;
#define int long long

int i,j,k,n,m,t,it;
int a[200005],res[200005];
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[2000005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline void pushdown(int k){
		s[k<<1].val+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
	inline void modify(int k,int l,int r,int x){
		if(l>r)	return;
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val+=x;
			s[k].lz+=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
	inline int last_zero(){
		int l=1,r=n,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(1,mid,n)==0)	ans=mid,l=mid+1;
			else					r=mid-1;
		}
		return ans;
	}
} s;

int get(){
	int l=1,r=n,md,res=0;
	while(l<=r){
		md=(l+r)/2;
		if(s.query(1,md,n)==0){res=max(res,md);l=md+1;}
		else{r=md-1;}
	}
	return res;
}

signed main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	s.build(1,1,n);
	for(i=1;i<=n;i++){
		int sb=get();
		res[sb]=i;
		s.modify(1,sb,sb,1e12);
		s.modify(1,sb+1,n,-i);
	}
	for(i=1;i<=n;i++){
		printf("%lld ",res[i]);
	}
}