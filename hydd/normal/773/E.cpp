/*********************************************************************
 * SourceCodeforces
 * ProblemCF773E
 * Authorhydd
 * Date2020/11/9 - 2020/11/10
*********************************************************************/
#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int INF=0x3f3f3f3f;
int n,a[510000],b[510000],p[510000];
inline bool cmp(int x,int y){ return a[x]<a[y];}
struct node{
	int num,tot,res;
	node operator+(const node &a) const{
		return (node){max(num,a.num),tot+a.tot,min(res+a.tot,a.res)};
	}
} tree[2100000];
void build(int now,int l,int r){
	tree[now].num=-INF;
	tree[now].tot=0; tree[now].res=INF;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	tree[now]=tree[ls]+tree[rs];
}
void change(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].num=v;
		tree[now].tot++; tree[now].res=v;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) change(ls,l,mid,x,v);
	else change(rs,mid+1,r,x,v);
	tree[now]=tree[ls]+tree[rs];
}
node query(int now,int l,int r,int x,int y){
	if (l==x&&r==y) return tree[now];
	int mid=(l+r)>>1;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return query(ls,l,mid,x,mid)+query(rs,mid+1,r,mid+1,y);
}
bool check(int x){
	node tmp=query(1,1,n,1,x);
	return tmp.num<=-tmp.tot;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++) b[p[i]]=i;
	build(1,1,n);
	for (int i=1;i<=n;i++){
		change(1,1,n,b[i],a[i]);
		int l=1,r=n,mid,res=0;
		while (l<=r){
			mid=(l+r)>>1;
			if (check(mid)) res=mid,l=mid+1;
			else r=mid-1;
		}
		if (res<n){
			node tmp=query(1,1,n,res+1,n);
			printf("%d\n",min(tmp.tot-i+tmp.tot,tmp.res));
		} else printf("%d\n",-i);
	}
	return 0;
}