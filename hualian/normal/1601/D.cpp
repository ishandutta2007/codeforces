#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,d;
struct node{
	int s,a;
	bool operator<(const node&X)const{
		return max(s,a)==max(X.s,X.a)?(s<X.s):max(s,a)<max(X.s,X.a);
	}
}a[N];
int mx[N<<2],tag[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_up(int p){mx[p]=max(mx[ls],mx[rs]);}
	void push_down(int p){
		tag[ls]+=tag[p];tag[rs]+=tag[p];
		mx[ls]+=tag[p];mx[rs]+=tag[p];
		tag[p]=0;
	}
	int get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return mx[p];
		int mid=(l+r)>>1,res=-1e9;push_down(p);
		if(mid>=nl)chmx(res,get(ls,l,mid,nl,nr));
		if(mid<nr)chmx(res,get(rs,mid+1,r,nl,nr));
		push_up(p);
		return res;
	}
	void add(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){tag[p]++;mx[p]++;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr);
		if(mid<nr)add(rs,mid+1,r,nl,nr);
		push_up(p);
		return;
	}
	void change(int p,int l,int r,int x,int v){
		if(l==r){chmx(mx[p],v);return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=x)change(ls,l,mid,x,v);
		else change(rs,mid+1,r,x,v);
		push_up(p);
	}
}T;
int b[2*N],lim;
int get(int x){return lower_bound(b+1,b+1+lim,x)-b;}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),d=read();b[++lim]=d;
	rep(i,n){
		a[i].s=read(),a[i].a=read();
		b[++lim]=a[i].s;b[++lim]=a[i].a;
	}
	sort(b+1,b+1+lim);lim=unique(b+1,b+1+lim)-b-1;
	rep(i,n)a[i].s=get(a[i].s),a[i].a=get(a[i].a);
	sort(a+1,a+1+n);
	memset(mx,0xc0,sizeof mx);d=get(d);
	T.change(1,1,lim,d,0);
	rep(i,n){
		int res=0;
		if(a[i].s<a[i].a){
			res=T.get(1,1,lim,1,a[i].s)+1;
			T.change(1,1,lim,a[i].a,res);
		}else{//s>=a 
			res=T.get(1,1,lim,1,a[i].a)+1;
			T.change(1,1,lim,a[i].a,res);
			if(a[i].a!=a[i].s)T.add(1,1,lim,a[i].a+1,a[i].s);
		}
	}
	cout<<T.get(1,1,lim,1,lim);
	return 0;
}