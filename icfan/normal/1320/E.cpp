#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,q;
int fa[18][Maxn+5];
int dep[Maxn+5];
int dfn[Maxn+5],out[Maxn+5],dfn_tot;
void init_dfs(int u){
	dfn[u]=++dfn_tot;
	dep[u]=dep[fa[0][u]]+1;
	for(int i=1;fa[i-1][fa[i-1][u]];i++){
		fa[i][u]=fa[i-1][fa[i-1][u]];
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[0][u]){
			continue;
		}
		fa[0][v]=u;
		init_dfs(v);
	}
	out[u]=dfn_tot;
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=17;i>=0;i--){
		if(dep[fa[i][u]]>=dep[v]){
			u=fa[i][u];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=17;i>=0;i--){
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	}
	return fa[0][u];
}
int find_dis(int u,int v){
	return dep[u]+dep[v]-(dep[find_lca(u,v)]<<1);
}
int sp[Maxn+5],type[Maxn+5];
int f[Maxn+5];
int lim[Maxn<<2|5],lim_len;
int pa[Maxn+5];
int imp[Maxn+5];
int st[Maxn+5],st_top;
int get_time(int u,int v){
	return (find_dis(u,v)+sp[type[u]]-1)/sp[type[u]];
}
int merge(int u,int a,int b){
	if(u==0){
		return 0;
	}
	if(a==0){
		return b;
	}
	if(b==0){
		return a;
	}
	int dis_a=get_time(a,u),dis_b=get_time(b,u);
	if(dis_a==dis_b){
		return type[a]<type[b]?a:b;
	}
	return dis_a<dis_b?a:b;
}
bool cmp(int p,int q){
	return dfn[p]<dfn[q];
}
int main(){
	read(n);
	int u,v;
	for(int i=1;i<n;i++){
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1);
	read(q);
	int k,m;
	for(int i=1;i<=q;i++){
		read(k),read(m);
		lim_len=0;
		for(int j=1;j<=k;j++){
			read(u),read(v);
			type[u]=j;
			sp[j]=v;
			f[u]=u;
			lim[++lim_len]=u;
		}
		for(int j=1;j<=m;j++){
			read(u);
			lim[++lim_len]=u;
			imp[j]=u;
		}
		sort(lim+1,lim+1+lim_len,cmp);
		for(int j=lim_len-1;j>0;j--){
			lim[++lim_len]=find_lca(lim[j],lim[j+1]);
		}
		sort(lim+1,lim+1+lim_len,cmp);
		lim_len=unique(lim+1,lim+1+lim_len)-lim-1;
		st_top=0;
		for(int j=1;j<=lim_len;j++){
			while(st_top&&out[st[st_top]]<dfn[lim[j]]){
				st_top--;
			}
			if(st_top){
				pa[lim[j]]=st[st_top];
			}
			st[++st_top]=lim[j];
		}
		for(int j=lim_len;j>0;j--){
			f[pa[lim[j]]]=merge(pa[lim[j]],f[pa[lim[j]]],f[lim[j]]);
		}
		for(int j=1;j<=lim_len;j++){
			f[lim[j]]=merge(lim[j],f[lim[j]],f[pa[lim[j]]]);
		}
		for(int j=1;j<=m;j++){
			printf("%d ",type[f[imp[j]]]);
		}
		puts("");
		for(int j=1;j<=lim_len;j++){
			type[lim[j]]=0;
			f[lim[j]]=0;
			pa[lim[j]]=0;
		}
	}
	return 0;
}