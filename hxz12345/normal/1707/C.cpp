#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
struct Node{
	int x,y;
} edge[1001010];
int De,now,j,H[1001010],w,u,v,Z,pre[1001010],n,m,i,x,y,id,dep[1001010],siz[1001010],lg[1001010],cnt,dfn[1001010],f[1001010],a[1001010],b[1001010],d[1001010],F[1001010][22],r1,r2;
int find(int x){
	if (f[x]==x) return f[x];
	f[x]=find(f[x]);return f[x];
}
void add(int x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa){
	dfn[x]=++id;
	F[x][0]=fa;dep[x]=dep[fa]+1;
	for (int i=1;i<=20;i++) F[x][i]=F[F[x][i-1]][i-1];
	siz[x]=1;
	for (int i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	     	sc(a[i],x),siz[x]+=siz[a[i]];
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y])
		x = F[x][lg[dep[x]-dep[y]] - 1];
	if(x == y) return x;
	for(int k = lg[dep[x]] - 1; k >= 0; --k)
		if(F[x][k] != F[y][k])
			x = F[x][k], y = F[y][k];
	return F[x][0];
}
int main()
{
	n=read();m=read();
	for (i=1;i<=n;i++) lg[i]=lg[i/2]+1;
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++){
		x=read();y=read();
		r1=find(x);r2=find(y);
		if (r1!=r2) f[r1]=r2,add(x,y),add(y,x);
		else edge[++w].x=x,edge[w].y=y;
	}
	sc(1,0);
	for (i=1;i<=w;i++)
	    { 
	       u=edge[i].x;v=edge[i].y;
	       Z=LCA(u,v);
	       if ((u!=Z)&&(v!=Z)) pre[dfn[u]]++,pre[dfn[u]+siz[u]]--,pre[dfn[v]]++,pre[dfn[v]+siz[v]]--;
	       else {
	       	if (v==Z) swap(u,v);
	       	pre[1]++;pre[dfn[v]]++;pre[dfn[v]+siz[v]]--;
	       	now=v;De=dep[v]-dep[u]-1;
	       	for (j=20;j>=0;j--)
	       	     if (De>=(1<<j)) now=F[now][j],De-=(1<<j);
	       	pre[dfn[now]]--;pre[dfn[now]+siz[now]]++;
		   }
		}
for (i=1;i<=n;i++) pre[i]=pre[i-1]+pre[i];
for (i=1;i<=n;i++) H[dfn[i]]=i;
for (i=1;i<=n;i++)
     if (pre[dfn[i]]==w) printf("1");
     else printf("0");
return 0;
}