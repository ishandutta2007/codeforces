/*********************************************************************
 * Source
 * Problem
 * Author
 * Date
*********************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=110000;
const int MAXS=505;
const int S=500;
int n,Q,fa[MAXN],cnt,dfn[MAXN],t[MAXN],col[MAXN],tag[MAXS],ans;
int L[MAXN],R[MAXN],bel[MAXN],v[MAXN],tot[MAXS][MAXN];
int sz[MAXN],son[MAXN],dep[MAXN],top[MAXN];
int edgenum=1,vet[MAXN],Next[MAXN],Head[MAXN];
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
	sz[u]=1; son[u]=0; fa[u]=f;
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=f){
			dep[vet[e]]=dep[u]+1;
			dfs(vet[e],u);
			sz[u]+=sz[vet[e]];
			if (sz[vet[e]]>sz[son[u]]) son[u]=vet[e];
		}
}
void dfs2(int u,int t){
	top[u]=t; dfn[u]=++cnt;
	if (!son[u]) return;
	dfs2(son[u],t);
	for (int e=Head[u];e;e=Next[e])
		if (vet[e]!=fa[u]&&vet[e]!=son[u]) dfs2(vet[e],vet[e]);
}
void change(int x,int y){
	col[x]^=1;
	if (v[x]+tag[bel[x]]>=n+1) ans-=y;
	tot[bel[x]][v[x]]-=y;
}
void change2(int l,int r,int k){
	int f=bel[l],t=tag[f];
	for (int i=l;i<=r;i++){
		if (!col[i]&&v[i]+t>=n+1) ans--;
		if (!col[i]) tot[f][v[i]]--;
		v[i]+=k;
		if (!col[i]) tot[f][v[i]]++;
		if (!col[i]&&v[i]+t>=n+1) ans++;
	}
}
void change(int l,int r,int k){
	int a=bel[l],b=bel[r];
	if (a==b){ change2(l,r,k); return;}
	change2(l,R[a],k); change2(L[b],r,k);
	for (int i=a+1;i<=b-1;i++)
		if (k==1) tag[i]++,ans+=tot[i][n+1-tag[i]];
		else ans-=tot[i][n+1-tag[i]],tag[i]--;
}
int main(){
	n=read(); Q=read();
	for (int i=2;i<=n;i++){
		fa[i]=read();
		addedge(fa[i],i);
	}
	for (int i=1;i<=n;i++) t[i]=read();
	dfs(1,0); dfs2(1,1);
	for (int i=1;i<=n;i++){
		bel[i]=(i-1)/S+1;
		if (!L[bel[i]]) L[bel[i]]=i;
		R[bel[i]]=i;
	}
	for (int i=1;i<=n;i++) v[dfn[i]]=n-t[i];
	for (int i=1;i<=n;i++) tot[bel[i]][v[i]]++;
	int x,op;
	while (Q--){
		x=read(); op=1;
		if (x<0) x=-x,op=-1;
		//W->B  1
		//B->W -1
		change(dfn[x],op);
		while (x){
			change(dfn[top[x]],dfn[x],op);
			x=fa[top[x]];
		}
		printf("%d ",ans);
	}
	return 0;
}