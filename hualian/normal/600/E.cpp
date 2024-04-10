#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
int min(int &x,int &y){return x>y?y:x;}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
struct point{int l,r,mx;long long sum;}t[N*20];
int rt[N];
struct tree{
	#define ls t[p].l
	#define rs t[p].r
	int idx;
	void push_up(int p){
		t[p].mx=max(t[ls].mx,t[rs].mx);t[p].sum=0;
		t[p].sum+=(t[ls].mx==t[p].mx?t[ls].sum:0);
		t[p].sum+=(t[rs].mx==t[p].mx?t[rs].sum:0);
	}
	void add(int &p,int l,int r,int x){
		p=++idx;
		if(l==r){t[p].mx=1;t[p].sum=l;return;}
		int mid=(l+r)>>1;
		if(mid>=x)add(ls,l,mid,x);
		else add(rs,mid+1,r,x);
		push_up(p);
	}
	int merge(int p1,int p2,int l,int r){
		if(p1*p2==0)return p1|p2;
		if(l==r){t[p1].mx+=t[p2].mx;return p1;}
		int mid=(l+r)>>1;
		t[p1].l=merge(t[p1].l,t[p2].l,l,mid);
		t[p1].r=merge(t[p1].r,t[p2].r,mid+1,r);
		push_up(p1);return p1;
	}
}T;
vector<int>e[N];
long long ans[N];
void dfs(int x,int fa){
	for(int to:e[x])if(to!=fa){
		dfs(to,x);
		rt[x]=T.merge(rt[x],rt[to],1,n);
	}
	ans[x]=t[rt[x]].sum;
}
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)T.add(rt[i],1,n,read());
	rep(i,n-1){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}dfs(1,0);
	rep(i,n)printf("%lld ",ans[i]);
	return 0;
}