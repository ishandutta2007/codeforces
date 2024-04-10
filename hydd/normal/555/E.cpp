/*********************************************************************
 * Source
 * ProblemCF555E
 * Authorhydd
 * Date2020/8/30
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<algorithm>
#include<vector>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int MAXN=210000;
const int MAXM=410000;
int n,m,q,u[MAXN],v[MAXN];
int top,st[MAXN],fr[MAXN],dep[MAXN];
int cnt2,fa[MAXN][19]; bool vis[MAXN];
int cnt,num[MAXN],up[MAXN],dw[MAXN];
int dtime,dfn[MAXN],low[MAXN];
vector<int> vec[MAXN];
int edgenum=1,vet[MAXM],Next[MAXM],Head[MAXN];
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
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void tarjan(int u,int le){
	dfn[u]=low[u]=++dtime;
	st[++top]=u; int v;
	for (int e=Head[u];e;e=Next[e]){
		v=vet[e];
		if (e==(le^1)) continue;
		if (!dfn[v]){
			tarjan(v,e);
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		cnt++;
		while (st[top]!=u){ num[st[top]]=cnt; top--;}
		num[st[top]]=cnt; top--;
	}
}
void dfs(int u,int f){
	fr[u]=cnt2; dep[u]=dep[f]+1; fa[u][0]=f;
	for (int i=1;(1<<i)<dep[u];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int v:vec[u]){
		if (v==f) continue;
		dfs(v,u);
	}
}
void dfs2(int u,int f){
	vis[u]=true;
	for (int v:vec[u]){
		if (v==f) continue;
		dfs2(v,u);
		up[u]+=up[v]; dw[u]+=dw[v];
	}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	for (int i=0;i<=18;i++)
		if (d&(1<<i)) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
bool check(){
	int s,t;
	while (q--){
		s=read(); t=read();
		s=num[s]; t=num[t];
		if (fr[s]!=fr[t]) return false;
		int w=LCA(s,t);
		up[s]++; up[w]--;
		dw[t]++; dw[w]--;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs2(i,0);
	for (int i=1;i<=cnt;i++)
		if (up[i]&&dw[i]) return false;
	return true;
}
int main(){
	n=read(); m=read(); q=read();
	edgenum=1;
	for (int i=1;i<=m;i++){
		u[i]=read(); v[i]=read();
		addedge(u[i],v[i]); addedge(v[i],u[i]);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) tarjan(i,0);
	int x,y;
	for (int i=1;i<=m;i++){
		x=num[u[i]]; y=num[v[i]];
		if (x==y) continue;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for (int i=1;i<=cnt;i++)
		if (!fr[i]){ cnt2++; dfs(i,0);}
	if (check()) puts("Yes");
	else puts("No");
	return 0;
}