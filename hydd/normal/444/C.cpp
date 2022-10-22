#include<cstdio>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
int n,m,col[410000],tagc[410000];
ll sum[410000],taga[410000];
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
	while (ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=Getchar();
	return x*f;
}
inline int myabs(int x){ return x>0?x:-x;}
void pushup(int now){
	col[now]=(col[ls]==col[rs]?col[ls]:-1);
	sum[now]=sum[ls]+sum[rs];
}
void puttag(int now,int len,int tc,ll ta){
	tagc[now]=tc; taga[now]+=ta;
	col[now]=tc; sum[now]+=ta*len;
}
void pushdown(int now,int l,int r,int mid){
	if (tagc[now]){
		puttag(ls,mid-l+1,tagc[now],taga[now]);
		puttag(rs,r-mid,tagc[now],taga[now]);		
		tagc[now]=0; taga[now]=0;
	}
}
void build(int now,int l,int r){
	if (l==r){
		col[now]=l; sum[now]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
void change(int now,int l,int r,int x,int y,int c){
	if (x<=l&&r<=y&&col[now]!=-1){
		puttag(now,r-l+1,c,myabs(c-col[now]));
		return;
	}
	int mid=(l+r)>>1; pushdown(now,l,r,mid);
	if (x<=mid) change(ls,l,mid,x,y,c);
	if (y>mid) change(rs,mid+1,r,x,y,c);
	pushup(now);
}
ll query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y) return sum[now];
	int mid=(l+r)>>1; pushdown(now,l,r,mid);
	ll res=0;
	if (x<=mid) res+=query(ls,l,mid,x,y);
	if (y>mid) res+=query(rs,mid+1,r,x,y);
	return res;
}
int main(){
	n=read(); m=read();
	build(1,1,n);
	int op,l,r;
	for (int i=1;i<=m;i++){
		op=read(); l=read(); r=read();
		if (op==1) change(1,1,n,l,r,read());
		else printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}