#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
const int Maxm=1000001;
const int Inf=0x7f7f7f7f;
int n,m,p;
struct Seller{
	int val,cos;
	friend bool operator <(Seller p,Seller q){
		return p.val<q.val;
	}
}a[Maxn+5],b[Maxn+5];
struct Monster{
	int a,b;
	int val;
	friend bool operator <(Monster p,Monster q){
		return p.a<q.a;
	}
}c[Maxn+5];
struct Segment_Node{
	int lazy;
	int maxn;
}seg[Maxm<<2|5];
void build(int root=1,int left=1,int right=Maxm){
	seg[root].lazy=0;
	seg[root].maxn=-Inf;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
}
void push_down(int root){
	if(seg[root].lazy){
		seg[root<<1].maxn+=seg[root].lazy;
		seg[root<<1].lazy+=seg[root].lazy;
		seg[root<<1|1].maxn+=seg[root].lazy;
		seg[root<<1|1].lazy+=seg[root].lazy;
		seg[root].lazy=0;
	}
}
void update_node(int x,int a,int root=1,int left=1,int right=Maxm){
	if(left==right){
		seg[root].maxn=a;
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	if(x<=mid){
		update_node(x,a,root<<1,left,mid);
	}
	else{
		update_node(x,a,root<<1|1,mid+1,right);
	}
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
void update_seg(int l,int r,int k,int root=1,int left=1,int right=Maxm){
	if(l>right||r<left){
		return;
	}
	if(l<=left&&r>=right){
		seg[root].lazy+=k;
		seg[root].maxn+=k;
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	update_seg(l,r,k,root<<1,left,mid);
	update_seg(l,r,k,root<<1|1,mid+1,right);
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
int main(){
	build();
	read(n),read(m),read(p);
	for(int i=1;i<=n;i++){
		read(a[i].val);
		read(a[i].cos);
	}
	for(int i=1;i<=m;i++){
		read(b[i].val);
		read(b[i].cos);
		update_node(b[i].val,-b[i].cos);
	}
	for(int i=1;i<=p;i++){
		read(c[i].a);
		read(c[i].b);
		read(c[i].val);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sort(c+1,c+1+p);
	int ans=-Inf;
	for(int i=1,j=1;i<=n;i++){
		while(j<=p&&c[j].a<a[i].val){
			update_seg(c[j].b+1,Maxm,c[j].val);
			j++;
		}
		ans=max(ans,seg[1].maxn-a[i].cos);
	}
	printf("%d\n",ans);
	return 0;
}