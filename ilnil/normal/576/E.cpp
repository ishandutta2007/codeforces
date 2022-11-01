#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define put putchar
#define yes (put('Y'),put('E'),put('S'),put('\n'))
#define no (put('N'),put('O'),put('\n'))
#define P pair<int*,int>
using namespace std;
const int N=5e5+5,K=51;
int n,m,k,q;
int e[N],c[N],col[N],ne[N],la[N];
int a[N],b[N];
vector<int>ch[N*4];
stack<P>z;
struct Graph{
	int f[N],si[N],g[N];
	int F(int x,bool &d){
		for(;f[x];)d^=g[x],x=f[x];
		return x;
	}
	void init(){fo(i,1,n)si[i]=1;}
	void link(int x,int y){
		bool d=1;
		x=F(x,d);y=F(y,d);
		if(x==y)return;
		if(si[x]>si[y])swap(x,y);
		z.push(P(&si[y],si[y]));
		si[y]+=si[x];
		f[x]=y;g[x]=d;
		z.push(P(&f[x],0));
		z.push(P(&g[x],d));
	}
}g[K];
void push(int v,int l,int r,int pl,int pr){
	if(pl<=l&&r<=pr){
		ch[v].emplace_back(pl-1);
		return;
	}
	int m=l+r>>1;
	if(pl<=m)push(v*2,l,m,pl,pr);
	if(m<pr)push(v*2+1,m+1,r,pl,pr);
}
void cut(int lds){
	for(;z.size()>lds;z.pop())*z.top().first=z.top().second;
}
void go(int v,int l,int r){
	int lds=z.size();
	for(int i:ch[v])g[c[i]].link(a[e[i]],b[e[i]]);
	if(l==r){
		bool d=1;
		if(g[c[l]].F(a[e[l]],d)==g[c[l]].F(b[e[l]],d)&&d)c[l]=col[e[l]],no;else col[e[l]]=c[l],yes;
		if(c[l]&&l<q)push(1,1,q,l+1,ne[l]);
		cut(lds);
		return;
	}
	go(v*2,l,l+r>>1);go(v*2+1,l+r+2>>1,r);
	cut(lds);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>q;
	fo(i,1,m)cin>>a[i]>>b[i],la[i]=q;
	fo(i,1,k)g[i].init();
	fo(i,1,q)cin>>e[i]>>c[i];
	fd(i,1,q)ne[i]=la[e[i]],la[e[i]]=i;
	go(1,1,q);
}