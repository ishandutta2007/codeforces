#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int n,cnt;
int fib[N],mp[N];
int hed[N];
int vis[N],used[N];
struct edge{
	int r,nxt,id;
}e[N<<1];
void insert(int u,int v,int w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].id=w;
}
int fa[N],sz[N];
void dfs1(int x,int t){
	vis[x]=t;sz[x]=1;
	for(int i=hed[x];i;i=e[i].nxt){
		if(used[e[i].id]) continue;
		if(e[i].r==fa[x]) continue;
		fa[e[i].r]=x;
		dfs1(e[i].r,t);
		sz[x]+=sz[e[i].r];
	}
}
int X;
int tp;
int q[N];
void dfs2(int x){
	for(int i=hed[x];i;i=e[i].nxt){
		if(used[e[i].id]) continue;
		if(e[i].r==fa[x]) continue;
		dfs2(e[i].r);
		if(mp[sz[e[i].r]]==X-1||mp[sz[e[i].r]]==X-2){
			q[++tp]=e[i].id;
		}
	}
}
void MAIN(){
	n=read();
    fib[1]=1;fib[2]=2;
    mp[1]=1;mp[2]=2;
    for(int i=3;;++i){
    	fib[i]=fib[i-1]+fib[i-2];
    	if(fib[i]>n) break;
    	mp[fib[i]]=i;
	}
	int u,v;
	for(int i=1;i<n;++i){
		u=read();v=read();
		insert(u,v,i);
		insert(v,u,i);
	}
	int mx=n,t=0;
	int flag=0;
	while(mx>3){
		++t;mx=0;
		for(int i=1;i<=n;++i){
			if(vis[i]!=t){
				fa[i]=0;
				dfs1(i,t);
				mx=max(mx,sz[i]);
				if(mp[sz[i]]==0){
					flag=1;break;
				}
				if(sz[i]<=3) continue;
				tp=0;X=mp[sz[i]];
				dfs2(i);
				if(!tp){
					flag=1;break;
				}
				while(tp>0){
					used[q[tp]]=1;
					--tp;
				}
			}
		}
		if(flag==1) break;
	}
	if(flag) puts("NO");
	else puts("YES");
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}