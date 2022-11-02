#include <stdio.h>
#include <algorithm>
#define MAXN 5050

class Soldier {
	public:
		int id,p;
		const bool operator<(const Soldier &b) const { return p<b.p; }
};

int n;
int newid[MAXN];
Soldier sd[MAXN];

int deg[MAXN]={0},adj[MAXN][MAXN];
int cap[MAXN][MAXN],res[MAXN];
int pred[MAXN];

int pos[MAXN];
int fin[MAXN],sol[MAXN];

void dfs(int v,int p) {
	int i,u;
	pred[v]=p;
	for(i=0;i<deg[v];i++) {
		u=adj[v][i];
		if(u!=p) dfs(u,v);
	}
}

inline void solve() {
	int i,v,t;
	int rem=n;
	for(i=0;i<n;i++) {
		if(pos[i]==1) {
			fin[i]=0;
			rem--;
		}
		//printf("<%d %d>\n",i,pos[i]);
	}
	t=1;
	while(rem) {
		for(i=1;i<=n;i++)
			res[i]=cap[i][pred[i]];
		for(i=0;i<n;i++) {
			v=pos[i];
			if(v==1) continue;
			if(res[v]==0) continue;
			res[v]--;
			pos[i]=pred[v];
			if(pred[v]==1) {
				fin[i]=t;
				rem--;
			}
		}
		t++;
	}
	for(i=1;i<=n;i++)
		sol[i]=fin[newid[i]];
	for(i=1;i<=n;i++)
		printf("%d%c",sol[i],i<n?' ':'\n');
}

int main(void)
{
	int i,v,u,c;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		sd[i].id=i+1;
		scanf("%d",&sd[i].p);
	}
	std::sort(sd,sd+n);
	for(i=0;i<n;i++) {
		newid[sd[i].id]=i;
		pos[i]=sd[i].id;
	}
	for(i=0;i<n-1;i++) {
		scanf("%d %d %d",&v,&u,&c);
		adj[v][deg[v]++]=u;
		adj[u][deg[u]++]=v;
		cap[v][u]=cap[u][v]=c;
	}
	dfs(1,0);
	solve();
}