#include<cstdio>
#include<utility>
#include<algorithm>
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,cnt1,cnt2,c[210000],d[210000];
pii a[110000],b[110000];
pii tree[1610000],tag[1610000];
void pushdown(int now){
	tree[ls].first=max(tag[now].first,tree[ls].first);
	tree[ls].second=min(tag[now].second,tree[ls].second);
	tree[rs].first=max(tag[now].first,tree[rs].first);
	tree[rs].second=min(tag[now].second,tree[rs].second);
	tag[ls].first=max(tag[now].first,tag[ls].first);
	tag[ls].second=min(tag[now].second,tag[ls].second);
	tag[rs].first=max(tag[now].first,tag[rs].first);
	tag[rs].second=min(tag[now].second,tag[rs].second);
	tree[now].first=0; tree[now].second=INF;
}
void pushup(int now){
	tree[now].first=max(tree[ls].first,tree[rs].first);
	tree[now].second=min(tree[ls].second,tree[rs].second);
}
void change(int now,int l,int r,int x,int y,int a,int b){
	if (l==x&&r==y){
		tree[now].first=max(tree[now].first,a);
		tree[now].second=min(tree[now].second,b);
		tag[now].first=max(tag[now].first,a);
		tag[now].second=min(tag[now].second,b);
		return;
	}
	pushdown(now);
	int mid=(l+r)>>1;
	if (y<=mid) change(ls,l,mid,x,y,a,b);
	else if (x>mid) change(rs,mid+1,r,x,y,a,b);
	else { change(ls,l,mid,x,mid,a,b); change(rs,mid+1,r,mid+1,y,a,b);}
	pushup(now);
}
pii query(int now,int l,int r,int x,int y){
	if (l==x&&r==y) return tree[now];
	pushdown(now);
	int mid=(l+r)>>1;
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else {
		pii tmp1=query(ls,l,mid,x,mid),
			tmp2=query(rs,mid+1,r,mid+1,y);
		return pii(max(tmp1.first,tmp2.first),min(tmp1.second,tmp2.second));
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		scanf("%d%d",&b[i].first,&b[i].second);
	}
	cnt1=0;
	for (int i=1;i<=n;i++){
		c[++cnt1]=a[i].first;
		c[++cnt1]=a[i].second;
	}
	sort(c+1,c+cnt1+1);
	for (int i=1;i<=n;i++){
		a[i].first=lower_bound(c+1,c+cnt1+1,a[i].first)-c;
		a[i].second=lower_bound(c+1,c+cnt1+1,a[i].second)-c;
	}
	cnt2=0;
	for (int i=1;i<=n;i++){
		d[++cnt2]=b[i].first;
		d[++cnt2]=b[i].second;
	}
	sort(d+1,d+cnt2+1);
	for (int i=1;i<=n;i++){
		b[i].first=lower_bound(d+1,d+cnt2+1,b[i].first)-d;
		b[i].second=lower_bound(d+1,d+cnt2+1,b[i].second)-d;
	}
	pii tmp; bool flag=false;
	for (int i=1;i<=4*cnt1;i++){
		tree[i].first=0; tree[i].second=INF;
		tag[i].first=0; tag[i].second=INF;
	}
	for (int i=1;i<=n;i++){
		tmp=query(1,1,cnt1,a[i].first,a[i].second);
		//first:l'_max,second:r'_min
		if (tmp.first>b[i].second||tmp.second<b[i].first){
			flag=true;
			break;
		}
		change(1,1,cnt1,a[i].first,a[i].second,b[i].first,b[i].second);
	}
	if (flag){ puts("NO"); return 0;}
	for (int i=1;i<=4*cnt2;i++){
		tree[i].first=0; tree[i].second=INF;
		tag[i].first=0; tag[i].second=INF;
	}
	for (int i=1;i<=n;i++){
		tmp=query(1,1,cnt2,b[i].first,b[i].second);
		//first:l_max,second:r_min
		if (tmp.first>a[i].second||tmp.second<a[i].first){
			flag=true;
			break;
		}
		change(1,1,cnt2,b[i].first,b[i].second,a[i].first,a[i].second);
	}
	if (flag){ puts("NO"); return 0;}
	puts("YES");
	return 0;
}