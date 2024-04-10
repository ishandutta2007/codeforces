#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7; bool rev[N],fc[N];
int n,m,op,cnt,fa[N],st[N],siz[N],sec[N],val[N],vas[N],pos[N],ch[N][2];
struct edge{
	int u,v,t,q;
}e[N];
bool operator < (edge a,edge b){
	if(a.t==b.t){
		return a.q<b.q;
	}
	return a.t>b.t;
}
set<edge>f;
inline bool get(int u){
	return (ch[fa[u]][1]==u);
}
inline bool isroot(int u){
	return (ch[fa[u]][0]!=u)&&(ch[fa[u]][1]!=u);
}
inline void update(int u){
	if(val[u]>=max(vas[ch[u][0]],vas[ch[u][1]])) pos[u]=u,vas[u]=val[u];
	if(vas[ch[u][0]]>=max(val[u],vas[ch[u][1]])) pos[u]=pos[ch[u][0]],vas[u]=vas[ch[u][0]];
	if(vas[ch[u][1]]>=max(val[u],vas[ch[u][0]])) pos[u]=pos[ch[u][1]],vas[u]=vas[ch[u][1]];
	siz[u]=siz[ch[u][0]]+siz[ch[u][1]]+sec[u]+1;
}
inline void pushdown(int u){
	if(rev[u]) swap(ch[u][0],ch[u][1]),rev[ch[u][0]]^=1,rev[ch[u][1]]^=1,rev[u]^=1;
}
inline void rotate(int u){
	int pa=fa[u],gr=fa[pa],x=get(u);
	if(!isroot(pa)) ch[gr][get(pa)]=u; fa[u]=gr;
	fa[ch[u][x^1]]=pa,ch[pa][x]=ch[u][x^1],ch[u][x^1]=pa,fa[pa]=u,update(pa),update(u);
}
inline void splay(int u){
	st[st[0]=1]=u;
	for(int x=u;!isroot(x);x=fa[x]) st[++st[0]]=fa[x];
	for(int i=st[0];i>=1;i--) pushdown(st[i]);
	for(;!isroot(u);rotate(u)) if(!isroot(fa[u])) rotate(get(fa[u])==get(u)?fa[u]:u);
}
inline void access(int u){
	for(int i=0;u>0;i=u,u=fa[u])
		splay(u),sec[u]+=siz[ch[u][1]],ch[u][1]=i,sec[u]-=siz[ch[u][1]],update(u);
}
inline void makeroot(int u){
	access(u),splay(u),rev[u]^=1;
}
inline void link(int u,int v){
	makeroot(u),makeroot(v),fa[u]=v,sec[v]+=siz[u],update(v);
}
inline void cut(int u,int v){
	makeroot(u),access(v),splay(v);
	ch[v][0]=0,fa[u]=0,update(v);
}
inline int getit(int u){
	access(u),splay(u); while(ch[u][0]) u=ch[u][0]; return u;
}
inline int read(){
	int num=0; char g=getchar(); while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void cutit(int u){
	cut(e[u].u,u),cut(e[u].v,u),access(e[u].u),access(e[u].v);
	splay(e[u].u),splay(e[u].v),fc[u]=0;
	int a=(siz[e[u].u]+1)/2,b=(siz[e[u].v]+1)/2;
	if(a&1) cnt++; if(b&1) cnt++; if((a+b)&1) cnt--; f.erase(e[u]);
	
}
inline void linkit(int u){
	access(e[u].u),access(e[u].v),splay(e[u].u),splay(e[u].v),fc[u]=1;
	int a=(siz[e[u].u]+1)/2,b=(siz[e[u].v]+1)/2;
	link(e[u].u,u),link(e[u].v,u);
	if(a&1) cnt--; if(b&1) cnt--; if((a+b)&1) cnt++; f.insert(e[u]);
}
inline void write(int u){
	if(u>9) write(u/10); putchar(u%10+'0');
}
int main(){
	n=read(),m=read(); int u,v,t; cnt=n,op=n;
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=1;i<=m;i++){
		u=read(),v=read(),t=read(),op++,vas[op]=t,val[op]=t,siz[op]=1,pos[op]=op;
		e[op].u=u,e[op].v=v,e[op].t=t,e[op].q=op;
		if(getit(u)!=getit(v)) linkit(op);
		else{
			makeroot(u),access(v),splay(v); int x=pos[v];
			if(val[x]>t) cutit(x),linkit(op);
		}
		if(cnt>0) puts("-1");
		else{
			while(!cnt){
				edge c=*f.begin(); cutit(c.q);
				if(cnt>0) {linkit(c.q); break;} f.erase(c);
			}
			write((*f.begin()).t),putchar('\n');
		}
	}
	return 0;
}