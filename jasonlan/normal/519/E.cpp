#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=101000,maxm=201000;
int n;
int head[maxn],nxt[maxm],rdc[maxm],len[maxm],tnt;
int dep[maxn],siz[maxn],f[19][maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
void dfs(int p){
	siz[p]=1;
	for(register int i=1;f[i-1][p];++i)
		f[i][p]=f[i-1][f[i-1][p]];
	for(register int i=head[p];i;i=nxt[i])
		if(!dep[rdc[i]]){
			dep[rdc[i]]=dep[p]+1;
			f[0][rdc[i]]=p;
			dfs(rdc[i]);
			siz[p]+=siz[rdc[i]];
		}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(register int i=18;~i;--i)
		if((dep[x]-dep[y])>>i)
			x=f[i][x];
	if(x==y)return y;
	for(register int i=18;~i;--i)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x];
}
int jump(int x,int k){
	for(register int i=18;~i;--i)
		if(k>>i)x=f[i][x],k^=1<<i;
	return x;
}
int main(){
	n=read();
	for(register int i=1,u,v;i<n;++i){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	dep[1]=1;dfs(1);
	for(register int T=read(),x,y,l,dlen;T;--T){
		x=read();y=read();
		l=lca(x,y);
		dlen=(dep[x]+dep[y]-dep[l]*2);
		if(dlen&1)puts("0");
		else{
			if(dep[x]==dep[y]){
				x=jump(x,(dlen>>1)-1);
				y=jump(y,(dlen>>1)-1);
				printf("%d\n",n-siz[x]-siz[y]);
			}
			else{
				if(dep[x]<dep[y])swap(x,y);
				x=jump(x,(dlen>>1)-1);
				printf("%d\n",siz[f[0][x]]-siz[x]);
			}
		}
	}
	return 0;
}