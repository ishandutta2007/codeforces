#include <queue>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,k;
int a[Maxn+5];
struct Segment_Node{
	std::pair<int,int> mn_val;
	int lazy;
}seg[Maxn<<2|5];
void update_tag(int root,int a){
	seg[root].mn_val.first+=a,seg[root].lazy+=a;
}
void push_down(int root){
	if(seg[root].lazy){
		update_tag(root<<1,seg[root].lazy),update_tag(root<<1|1,seg[root].lazy);
		seg[root].lazy=0;
	}
}
void push_up(int root){
	seg[root].mn_val=std::min(seg[root<<1].mn_val,seg[root<<1|1].mn_val);
}
void build(int root=1,int left=1,int right=n){
	seg[root].mn_val=std::make_pair(Inf,0),seg[root].lazy=0;
	if(left==right){
		seg[root].mn_val=std::make_pair(Inf,left);
		return;
	}
	int mid=(left+right)/2;
	build(root<<1,left,mid),build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int l,int r,int a,int root=1,int left=1,int right=n){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		update_tag(root,a);
		return;
	}
	push_down(root);
	int mid=(left+right)/2;
	update(l,r,a,root<<1,left,mid),update(l,r,a,root<<1|1,mid+1,right);
	push_up(root);
}
void change(int x,int a,int root=1,int left=1,int right=n){
	if(left==right){
		seg[root].mn_val=std::make_pair(a,left);
		return;
	}
	push_down(root);
	int mid=(left+right)/2;
	if(x<=mid){
		change(x,a,root<<1,left,mid);
	}
	else{
		change(x,a,root<<1|1,mid+1,right);
	}
	push_up(root);
}
void solve(){
	scanf("%d%d",&n,&k);
	build();
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=n-k+1;i--){
		change(i,a[i]+k-(n-i));
	}
	for(int i=1;i<=n-k;i++){
		ans+=a[i];
	}
	for(int i=n-k;i>0;i--){
		std::pair<int,int> val=seg[1].mn_val;
		if(val.first<a[i]){
			ans=ans-a[i]+val.first;
			change(val.second,Inf);
			change(i,a[i]);
		}
		update(i,n,1);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}