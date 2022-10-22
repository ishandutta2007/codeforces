#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
int n,q;
int a[Maxn+5],b[Maxn+5];
int d[Maxn+5];
struct Value{
	ll sum,min_val,max_val;
	ll l_neg,f_val,ans;
	friend Value operator +(Value a,Value b){
		Value ans;
		ans.sum=a.sum+b.sum;
		ans.min_val=std::min(a.min_val,a.sum+b.min_val);
		ans.max_val=std::max(b.max_val,b.sum+a.max_val);
		ll tmp=std::min(a.l_neg,b.f_val);
		ans.ans=a.ans+b.ans-tmp;
		ans.l_neg=a.l_neg-tmp+b.l_neg;
		ans.f_val=a.f_val+b.f_val-tmp;
		return ans;
	}
}seg[Maxn<<2|5];
void build(int root=1,int left=1,int right=n){
	if(left==right){
		seg[root].sum=d[left];
		seg[root].min_val=std::min(0,d[left]);
		seg[root].max_val=std::max(0,d[left]);
		seg[root].l_neg=(d[left]<0?-d[left]:0);
		seg[root].f_val=(d[left]>0?d[left]:0);
		seg[root].ans=seg[root].f_val;
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root]=seg[root<<1]+seg[root<<1|1];
}
Value query(int l,int r,int root=1,int left=1,int right=n){
	if(l<=left&&r>=right){
		return seg[root];
	}
	int mid=(left+right)>>1;
	if(r<=mid){
		return query(l,r,root<<1,left,mid);
	}
	if(l>mid){
		return query(l,r,root<<1|1,mid+1,right);
	}
	return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		d[i]=b[i]-a[i];
	}
	build();
	for(int t=1;t<=q;t++){
		int l,r;
		scanf("%d%d",&l,&r);
		Value ans=query(l,r);
		if(ans.min_val<0||ans.sum!=0||ans.max_val>0){
			puts("-1");
		}
		else{
			printf("%lld\n",ans.ans);
		}
	}
	return 0;
}