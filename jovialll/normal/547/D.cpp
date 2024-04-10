#include<bits/stdc++.h>
using namespace std;
#define N 800005
#define M 200001
struct edge{int to,nxt,pos;}e[N<<2];
int tot,node[N],vst[N],n;
void add(int x,int y,int i){
	e[++tot].nxt=node[x];e[tot].pos=i;e[tot].to=y;node[x]=tot;
}void dfs(int now){
	for(int&i=node[now];i;i=e[i].nxt)if(!vst[e[i].pos]){vst[e[i].pos]=1+(now>M),dfs(e[i].to);}
}int i,x,y,deg[N],cnt;main(){
	cin>>n;for(i=1;i<=n;++i)cin>>x>>y,add(x,y+M,i),add(y+M,x,i),++deg[x],++deg[y+M];
	for(i=1;i<M+M;++i)if(deg[i]&1)++cnt,add(i,N-1,n+cnt),add(N-1,i,n+cnt);
	for(i=1;i<N;++i)dfs(i);
	for(i=1;i<=n;++i)putchar((vst[i]&1)?'r':'b');
}