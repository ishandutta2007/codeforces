#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=101000,maxm=101000,maxv=1e5+10;
int n,m;
int a[maxn];
int fa[maxn],rt[maxv],sz[maxv];
int mx,tag;
struct OP_Note{
	int op;
	int l,r,x,ans;
}q[maxm];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int getf(int x){
	return x==fa[x]?x:(fa[x]=getf(fa[x]));
}
void merge(int x,int y){
	if(!rt[y]){
		rt[y]=rt[x];sz[y]=sz[x];
		a[rt[y]]=y;
	}
	else{
		fa[rt[x]]=rt[y];
		sz[y]+=sz[x];
	}
	sz[x]=rt[x]=0;
}
void build(int L,int R){
	tag=mx=0;
	for(register int i=L;i<=R;++i){
		if(!rt[a[i]])
			rt[a[i]]=fa[i]=i;
		else
			fa[i]=rt[a[i]];
		++sz[a[i]];
		mx=max(a[i],mx);
	}
}
void Modify(int x){
	if((x<<1)<=mx-tag){
		for(register int i=tag+1;i<=x+tag;++i)
			if(rt[i])merge(i,i+x);
		tag+=x;
	}
	else{
		for(register int i=mx;i>x+tag;--i)
			if(rt[i])merge(i,i-x);
		if(tag+x<mx)mx=tag+x;
	}
}
void Modify(int L,int R,int l,int r,int x){
	for(register int i=L;i<=R;++i)
		if(getf(i)==i){
			rt[a[i]]=sz[a[i]]=0;
			a[i]-=tag;
		}
	for(register int i=L;i<=R;++i)
		a[i]=a[getf(i)];
	for(register int i=l;i<=r;++i)
		if(a[i]>x)a[i]-=x;
	build(L,R);
}
int Query(int x){
	return sz[x+tag];
}
int Query(int l,int r,int x){
	int cnt=0;
	for(register int i=l;i<=r;++i)
		if(a[getf(i)]-tag==x)++cnt;
	return cnt;
}
void Proc(int L,int R){
	for(register int i=0;i<maxv;++i)
		rt[i]=sz[i]=0;
	build(L,R);
	for(register int i=1;i<=m;++i){
		if(q[i].r<L||q[i].l>R)continue;
		if(q[i].op==1){
			if(q[i].l>L||q[i].r<R)
				Modify(L,R,max(q[i].l,L),min(q[i].r,R),q[i].x);
			else Modify(q[i].x);
		}
		else{
			if(q[i].l>L||q[i].r<R)
				q[i].ans+=Query(max(q[i].l,L),min(q[i].r,R),q[i].x);
			else q[i].ans+=Query(q[i].x);
		}
	}
}
int main(){
	n=read();m=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	for(register int i=1;i<=m;++i){
		q[i].op=read();
		q[i].l=read();q[i].r=read();q[i].x=read();
	}
	int T=sqrt(n);
	for(register int i=1,L,R;i<=n;i+=T)
		Proc(i,min(n,i+T-1));
	for(register int i=1;i<=m;++i)
		if(q[i].op==2)printf("%d\n",q[i].ans);
	return 0;
}