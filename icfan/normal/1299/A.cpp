#include <cstdio>
const int Maxn=100000;
struct Segment{
	int left,right;
	int sum;
}seg[Maxn<<2|5];
int a[Maxn+5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	if(left==right){
		seg[root].sum=(~a[left]);
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].sum=(seg[root<<1].sum&seg[root<<1|1].sum);
}
void update(int root,int x,int a){
	if(seg[root].left==seg[root].right){
		seg[root].sum=(~a);
		return;
	}
	int mid=(seg[root].left+seg[root].right)>>1;
	if(x<=mid){
		update(root<<1,x,a);
	}
	else{
		update(root<<1|1,x,a);
	}
	seg[root].sum=(seg[root<<1].sum&seg[root<<1|1].sum);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	int maxn=0,sum=-1;
	for(int i=1;i<=n;i++){
		update(1,i,0);
		if((seg[1].sum&a[i])>sum){
			sum=(seg[1].sum&a[i]);
			maxn=i;
		}
		update(1,i,a[i]);
	}
	printf("%d ",a[maxn]);
	for(int i=1;i<=n;i++){
		if(i!=maxn){
			printf("%d ",a[i]);
		}
	}
	puts("");
	return 0;
}