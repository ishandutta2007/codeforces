#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
int T,n,q,l[210000],r[210000],sum[810000],tag[810000];
char s[210000],t[210000];
void pushup(int now){
	sum[now]=sum[ls]+sum[rs];
}
void pushdown(int now,int l,int r){
	if (tag[now]!=-1){
		int mid=(l+r)>>1;
		tag[ls]=tag[now]; sum[ls]=(mid-l+1)*tag[now];
		tag[rs]=tag[now]; sum[rs]=(r-mid)*tag[now];
		tag[now]=-1;
	}
}
void build(int now,int l,int r){
	tag[now]=-1;
	if (l==r){
		sum[now]=t[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
void change(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tag[now]=v;
		sum[now]=(r-l+1)*v;
		return;
	}
	int mid=(l+r)>>1; pushdown(now,l,r);
	if (x<=mid) change(ls,l,mid,x,y,v);
	if (y>mid) change(rs,mid+1,r,x,y,v);
	pushup(now);
}
int query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y) return sum[now];
	int mid=(l+r)>>1; pushdown(now,l,r);
	int res=0;
	if (x<=mid) res+=query(ls,l,mid,x,y);
	if (y>mid) res+=query(rs,mid+1,r,x,y);
	return res;
}
void work(){
	build(1,1,n);
	for (int i=1;i<=q;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=q;i>=1;i--){
		int b=query(1,1,n,l[i],r[i]),a=r[i]-l[i]+1-b;
		if (a==b){
			puts("NO");
			return;
		}
		change(1,1,n,l[i],r[i],(a<b));
	}
	for (int i=1;i<=n;i++)
		if (query(1,1,n,i,i)!=s[i]-'0'){
			puts("NO");
			return;
		}
	puts("YES");
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&q);
		scanf("%s%s",s+1,t+1);
		work();
	}
	return 0;
}