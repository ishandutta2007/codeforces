//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,maxv=(1<<22)+5,c=22,inf=0x3f3f3f3f;
struct Edge{int to,nxt;}e[maxn];
int cnt,head[maxn];
int w[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline void chkmx(int &x,int y){x=max(x,y);return ;}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
int hson[maxn];
int siz[maxn],dep[maxn];
int dfsnum,dfn[maxn],rdfn[maxn];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	w[x]^=w[fa];siz[x]=1;
	dfn[x]=++dfsnum;rdfn[dfsnum]=x;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		dfs1(tmp,x);
		siz[x]+=siz[tmp];
		if(siz[hson[x]]<siz[tmp])hson[x]=tmp;
	}
	return ;
}
int f[maxn];
int t[maxv];
void dfs(int x,int fa,bool op){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==hson[x])continue;
		dfs(tmp,x,0);
		chkmx(f[x],f[tmp]);
	}
	if(hson[x])dfs(hson[x],x,1),chkmx(f[x],f[hson[x]]);
	chkmx(f[x],t[w[x]]-dep[x]);
	for(int i=0;i<c;i++)chkmx(f[x],t[w[x]^(1<<i)]-dep[x]);
	chkmx(t[w[x]],dep[x]);
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==hson[x])continue;
		for(int j=dfn[tmp];j<dfn[tmp]+siz[tmp];j++){
			int y=rdfn[j];
			chkmx(f[x],t[w[y]]+dep[y]-2*dep[x]);
			for(int k=0;k<c;k++)chkmx(f[x],t[w[y]^(1<<k)]+dep[y]-2*dep[x]);
		}
		for(int j=dfn[tmp];j<dfn[tmp]+siz[tmp];j++){
			int y=rdfn[j];
			chkmx(t[w[y]],dep[y]);
		}
	}
	if(!op)for(int i=dfn[x];i<dfn[x]+siz[x];i++)t[w[rdfn[i]]]=-inf;
	return ;
}
int main(){
    int n;
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=2;i<=n;i++){
		int x;
		char ch;
		x=read();
		scanf("%c",&ch);
		w[i]=1<<(ch-'a');
		add(x,i);
	}
	dfs1(1,0);
	memset(t,0xcf,sizeof(t));
	dfs(1,0,0);
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	puts("");
    return 0;
}