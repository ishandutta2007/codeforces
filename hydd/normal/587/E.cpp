/*********************************************************************
 * Source
 * ProblemCF587E
 * Authorhydd
 * Date2020/9/8
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<cstring>
#define ls now<<1
#define rs now<<1|1
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,q,a[210000],b[210000];
int tree[210000];
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
void update(int x,int y){
	for (;x<=n;x+=x&-x) tree[x]^=y;
}
int getnum(int x){
	int res=0;
	for (;x;x-=x&-x) res^=tree[x];
	return res;
}
struct Linear_Basis{
	int cnt,v[30];
	void clr(){
		cnt=0;
		memset(v,0,sizeof(v));
	}
	void ins(int x,int lim=29){
		if (cnt==30) return;
		for (int i=lim;i>=0&&x;i--)
			if (x&(1<<i)){
				if (v[i]) x^=v[i];
				else { v[i]=x; cnt++; break;}
			}
	}
	void merge(const Linear_Basis &a){
		for (int i=29;i>=0;i--)
			if (a.v[i]) ins(a.v[i],i);
	}
} tmp,t[810000];
void pushup(int now){ t[now]=t[now<<1]; t[now].merge(t[now<<1|1]);}
void build(int now,int l,int r){
	if (l==r){
		t[now].clr();
		t[now].ins(b[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(now);
}
void change(int now,int l,int r,int x){
	if (l==r){
		t[now].clr();
		t[now].ins(b[l]);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) change(ls,l,mid,x);
	else change(rs,mid+1,r,x);
	pushup(now);
}
void query(int now,int l,int r,int x,int y){
	if (l==x&&r==y){
		tmp.merge(t[now]);
		return;
	}
	int mid=(l+r)>>1;
	if (y<=mid) query(ls,l,mid,x,y);
	else if (x>mid) query(rs,mid+1,r,x,y);
	else { query(ls,l,mid,x,mid); query(rs,mid+1,r,mid+1,y);}
}
int main(){
	n=read(); q=read();
	for (int i=1;i<=n;i++){
		a[i]=read(); b[i]=a[i-1]^a[i];
		update(i,b[i]);
	}
	build(1,1,n); int op,l,r,x;
	while (q--){
		op=read(); l=read(); r=read();
		if (op==1){
			x=read();
			update(l,x); update(r+1,x);
			b[l]^=x; b[r+1]^=x;
			change(1,1,n,l); if (r<n) change(1,1,n,r+1);
		} else{
			tmp.clr();
			tmp.ins(getnum(l));
			if (l<r) query(1,1,n,l+1,r);
			printf("%d\n",1<<tmp.cnt);
		}
	}
	return 0;
}