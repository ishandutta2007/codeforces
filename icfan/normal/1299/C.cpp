#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=1000000;
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
int fa[Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
int n;
int a[Maxn+5];
struct Segment_Node{
	int left,right;
	double sum,maxn;
	bool lazy;
}seg[Maxn<<2|5];
void build(int root,int left,int right){
	seg[root].left=left;
	seg[root].right=right;
	seg[root].lazy=0;
	if(left==right){
		seg[root].sum=a[left];
		seg[root].maxn=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
}
void push_down(int root){
	if(seg[root].lazy){
		seg[root<<1].lazy=1;
		seg[root<<1|1].lazy=1;
		seg[root<<1].sum=(seg[root<<1].right-seg[root<<1].left+1)*seg[root].maxn;
		seg[root<<1|1].sum=(seg[root<<1|1].right-seg[root<<1|1].left+1)*seg[root].maxn;
		seg[root<<1].maxn=seg[root].maxn;
		seg[root<<1|1].maxn=seg[root].maxn;
		seg[root].lazy=0;
	}
}
void update(int root,int left,int right,double val){
	if(seg[root].left==left&&seg[root].right==right){
		seg[root].maxn=val;
		seg[root].sum=(seg[root].right-seg[root].left+1)*val;
		seg[root].lazy=1;
		return;
	}
	push_down(root);
	int mid=(seg[root].left+seg[root].right)>>1;
	if(left<=mid){
		if(right<=mid){
			update(root<<1,left,right,val);
		}
		else{
			update(root<<1,left,mid,val);
		}
	}
	if(right>mid){
		if(left>mid){
			update(root<<1|1,left,right,val);
		}
		else{
			update(root<<1|1,mid+1,right,val);
		}
	}
	seg[root].maxn=max(seg[root<<1].maxn,seg[root<<1|1].maxn);
	seg[root].sum=seg[root<<1].sum+seg[root<<1|1].sum;
}
double query_s(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].sum;
	}
	push_down(root);
	int mid=(seg[root].left+seg[root].right)>>1;
	if(right<=mid){
		return query_s(root<<1,left,right);
	}
	if(left>mid){
		return query_s(root<<1|1,left,right);
	}
	return query_s(root<<1,left,mid)+query_s(root<<1|1,mid+1,right);
}
double query_mx(int root,int left,int right){
	if(seg[root].left==left&&seg[root].right==right){
		return seg[root].maxn;
	}
	push_down(root);
	int mid=(seg[root].left+seg[root].right)>>1;
	if(right<=mid){
		return query_mx(root<<1,left,right);
	}
	if(left>mid){
		return query_mx(root<<1|1,left,right);
	}
	return max(query_mx(root<<1,left,mid),query_mx(root<<1|1,mid+1,right));
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		fa[i]=i;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int j=i-1;
		while(j>0&&query_s(1,j,j)>query_s(1,i,i)){
			j=find(j);
			update(1,j,i,query_s(1,j,i)/(i-j+1));
			merge(j,i);
			j--;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%.10lf\n",query_s(1,i,i));
	}
	return 0;
}