#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=400010;
int T=1,opt;
int n,m;
int t1,t2,t3;
int fa[maxn];
int getfa(int x){
	if (x==fa[x]) return x;
	else{
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
}
vector <int> a[maxn];
void edge(int x,int y){
	a[x].push_back(y);
	a[y].push_back(x);
}
int b[maxn];
int l[maxn],r[maxn],th;
int xx[maxn],yy[maxn];
int faa[maxn][22],depth[maxn];
void dfs1(int x,int fa){
	faa[x][0]=fa;
	depth[x]=depth[fa]+1;
	for (int i=1;i<=20;i++) faa[x][i]=faa[faa[x][i-1]][i-1];
	th++; l[x]=th;
	for (int i=0;i<a[x].size();i++){
		if (a[x][i]!=fa) dfs1(a[x][i],x);
	}
	r[x]=th;
}
int lca(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (depth[faa[x][i]]>=depth[y]) x=faa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--){
		if (faa[x][i]!=faa[y][i]){
			x=faa[x][i];
			y=faa[y][i];
		}
	}
	return faa[x][0];
}
int lcaa(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (depth[faa[x][i]]>depth[y]) x=faa[x][i];
	return x;
}
int d[maxn],dd[maxn];
void getlr(int l,int r){
	d[l]++; d[r+1]--;
}
int x,y,t;
int main(){
	
	n=read(); m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		x=read(); y=read();
		if (getfa(x)!=getfa(y)){
			t1=getfa(x);
			t2=getfa(y);
			fa[t1]=t2;
			edge(x,y);
		}
		else{
			xx[i]=x; yy[i]=y;
		}
	}
		
		t=0;
		dfs1(1,0);
		for (int i=0;i<=n+1;i++) d[i]=0;
		for (int i=1;i<=m;i++){
			if (xx[i]){
				t++;
				if (depth[xx[i]]>depth[yy[i]]) swap(xx[i],yy[i]);
				x=xx[i]; y=yy[i];
				if (lca(x,y)==x){
					x=lcaa(x,y);
					getlr(1,l[x]-1);
					getlr(r[x]+1,n);
					getlr(l[y],r[y]);
				}
				else{
					getlr(l[x],r[x]);
					getlr(l[y],r[y]);
				}
			}
		}
		for (int i=1;i<=n;i++){
			d[i]=d[i-1]+d[i];
		}
		for (int i=1;i<=n;i++) dd[i]=d[l[i]];
		for (int i=1;i<=n;i++)
			if (dd[i]==t) printf("1"); else printf("0");
		printf("\n");

	return 0;
}