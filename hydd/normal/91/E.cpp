#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> node;
int n,q;
vector<int> tree[410000];
int A[210000],B[210000]; pii val[110000];
bool check(pii a,pii b,pii c){
	// return (a.second-b.second)/(b.first-a.first)>=(b.second-c.second)/(c.first-b.first);
	return 1ll*(a.second-b.second)*(c.first-b.first)>=1ll*(b.second-c.second)*(b.first-a.first);
}
bool cmp(int x,int y){ return val[x]<val[y];}
void pushup(int now){
	int len1=tree[ls].size(),len2=tree[rs].size();
	int i=0,j=0,k=0;
	while (i<len1||j<len2){
		if (i<len1&&j<len2&&val[tree[ls][i]].first==val[tree[rs][j]].first){
			if (cmp(tree[ls][i],tree[rs][j])) B[k++]=tree[rs][j];
			else B[k++]=tree[ls][i];
			i++; j++;
		} else
			if (j>=len2||(i<len1&&cmp(tree[ls][i],tree[rs][j]))) B[k++]=tree[ls][i++];
			else B[k++]=tree[rs][j++];
	}
	int m=0;
	for (int i=0;i<k;i++){
		while (m>1&&check(val[A[m-2]],val[A[m-1]],val[B[i]])) m--;
		A[m++]=B[i];
	}
	for (int i=0;i<m;i++) tree[now].push_back(A[i]);
}
ll query(pii a,int x){ return 1ll*a.first*x+a.second;}
int calc(int now,int x){
	int l=0,r=(int)tree[now].size()-1,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (query(val[tree[now][mid]],x)>query(val[tree[now][mid+1]],x)) r=mid;
		else l=mid+1;
	}
	return tree[now][r];
}
void build(int now,int l,int r){
	if (l==r){
		tree[now].push_back(l);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
int query(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y) return calc(now,v);
	int mid=(l+r)>>1; int res=0,tmp;
	if (x<=mid){
		tmp=query(ls,l,mid,x,y,v);
		if (query(val[res],v)<query(val[tmp],v)) res=tmp;
	}
	if (y>mid){
		tmp=query(rs,mid+1,r,x,y,v);
		if (query(val[res],v)<query(val[tmp],v)) res=tmp;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&q); int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		val[i]=pii(y,x);
	}
	build(1,1,n); int l,r,v;
	while (q--){
		scanf("%d%d%d",&l,&r,&v);
		printf("%d\n",query(1,1,n,l,r,v));
	}
	return 0;
}