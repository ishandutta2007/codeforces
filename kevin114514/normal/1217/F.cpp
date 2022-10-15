#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#define ll long long
#define db double
#define rint register int
#define re register
#define pint pair<int,int>
#define eps 1e-10
#define Son 26
#define inf 1000000007
#define mk make_pair
#define IT set<pint>::iterator
#define fs first
#define sd second
#define N 400005
#define block 3000
using namespace std;
inline char get(){
	const int TOP=1<<20;
	static char T[TOP],*x=T,*y=T;
	return x==y&&(y=(x=T)+fread(T,1,TOP,stdin),x==y)?EOF:*x++;
}
inline int read (){
	register int num,sign=1;register char c;
	while (((c=get())<'0'||c>'9')&&c!='-');c=='-'?num=sign=0:num=c-48;
	while ((c=get())>='0'&&c<='9')num=(num<<3)+(num<<1)+(c-48);
	return sign?num:-num;
}
int n,m,top,last;
int opt[N];
set<pint>a,b,c;
pint q[N][2],st[N];
int ans[N],size[N],father[N];
inline void add(set<pint>&s,pint x){if(s.count(x)<1)s.insert(x);else s.erase(x);}
inline int find(rint x){if(father[x]==x)return x;return find(father[x]);}
inline void merge(rint x,rint y){
	x=find(x);y=find(y);if(x==y)return;
	if(size[x]<size[y])swap(x,y);st[++top]=mk(x,y);
	size[x]+=size[y];father[y]=x;
}
inline void cal(rint time){
	while(top!=time){
		rint x=st[top].fs,y=st[top].sd;
		father[y]=y;size[x]-=size[y];--top;
	}
}
inline void solve(){
	for(rint i=1;i<=n;++i)father[i]=i,size[i]=1;top=0;
	for(IT it=c.begin();it!=c.end();++it)merge((*it).fs,(*it).sd);last=top;
}
int main(){
	n=read();m=read();
	for(rint pos=1,x,y;pos<=m;pos+=block){
		rint l,r;l=pos,r=min(m,l+block-1);
		a.clear();b.clear();c.clear();
		for(rint i=l;i<=r;++i){
			opt[i]=read();x=read();y=read();
			if(x>y)swap(x,y);q[i][0]=mk(x,y);
			x=x%n+1;y=y%n+1;
			if(x>y)swap(x,y);q[i][1]=mk(x,y);
			if(opt[i]==1)a.insert(q[i][0]),a.insert(q[i][1]);
		}
		for(rint i=1;i<l;++i)if(opt[i]==1){if(a.count(q[i][ans[i]])<1)add(c,q[i][ans[i]]);else add(b,q[i][ans[i]]);}
		solve();
		for(rint i=l;i<=r;++i){
			if(opt[i]==1){ans[i]=ans[i-1];add(b,q[i][ans[i]]);continue;}
			cal(last);
			for(IT it=b.begin();it!=b.end();++it)merge((*it).fs,(*it).sd);
			ans[i]=(find(q[i][ans[i-1]].fs)==find(q[i][ans[i-1]].sd));
		}
	}
	for(rint i=1;i<=m;++i)if(opt[i]==2)putchar(ans[i]+'0');
}