/*********************************************************************
 * Source - lyp
 * ProblemCF1174F
 * Authorhydd
 * Date2020/10/13
*********************************************************************/
#include<cstdio>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
int n,sz[210000],fa[210000],son[210000],dfn[210000],cnt,num[210000],sond[210000],dep[210000];
int edgenum,vet[410000],Next[410000],Head[210000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void dfs(int u,int f){
	sz[u]=1; fa[u]=f; dep[u]=dep[f]+1;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f){
			dfs(vet[e],u);
			sz[u]+=sz[vet[e]];
			if (sz[vet[e]]>sz[son[u]]) son[u]=vet[e];
		}
}
void dfs2(int u){
	dfn[u]=++cnt; num[cnt]=u;
	if (son[u]){
		dfs2(son[u]);
		sond[u]=sond[son[u]];
	} else sond[u]=u;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa[u]&&vet[e]!=son[u]) dfs2(vet[e]);
}
int d;
int solve(int u){
	int v=sond[u];
	printf("d %d\n",v); fflush(stdout);
	int dis; scanf("%d",&dis);
	if (dis==0) return v;
	int tmp=(d+dep[v]-dis)/2-dep[u];
	int x=num[dfn[u]+tmp];
	if (dep[x]==d) return x;
	printf("s %d\n",x); fflush(stdout);
	scanf("%d",&x); return solve(x);
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dep[0]=-1; dfs(1,0); dfs2(1);
	puts("d 1"); fflush(stdout);
	scanf("%d",&d);
	printf("! %d\n",solve(1));
	return 0;
}