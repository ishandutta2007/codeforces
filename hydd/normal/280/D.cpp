#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
int n,q,v[110000],L[110000],R[110000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
struct Node{
	Node(){}
	Node(int _x,int _v):x(_x),v(_v){}
	int x,v;
};
struct node{
	node(){}
	node(int _l,int _r,int _v):l(_l),r(_r),v(_v){}
	int l,r,v;
};
struct treenode{
	int sum;
	node mx,mn;
	Node mxsuf,mnsuf,mxpre,mnpre;
} tree[410000];
int tag[410000];
bool operator<(const node &a,const node &b){ return a.v<b.v;}
bool operator<(const Node &a,const Node &b){ return a.v<b.v;}
node operator+(const Node &a,const Node &b){ return node(a.x,b.x,a.v+b.v);}
Node operator+(const Node &a,int b){ return Node(a.x,a.v+b);}
treenode merge(const treenode &lsv,const treenode &rsv){
	treenode nowv;
	nowv.sum=lsv.sum+rsv.sum;
	nowv.mx=max(max(lsv.mx,rsv.mx),lsv.mxsuf+rsv.mxpre);
	nowv.mn=min(min(lsv.mn,rsv.mn),lsv.mnsuf+rsv.mnpre);
	nowv.mxsuf=max(rsv.mxsuf,lsv.mxsuf+rsv.sum);
	nowv.mnsuf=min(rsv.mnsuf,lsv.mnsuf+rsv.sum);
	nowv.mxpre=max(lsv.mxpre,rsv.mxpre+lsv.sum);
	nowv.mnpre=min(lsv.mnpre,rsv.mnpre+lsv.sum);
	return nowv;
}
void rev(int now){
	tree[now].sum=-tree[now].sum;
	swap(tree[now].mx,tree[now].mn);
	tree[now].mx.v=-tree[now].mx.v;
	tree[now].mn.v=-tree[now].mn.v;
	swap(tree[now].mxsuf,tree[now].mnsuf);
	tree[now].mxsuf.v=-tree[now].mxsuf.v;
	tree[now].mnsuf.v=-tree[now].mnsuf.v;
	swap(tree[now].mxpre,tree[now].mnpre);
	tree[now].mxpre.v=-tree[now].mxpre.v;
	tree[now].mnpre.v=-tree[now].mnpre.v;
	tag[now]^=1;
}
void pushup(int now){ tree[now]=merge(tree[ls],tree[rs]);}
void pushdown(int now){
	if (tag[now]){
		rev(ls); rev(rs);
		tag[now]=0;
	}
}
void init(treenode &res,int x){
	res.sum=v[x];//
	res.mx=node(x,x,v[x]);//
	res.mn=node(x,x,v[x]);//
	res.mxsuf=Node(x,v[x]);//
	res.mnsuf=Node(x,v[x]);//
	res.mxpre=Node(x,v[x]);//
	res.mnpre=Node(x,v[x]);//
}
void build(int now,int l,int r){
	if (l==r) return tag[now]=0,init(tree[now],l);
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
void change(int now,int l,int r,int x){
	if (l==r) return tag[now]=0,init(tree[now],x);
	int mid=(l+r)>>1; pushdown(now);
	if (x<=mid) change(ls,l,mid,x);
	else change(rs,mid+1,r,x);
	pushup(now);
}
void change(int now,int l,int r,int x,int y){
	if (l==x&&r==y) return rev(now);
	int mid=(l+r)>>1; pushdown(now);
	if (y<=mid) change(ls,l,mid,x,y);
	else if (x>mid) change(rs,mid+1,r,x,y);
	else{ change(ls,l,mid,x,mid); change(rs,mid+1,r,mid+1,y);}
	pushup(now);
}
treenode query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y) return tree[now];
	int mid=(l+r)>>1; pushdown(now);
	if (y<=mid) return query(ls,l,mid,x,y);
	else if (x>mid) return query(rs,mid+1,r,x,y);
	else return merge(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) v[i]=read();
	build(1,1,n);
	q=read(); int op,x,l,r,k;
	while (q--){
		op=read();
		if (op==0){
			x=read(); v[x]=read();
			change(1,1,n,x);
		} else{
			l=read(); r=read(); k=read(); int res=0,cnt=0;
			for (int i=1;i<=k;i++){
				node tmp=query(1,1,n,l,r).mx;
				L[i]=tmp.l; R[i]=tmp.r;
				if (tmp.v<0) break;
				res+=tmp.v; cnt=i;
				change(1,1,n,L[i],R[i]);
			}
			for (int i=cnt;i>=1;i--) change(1,1,n,L[i],R[i]);
			printf("%d\n",res);
		}
	}
	return 0;
}