#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,q; 
struct edge{
	int pre,to,w;
}e[2*N];int last[N],cnt=1;
void add(int x,int y,int w){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	e[cnt].w=w;
	last[x]=cnt;
}
int dfn[N],low[N],idx,color,c[N];
int sta[N],top;
void tarjan(int x){
	dfn[x]=low[x]=++idx;sta[++top]=x;
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;
		if(!dfn[to]){
			tarjan(to);
			chmn(low[x],low[to]);
		}else if(!c[to])chmn(low[x],dfn[to]);
	}
	if(low[x]!=dfn[x])return;
	++color;do c[sta[top--]]=color;while(sta[top+1]!=x);
	
}
int vis[N],g[N],dis[N];
void dfs(int x){
	vis[x]=1;
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;
		if(c[to]!=c[x]||vis[to])continue;
		dis[to]=dis[x]+e[i].w;dfs(to);
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,m){
		int x=read(),y=read(),w=read();
		add(x,y,w);
	}
	rep(i,n)if(!dfn[i])tarjan(i);
	rep(i,n)if(!vis[i])dfs(i);
	rep(x,n)for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(c[x]!=c[to])continue;
		int w=abs(e[i].w+dis[x]-dis[to]);
		g[c[x]]=__gcd(g[c[x]],w);
	}
	q=read();while(q--){
		int x=read(),s=read(),t=read();
		if(!g[c[x]]&&s!=0){puts("NO");continue;}
		if(s%__gcd(t,g[c[x]])==0)puts("YES");
		else puts("NO");
	}
	return 0;
}