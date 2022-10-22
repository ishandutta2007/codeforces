#include <cstdio>
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
void write(int a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>=10){
		write(a/10);
	}
	putchar(a%10+'0');
}
const int Maxn=300000;
int n,q;
int a[Maxn+5];
struct Segment_Node{
	int lson,rson;
	int sum;
}seg[Maxn*30+5];
int id_tot;
int Root[Maxn+5];
void insert(int last,int &root,int x,int a,int left=1,int right=n){
	root=++id_tot;
	seg[root]=seg[last];
	seg[root].sum+=a;
	if(left==right){
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		insert(seg[last].lson,seg[root].lson,x,a,left,mid);
	}
	else{
		insert(seg[last].rson,seg[root].rson,x,a,mid+1,right);
	}
}
int query(int root_1,int root_2,int k,int left=1,int right=n){
	if(k>seg[root_2].sum-seg[root_1].sum){
		return -1;
	}
	if(left==right){
		return left;
	}
	int l_sum=seg[seg[root_2].lson].sum-seg[seg[root_1].lson].sum;
	int r_sum=seg[seg[root_2].rson].sum-seg[seg[root_1].rson].sum;
	int mid=(left+right)>>1;
	int ans=-1;
	if(l_sum>=k){
		ans=query(seg[root_1].lson,seg[root_2].lson,k,left,mid);
	}
	if(ans==-1&&r_sum>=k){
		ans=query(seg[root_1].rson,seg[root_2].rson,k,mid+1,right);
	}
	return ans;
}
int main(){
	read(n),read(q);
	for(int i=1;i<=n;i++){
		read(a[i]);
		insert(Root[i-1],Root[i],a[i],1);
	}
	int l,r,k;
	for(int i=1;i<=q;i++){
		read(l),read(r),read(k);
		printf("%d\n",query(Root[l-1],Root[r],(r-l+1)/k+1));
	}
	return 0;
}