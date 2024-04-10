#include<cstdio>
#define ls ((now)<<1)
#define rs ((now)<<1|1)
using namespace std;
int tree[1100000],ans[31][110000];
int a[110000],b[110000];
char s[110000];
int n,m,q;
struct questions{
	int op,l,r;
} ques[110000];
void pushdown(int now,int l,int r){
	int mid=(l+r)>>1;
	if (tree[now]==r-l+1){
		tree[ls]=mid-l+1;
		tree[rs]=r-mid;
	}
	if (!tree[now]){
		tree[ls]=0;
		tree[rs]=0;
	}
}
void update(int now){
	tree[now]=tree[ls]+tree[rs];
}
void buildtree(int now,int l,int r){
	if (l>r) return;
	if (l==r){
		tree[now]=b[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(ls,l,mid); buildtree(rs,mid+1,r);
	update(now);
}
void change(int now,int l,int r,int x,int y,int v){
	if (l>r||x>y) return;
	if (x==l&&r==y){
		tree[now]=v*(r-l+1);
		return;
	}
	int mid=(l+r)>>1; pushdown(now,l,r);
	if (y<=mid) change(ls,l,mid,x,y,v);
	else if (x>mid) change(rs,mid+1,r,x,y,v);
	else {
		change(ls,l,mid,x,mid,v);
		change(rs,mid+1,r,mid+1,y,v);
	}
	update(now); pushdown(now,l,r);
}
int query(int now,int l,int r,int x,int y){
	if (l>r||x>y) return 0;
	if (x==l&&r==y) return tree[now];
	int mid=(l+r)>>1; pushdown(now,l,r);
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return query(ls,l,mid,x,mid)+query(rs,mid+1,r,mid+1,y);
}

void work(){
	for (int now=1;now<=26;now++){
		for (int i=1;i<=n;i++) b[i]=(a[i]>=now);
		buildtree(1,1,n);
		for (int i=1;i<=m;i++){
			int k=query(1,1,n,ques[i].l,ques[i].r);
			if (!ques[i].op){
				change(1,1,n,ques[i].l,ques[i].l+k-1,1);
				change(1,1,n,ques[i].l+k,ques[i].r,0);
			} else {
				k=ques[i].r-ques[i].l+1-k;
				change(1,1,n,ques[i].l,ques[i].l+k-1,0);
				change(1,1,n,ques[i].l+k,ques[i].r,1);
			}
		}
		for (int i=1;i<=n;i++) ans[now][i]=query(1,1,n,i,i);
	}
	
}
int main(){
	//freopen("sort.in","r",stdin);
	//freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&ques[i].l,&ques[i].r,&ques[i].op);
	work();
	for (int i=1;i<=n;i++)
		for (int now=26;now>=1;now--)
			if (ans[now][i]){
				putchar(now+'a'-1);
				break;
			}
	return 0;
}
/*
6 4
1 4 2 6 5 3
0 1 4
1 2 5
1 3 6
0 6 6
3

*/