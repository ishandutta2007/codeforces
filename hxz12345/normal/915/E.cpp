#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
struct SegmentTree{
	int lft,rit,sum,tag;
} tree[15001010];
int opt,n,Testing,id,rt,l,r;
void pushup(int x){
	tree[x].sum=tree[tree[x].lft].sum+tree[tree[x].rit].sum;
}
void pushdown(int x,int l,int r){
	int mid=(l+r)>>1;
	if (tree[x].tag!=0){
		if (tree[x].lft==0) tree[x].lft=++id;
		if (tree[x].rit==0) tree[x].rit=++id;
		if (tree[x].tag==2){
			tree[tree[x].lft].sum=0;tree[tree[x].lft].tag=2;
			tree[tree[x].rit].sum=0;tree[tree[x].rit].tag=2;
		}
		else {
			tree[tree[x].lft].sum=mid-l+1;tree[tree[x].lft].tag=1;
			tree[tree[x].rit].sum=r-mid;tree[tree[x].rit].tag=1;
		}
		tree[x].tag=0;
	}
	return ;
}
void modify(int &x,int l,int r,int tl,int tr,int val){
	if (x==0) x=++id;
	if ((l>=tl)&&(r<=tr)) {
		tree[x].sum=(r-l+1)*val;tree[x].tag=2-val;
		return ;
	}
	pushdown(x,l,r);
	int mid=(l+r)>>1;
	if (tl<=mid) modify(tree[x].lft,l,mid,tl,tr,val);
	if (tr>mid) modify(tree[x].rit,mid+1,r,tl,tr,val);
	pushup(x);
}
int main(){
	n=read();Testing=read();
	modify(rt,1,n,1,n,1);
	for (;Testing;Testing--){
		l=read();r=read();opt=read();
		if (opt==1) modify(rt,1,n,l,r,0);
		if (opt==2) modify(rt,1,n,l,r,1);
		printf("%d\n",tree[rt].sum);
	}
	return 0;
}