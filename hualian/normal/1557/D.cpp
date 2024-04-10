#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+9;
const int LEN=6e5;
bool ppp;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m;
int b[2*N],lim;
struct line{
	int id,l,r;
	void input(){
		id=read();
		l=read(),r=read();
		b[++lim]=l,b[++lim]=r;
	}
	bool operator<(const line&x)const{
		return id<x.id;
	}
}a[N];
inline void get(int &x){
	x=lower_bound(b+1,b+1+lim,x)-b;
	return;
}
struct node{
	int mx,id;
	node(int M=0,int I=0):mx(M),id(I){}
};
inline node max(node x,node y){
	if(x.mx>y.mx)return x;
	return y;
}
struct point{
	node tag;
	node w;
}t[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void push_up(int p){
		t[p].w=max(t[ls].w,t[rs].w);
		return;
	}
	inline void push_down(int p){
		if(!t[p].tag.mx)return;
		t[ls].w=t[rs].w=t[p].tag;
		t[ls].tag=t[rs].tag=t[p].tag;
		t[p].tag=node(0,0);
		return;
	}
	inline node find(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){
			return t[p].w;
		}
		int mid=(l+r)>>1;node res=node(0,0);
		push_down(p);
		if(mid>=nl)res=max(res,find(ls,l,mid,nl,nr));
		if(mid<nr)res=max(res,find(rs,mid+1,r,nl,nr));
		push_up(p);
		return res;
	}
	inline void change(int p,int l,int r,int nl,int nr,node x){
		if(nl<=l&&r<=nr){
			t[p].w=x;
			t[p].tag=x;
			return;
		}
		int mid=(l+r)>>1;
		push_down(p);
		if(mid>=nl)change(ls,l,mid,nl,nr,x);
		if(mid<nr)change(rs,mid+1,r,nl,nr,x);
		push_up(p);
		return ;
	}
}T;
node ans=0;int now;
int pre[N];
int vis[N];
bool pppp;
signed main(){
//		printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		a[i].input();
	sort(b+1,b+1+lim);
	lim=unique(b+1,b+1+lim)-b-1;
	for(int i=1;i<=m;i++){
		get(a[i].l);
		get(a[i].r);
	}
	sort(a+1,a+1+m);
	int l=1;
	for(int i=1;i<=n;i++){
		int r=l-1;
		while(a[r+1].id==i)r++;
		node res=node(0,0);
		for(int j=l;j<=r;j++)
			res=max(res,T.find(1,1,LEN,a[j].l,a[j].r));
		pre[i]=res.id;
		res.mx++;
		res.id=i;
		ans=max(ans,res);
		for(int j=l;j<=r;j++)
			T.change(1,1,LEN,a[j].l,a[j].r,res);
		
		l=r+1;
	}
	cout<<n-ans.mx<<endl;
	now=ans.id;
	while(now)vis[now]=1,now=pre[now];
	for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);
	return 0;

}