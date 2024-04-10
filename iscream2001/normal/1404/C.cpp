#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int inf=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,Q;
int a[N];
int las[N];
struct node{
	int l,r;
	int mn;
	int tag;
}d[N<<2];
void update(int id){
	d[id].mn=min(d[id<<1].mn,d[id<<1|1].mn);
}
void pushdown(int id){
	if(d[id].l==d[id].r) return;
	d[id<<1].tag+=d[id].tag;
	d[id<<1|1].tag+=d[id].tag;
	d[id<<1].mn+=d[id].tag;
	d[id<<1|1].mn+=d[id].tag;
	d[id].tag=0;
}
void build(int l,int r,int id){
	d[id].l=l;d[id].r=r;d[id].tag=0;
	if(l==r){
		d[id].mn=inf;
		d[id].tag=0;
		return ;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	update(id);
}
void C(int id,int x,int y){
	pushdown(id);
	if(d[id].l==d[id].r){
		d[id].mn=y;
		return;
	}
	int mid=d[id].l+d[id].r>>1;
	if(x<=mid) C(id<<1,x,y);
	else C(id<<1|1,x,y);
	update(id);
}
void J(int id,int l,int r){
	pushdown(id);
	if(d[id].l==l&&d[id].r==r) {
		d[id].tag--;
		d[id].mn--;
		return;
	}
	int mid=d[id].l+d[id].r>>1;
	if(r<=mid) J(id<<1,l,r);
	else if(l>mid) J(id<<1|1,l,r);
	else {
	    J(id<<1,l,mid);
		J(id<<1|1,mid+1,r);
	}
	update(id);
}
int find(int id){
	pushdown(id);
	if(d[id].l==d[id].r) return d[id].l;
	if(d[id<<1].mn<=0) return find(id<<1);
	else return find(id<<1|1);
}
int cnt=0;
int rt[N];
int ls[N*21],rs[N*21],val[N*21];
void insert(int l,int r,int x,int y,int v){
	ls[y]=ls[x];rs[y]=rs[x];val[y]=val[x]+1;
	//cout<<"y "<<y<<" "<<val[y]<<endl;
	if(l==r) return;
	int mid=l+r>>1;
	if(v<=mid){
		ls[y]=++cnt;
		insert(l,mid,ls[x],ls[y],v);
	}
	else{
		rs[y]=++cnt;
		insert(mid+1,r,rs[x],rs[y],v);
	}
}
int check(int l,int r,int x,int y,int v){
	if(r<v) return 0;
	if(l>=v) return val[y]-val[x];
	int mid=l+r>>1;
	return check(l,mid,ls[x],ls[y],v)+check(mid+1,r,rs[x],rs[y],v);
}
int main(){
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	int x,y;
	for(int i=n;i>=1;--i){
		if(a[i]>i) continue;
		x=i-a[i];
		C(1,i,x);
		while(d[1].mn<=0){
			x=find(1);
			las[x]=i;
			C(1,x,inf);
			if(x+1<=n) J(1,x+1,n);
		}
	}
	//for(int i=1;i<=n;++i) cout<<las[i]<<" ";puts("");
	for(int i=1;i<=n;++i){
		rt[i]=++cnt;
		insert(0,n,rt[i-1],rt[i],las[i]);
	}
	while(Q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",check(0,n,rt[x],rt[n-y],x+1));
	}
	return 0;
}