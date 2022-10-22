#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=200000;
int n;
ll a[Maxn+5],b[Maxn+5];
struct Segment_Node{
	std::vector<ll> l_val,r_val;
}seg[Maxn<<2|5];
void build(int root=1,int left=1,int right=n){
	seg[root].l_val.clear(),seg[root].r_val.clear();
	seg[root].l_val.push_back(0),seg[root].r_val.push_back(0);
	if(left==right){
		seg[root].l_val.push_back(b[left]);
		return;
	}
	int mid=(left+right)>>1;
	seg[root].l_val.push_back(b[mid]);
	for(int i=mid-1;i>=left;i--){
		seg[root].l_val.push_back(gcd(seg[root].l_val.back(),b[i]));
	}
	seg[root].r_val.push_back(b[mid+1]);
	for(int i=mid+2;i<=right;i++){
		seg[root].r_val.push_back(gcd(seg[root].r_val.back(),b[i]));
	}
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
ll query(int l,int r,int root=1,int left=1,int right=n){
	int mid=(left+right)>>1;
	if(l<=mid+1&&r>=mid){
		return gcd(seg[root].l_val[mid-l+1],seg[root].r_val[r-mid]);
	}
	if(r<=mid){
		return query(l,r,root<<1,left,mid);
	}
	else{
		return query(l,r,root<<1|1,mid+1,right);
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i]-a[i-1];
		b[i]=std::abs(b[i]);
	}
	build();
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&query(j+1,i)==1){
			j++;
		}
		ans=std::max(ans,i-j+1);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}