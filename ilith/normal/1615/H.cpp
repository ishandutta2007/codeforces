#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
using namespace std;
const int N=1010,M=6010,inf=1e8;
int n,m,y[N],u,v,s,t,f[N],Q[N];
vector<int>a[N],g;
int hd[N],tot,nxt[M],to[M],cr[N];
int q[N],l,r,d[N],ky[N],w[M],k;
void link(int u,int v,int c){to[++tot]=v,w[tot]=c,nxt[tot]=hd[u],hd[u]=tot;}
int bfs(vector<int>g){
	for(rgi x:g)cr[x]=hd[x],d[x]=0;
	cr[s]=hd[s],q[d[s]=l=r=1]=s,d[t]=0;
	while(r>=l)for(int i=hd[k=q[l++]];i;i=nxt[i]){
		if(w[i]&&!d[to[i]])d[q[++r]=to[i]]=d[k]+1;
	}
	return d[t];
}
int dfs(int x,int f){
	if(x==t)return f;
	int res=f;
	for(int i=cr[x];i&&f;i=nxt[i]){
		if(w[cr[x]=i]&&d[v=to[i]]==d[x]+1)f-=k=dfs(v,min(f,w[i])),w[i]-=k,w[i^1]+=k;
	}
	return f==res?d[x]=0:res-f;
}
void solve(int l,int r,vector<int>g){
	if(!g.size()||l>r)return;
	if(l==r){
		for(rgi x:g)f[x]=l;
		return;
	}
	int mid=(l+r)>>1;
	vector<int>L[2];
	tot=1,hd[s]=hd[t]=0;
	for(rgi x:g)ky[x]=1,hd[x]=0;
	for(rgi x:g){
		if(mid<y[x])link(x,s,0),link(s,x,1);
		else link(x,t,1),link(t,x,0);
	}
	for(rgi x:g)for(rgi to:a[x]){
		if(ky[to])link(x,to,inf),link(to,x,0);
	}
	while(bfs(g))dfs(s,inf);
	bfs(g);
	for(rgi x:g)L[!d[x]].pbk(x),ky[x]=0;
	solve(l,mid,L[1]),solve(mid+1,r,L[0]);
}
signed main(){
	scanf("%d%d",&n,&m),s=n+1,t=n+2;
	FOR(i,1,n)scanf("%d",y+i),g.pbk(i);
	while(m--)scanf("%d%d",&u,&v),a[u].pbk(v);
	solve(1,1e9,g);
	FOR(i,1,n)printf("%d ",f[i]);
	return 0;
}