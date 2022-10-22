#include<cstdio>
#include<algorithm>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
int n,m,op,l,r,k,x,a[310000];
int mx[1210000];
ll sum[1210000];
void pushup(int now){
	mx[now]=max(mx[ls],mx[rs]);
	sum[now]=sum[ls]+sum[rs];
}
void build(int now,int l,int r){
	if (l==r){
		mx[now]=a[l]; sum[now]=a[l]; 
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
void change1(int now,int l,int r,int x,int y,int k){
	if (mx[now]<k) return;
	if (l==r){
		mx[now]%=k;
		sum[now]=(ll)(r-l+1)*mx[now];
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) change1(ls,l,mid,x,y,k);
	if (y>mid) change1(rs,mid+1,r,x,y,k);
	pushup(now);
}
void change2(int now,int l,int r,int x,int k){
	if (l==r){
		mx[now]=k; sum[now]=k;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) change2(ls,l,mid,x,k);
	else change2(rs,mid+1,r,x,k);
	pushup(now);
}
ll query(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y) return sum[now];
    int mid=(l+r)>>1;
    ll ret=0;
    if (x<=mid) ret+=query(ls,l,mid,x,y);
    if (y>mid) ret+=query(rs,mid+1,r,x,y);
    return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for (int i=1;i<=m;i++){
		scanf("%d",&op);
		if (op==3){
			scanf("%d%d",&k,&x);
			change2(1,1,n,k,x);
		}
		else{
			scanf("%d%d",&l,&r);
			if (op==1) printf("%lld\n",query(1,1,n,l,r));
			else { scanf("%d",&x); change1(1,1,n,l,r,x);}
		}
	}
	return 0;
}