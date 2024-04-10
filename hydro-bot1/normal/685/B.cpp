// Hydro submission #614c84607fab56821a8712bd@1632404577585
#include <bits/stdc++.h>
using namespace std;
const int N=300010;
inline int read(){
	int x=0;bool f=false;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=true;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
inline void write(int x,char ed='\n'){
	if(x<0) putchar('-'),x=-x;
	static int num[30],nm=0;
	do num[++nm]=x%10,x/=10;while(x);
	while(nm) putchar(num[nm--]^48);
	putchar(ed);
}
struct edge{
	int to,next;
}edges[N<<1];
int n,q;
int h[N],tot;
int fa[N];
int siz[N],mx[N],rt[N];
void add(int u,int v){
	edges[tot].to=v;
	edges[tot].next=h[u];
	h[u]=tot++;
}
void dfs(int u,int f){
	siz[u]++;fa[u]=f;
	for(int i=h[u];i!=-1;i=edges[i].next){
		int v=edges[i].to;
		if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		mx[u]=max(mx[u],siz[v]);
	}
	int id=u,me=mx[u];
	for(int i=h[u];i!=-1;i=edges[i].next){
		int v=edges[i].to;
		if(v==f) continue;
		int it=rt[v],pre=max(mx[it],siz[u]-siz[it]),p=it;
		while(fa[it]!=u){
			it=fa[it];
			int New=max(mx[it],siz[u]-siz[it]);
			if(New<pre) pre=New,p=it;
			else break;
		}
		if(me>pre) pre=me,id=p;
	}
	rt[u]=id;
}
signed main(){
	memset(h,-1,sizeof h);
	n=read();q=read();
	for(int i=2;i<=n;i++){
		int u=read();
		add(u,i);add(i,u);
	}
	dfs(1,0);
	while(q--) write(rt[read()]);
	return 0;
}