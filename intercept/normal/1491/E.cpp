#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,m,num,top;
int head[M],f[M],siz[M];
bool vis[M<<1];
struct P{int to,ne;}e[M<<1];
struct Q{int x,y;}st[M<<6];
void get(int u,int fa,int s){
	siz[u]=1;
	for(int i=head[u],v;i;i=e[i].ne){
		if(!vis[v=e[i].to]&&v!=fa)get(v,u,s),siz[u]+=siz[v];
	}
	if(siz[u]==f[s-2])st[++top]=Q{u,fa};
	if(siz[u]==f[s-1])st[++top]=Q{fa,u};
}
bool dfs(int u,int s){
	if(s<=3)return 1;
	int now=top,p=0;
	get(u,0,s);
	while(top>now){
		int op=1;
		Q o=st[top--];
		vis[o.y]=1;op&=dfs(o.x,s-2);vis[o.y]=0;
		vis[o.x]=1;op&=dfs(o.y,s-1);vis[o.x]=0;
		top=now;
		return op;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(int i=2;;++i){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=n){m=i;break;}
	}
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		e[++num]=P{v,head[u]};head[u]=num;
		e[++num]=P{u,head[v]};head[v]=num;
	}
	if(n==1)m=0;
	if(f[m]>n){printf("NO\n");return 0;}
	if(dfs(1,m))printf("YES\n");
	else printf("NO\n");
	return 0;
}
/*
3
1 2
2 3

*/