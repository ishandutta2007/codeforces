#include <cstdio>
#include <algorithm> 

int n,q,a[4000001];
int se[8000001][2],lazy[8000001];
void pushdown(int x,int l){se[x][0]+=l,lazy[x]+=l;}
void spread(int root){
	pushdown(root<<1,lazy[root]);
	pushdown(root<<1|1,lazy[root]);
	lazy[root]=0;
}
void pushup(int root){
	se[root][0]=std::min(se[root<<1][0],se[root<<1|1][0]);
	se[root][1]=0;
	if(se[root][0]==se[root<<1][0])se[root][1]+=se[root<<1][1];
	if(se[root][0]==se[root<<1|1][0])se[root][1]+=se[root<<1|1][1];
}
void update(int root,int l,int r,int el,int er,int x){
	spread(root);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root); 
}
void updpoint(int root,int l,int r,int e,int x){
	spread(root);
	if(l==r){se[root][1]+=x;return;}
	if((l+r)>>1>=e)updpoint(root<<1,l,(l+r)>>1,e,x);
	else updpoint(root<<1|1,((l+r)>>1)+1,r,e,x);
	pushup(root);
}
const int N=1000000;
void alter(int i,int x){
	if(a[i]>a[i+1])update(1,0,N,a[i+1],a[i]-1,x);
	else update(1,0,N,a[i],a[i+1]-1,x);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),updpoint(1,0,N,a[i],1);
	a[0]=N+1,a[n+1]=0;
	for(int i=0;i<=n;i++)alter(i,1);
	for(int i=1,pos,x;i<=q;i++){
		scanf("%d%d",&pos,&x);
		updpoint(1,0,N,a[pos],-1);
		alter(pos-1,-1);
		alter(pos,-1);
		a[pos]=x;
		updpoint(1,0,N,a[pos],1);
		alter(pos-1,1);
		alter(pos,1);
		printf("%d\n",se[1][1]);
	}
}