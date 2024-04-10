#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,m,s,vis[N],cur[N],tot;
int U,V,fa[N];
void dfs(int u,int f,int c){
//	printf("%d -> %d [%d]\n",f,u,c);
	vis[u]=1,cur[u]=c,fa[u]=f;
	if(U)return;
	go(u){
		int v=to[i];
		if(U)break;
		if(vis[v]){
			if(cur[u]!=cur[v]&&v!=s)
				U=u,V=v;
		}else dfs(v,u,c);
	}
}int stk[N],tp;
signed main(){
	n=read(),m=read(),s=read();
	For(i,1,m){
		int u=read(),v=read();
		add(u,v);
	}vis[s]=1;go(s)if(!vis[to[i]])dfs(to[i],s,++tot);else{
		V=to[i],U=s;break;
	}
	if(!U)return puts("Impossible"),0;
	puts("Possible");
	stk[++tp]=V;int x=U;while(x!=s)stk[++tp]=x,x=fa[x];stk[++tp]=s;
	printf("%d\n",tp);Rof(i,tp,1)printf("%d ",stk[i]);puts("");
	tp=0,x=V;while(x!=s)stk[++tp]=x,x=fa[x];stk[++tp]=s;
	printf("%d\n",tp);Rof(i,tp,1)printf("%d ",stk[i]);puts("");
	return 0;
}
/*
4 5 1
1 2
2 3
1 4
4 5
5 2

*/