#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=6e5+9;
const int lim=1e9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q;
int a[N],cnt[N<<1],mn[N<<1],tag[N<<1];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_down(int p){
		tag[ls]+=tag[p];tag[rs]+=tag[p];
		mn[ls]+=tag[p];mn[rs]+=tag[p];
		tag[p]=0;
	}
	void push_up(int p){
		mn[p]=min(mn[ls],mn[rs]);
		cnt[p]=cnt[ls]+cnt[rs];
	}
	void change(int p,int l,int r,int x,int v){
		if(l==r){mn[p]=v;if(v==lim)cnt[p]=1;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=x)change(ls,l,mid,x,v);
		else change(rs,mid+1,r,x,v);
		push_up(p);
	}
	void add(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){tag[p]--;mn[p]--;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr);
		if(mid<nr)add(rs,mid+1,r,nl,nr);
		push_up(p);
	}
	int del(int p,int l,int r){
		if(l==r){return l;}
		int mid=(l+r)>>1,res=0;push_down(p);
		if(mn[ls]<0)res=del(ls,l,mid);
		else if(mn[rs]<0)res=del(rs,mid+1,r);
		push_up(p);return res;
	}
	int get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return (r-l+1-cnt[p]);
		int mid=(l+r)>>1,res=0;push_down(p);
		if(mid>=nl)res+=get(ls,l,mid,nl,nr);
		if(mid<nr)res+=get(rs,mid+1,r,nl,nr);
		push_up(p);return res;
	}
	int getval(int p,int l,int r,int x){
		if(l==r)return mn[p];
		int mid=(l+r)>>1,res=0;push_down(p);
		if(mid>=x)res=getval(ls,l,mid,x);
		else res=getval(rs,mid+1,r,x);
		push_up(p);return res;
	}
}T;
struct node{
	int l,r,id;
	bool operator<(const node&x)const{return l<x.l;}
}A[N];int ans[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();
	//can<=need 
	rep(i,n)a[i]=read()-1,T.change(1,1,n,i,a[i]);
	rep(i,n)if(a[i]+1>i)T.add(1,1,n,i,n),T.change(1,1,n,i,lim);
	while(mn[1]<0){
		int x=T.del(1,1,n);
		T.add(1,1,n,x,n);
		T.change(1,1,n,x,lim);
	}
	rep(i,q)A[i].l=read(),A[i].r=read(),A[i].id=i;
	sort(A+1,A+1+q);
	int now=1;
	rep(i,q){
		while(now<=A[i].l){
			if(T.get(1,1,n,now,now)){
				T.add(1,1,n,now,n);
				T.change(1,1,n,now,lim);
			}
			now++;
			while(mn[1]<0){
				int x=T.del(1,1,n);
				T.add(1,1,n,x,n);
				T.change(1,1,n,x,lim);
			}
		}
		ans[A[i].id]=T.get(1,1,n,1,n-A[i].r);
	}
	while(mn[1]<0){
		int x=T.del(1,1,n);
		T.add(1,1,n,x,n);
		T.change(1,1,n,x,lim);
	}
	rep(i,q)printf("%d\n",ans[i]);
	return 0;
}