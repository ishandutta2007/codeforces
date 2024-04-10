#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,q,fa[110000][18],dep[110000],sz[110000];
ll s1[110000],s2[110000];
int edgenum,vet[210000],Next[210000],Head[110000];
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
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
	while (ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=Getchar();
	return x*f;
}
void dfs(int u,int f){
	fa[u][0]=f; dep[u]=dep[f]+1;
	sz[u]=1; s1[u]=dep[u];
	for (int i=1;(1<<i)<dep[u];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f){
			dfs(vet[e],u);
			sz[u]+=sz[vet[e]];
			s1[u]+=s1[vet[e]];
		}
}
void dfs2(int u,int f){
	if (f) s2[u]=s2[f]+(s1[f]-s1[u])-2ll*dep[f]*(sz[f]-sz[u]);
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f) dfs2(vet[e],u);
}
int jump(int u,int d){
	for (int i=17;i>=0;i--)
		if (d&(1<<i)) u=fa[u][i];
	return u;
}
int LCA(int u,int v){//dep[u]>dep[v]
	u=jump(u,dep[u]-dep[v]);
	if (u==v) return u;
	for (int i=17;i>=0;i--)
		if (fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
void print(ll a,ll b){
	printf("%.8lf\n",1.0*a/b);
}
int main(){
	n=read(); q=read(); int u,v;
	for (int i=1;i<n;i++){
		u=read(); v=read();
		addedge(u,v); addedge(v,u);
	}
	dfs(1,0); dfs2(1,0);
	ll tot1,tot2,tot,ans;
	while (q--){
		u=read(); v=read();
		if (dep[u]>dep[v]) swap(u,v);
		int lca=LCA(v,u); ans=0;
		if (lca==u){
			int w=jump(v,dep[v]-dep[u]-1);
			tot1=sz[v]; tot2=n-sz[w]; tot=tot1*tot2;
			ans+=tot2*(s1[v]-dep[v]*tot1);
			ans+=tot1*(s2[w]+dep[u]*tot2);
			ans+=tot*(dep[v]-dep[u]);
			ans+=tot;
		} else{
			tot1=sz[v]; tot2=sz[u]; tot=tot1*tot2;
			ans+=tot2*(s1[v]-dep[v]*tot1);
			ans+=tot1*(s1[u]-dep[u]*tot2);
			ans+=tot*(dep[u]+dep[v]-dep[lca]*2);
			ans+=tot;
		}
		print(ans,tot);
	}
	return 0;
}