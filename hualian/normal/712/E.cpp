#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
double a[N];
struct node{
	double f,g;
	node(){f=g=0;}
	node(double f,double g):f(f),g(g){} 
	node operator+(const node&x){
		node c;
		c.f=f*x.f/(1-(1-x.f)*(1-g));
		c.g=g*x.g/(1-(1-x.f)*(1-g));
		return c;
	}
}t[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void build(int p,int l,int r){
		if(l==r){t[p]=node(a[l],1-a[l]);return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[p]=t[ls]+t[rs];
	}
	void change(int p,int l,int r,int x){
		if(l==r){t[p]=node(a[x],1-a[x]);return;}
		int mid=(l+r)>>1;
		if(mid>=x)change(ls,l,mid,x);
		else change(rs,mid+1,r,x);
		t[p]=t[ls]+t[rs];
	}
	node get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return t[p];
		int mid=(l+r)>>1;
		if(mid>=nl&&mid<nr)
			return get(ls,l,mid,nl,nr)+get(rs,mid+1,r,nl,nr);
		return mid>=nl?get(ls,l,mid,nl,nr):get(rs,mid+1,r,nl,nr);
	}
}T;
int n,q;
int main(){
//	freopen(".in","r",stdin);
//	froepen(".out","w",stdout);
	n=read(),q=read();
	rep(i,n)a[i]=1.0*read()/read();
	T.build(1,1,n);
	while(q--){
		int op=read();
		if(op==1){
			int x=read();
			a[x]=1.0*read()/read();
			T.change(1,1,n,x);
		}else{
			int l=read(),r=read();
			printf("%.6lf\n",T.get(1,1,n,l,r).f);
		}
	}
	return 0;
}