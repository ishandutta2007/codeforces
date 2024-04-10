#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
const int lim=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans,a[N];
int max(int x,int y){return x>y?x:y;}
void chmx(int &x,int y){(x<y)?(x=y):0;}
vector<int>e[N];
struct point{int l,r,mx;};
struct tree{
	#define ls t[p].l
	#define rs t[p].r
	point t[N<<2];int rt[N];
	int idx;tree(){idx=0;memset(rt,0,sizeof rt);}
	void add(int &p,int l,int r,int x,int v){
		if(!p){p=++idx;t[p].l=t[p].r=t[p].mx=0;}
		if(l==r){chmx(t[p].mx,v);return;}
		int mid=(l+r)>>1;
		if(mid>=x)add(ls,l,mid,x,v);
		else add(rs,mid+1,r,x,v);
		t[p].mx=max(t[ls].mx,t[rs].mx);
	}
	int merge(int p1,int p2,int l=1,int r=lim){
		if(p1*p2==0)return p1|p2;
		chmx(t[p1].mx,t[p2].mx);
		if(l==r)return p1;int mid=(l+r)>>1;
		t[p1].l=merge(t[p1].l,t[p2].l,l,mid);
		t[p1].r=merge(t[p1].r,t[p2].r,mid+1,r);
		return p1;
	}
	int get(int p,int l,int r,int nl,int nr){
		if(nl>nr)return 0;
		if(!p||(nl<=l&&r<=nr))return t[p].mx;
		int mid=(l+r)>>1,res=0;
		if(mid>=nl)chmx(res,get(ls,l,mid,nl,nr));
		if(mid<nr)chmx(res,get(rs,mid+1,r,nl,nr));
		return res;
	}
}T1,T2;//12 
void calc(int p1,int p2,int l=1,int r=lim){
	if(p1*p2==0)return;
	chmx(ans,T1.t[T1.t[p1].l].mx+T2.t[T2.t[p2].r].mx);
	if(l==r)return;
	int mid=(l+r)>>1;
	calc(T1.t[p1].l,T2.t[p2].l,l,mid);
	calc(T1.t[p1].r,T2.t[p2].r,mid+1,r);
}
void dfs(int x,int fa){
	int mx1=0,mx2=0;
	for(int to:e[x])if(to!=fa){
		dfs(to,x);
		int a1=T1.get(T1.rt[to],1,lim,1,a[x]-1);
		int a2=T2.get(T2.rt[to],1,lim,a[x]+1,lim);
		chmx(ans,mx1+a2+1);chmx(ans,a1+mx2+1);
		chmx(mx1,a1);chmx(mx2,a2);
		calc(T1.rt[x],T2.rt[to]);
		calc(T1.rt[to],T2.rt[x]);
		T1.rt[x]=T1.merge(T1.rt[x],T1.rt[to]);
		T2.rt[x]=T2.merge(T2.rt[x],T2.rt[to]);
	}
	T1.add(T1.rt[x],1,lim,a[x],mx1+1);
	T2.add(T2.rt[x],1,lim,a[x],mx2+1);
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)a[i]=read();
	rep(i,n-1){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	chmx(ans,T1.get(T1.rt[1],1,lim,1,lim));
	chmx(ans,T2.get(T2.rt[1],1,lim,1,lim));
	cout<<ans<<endl;
	return 0;
}
/*
5
1 6 3 4 5
1 2
2 3
3 4
3 5
*/