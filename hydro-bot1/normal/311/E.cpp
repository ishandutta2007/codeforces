// Hydro submission #61ee60c84ecae2351cfc45b1@1643336066365
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = 2147483647,N = 1e5 + 10 + 2e4;
int tot = 1,S,T,h[N],q[N],dep[N],cur[N],a[N],n,m,G;

// S man,T woman
struct edge{
	int to,nxt,z;
}e[N << 2];
void add(int x,int y,int z)
{
	e[++tot] = (edge){y,h[x],z},h[x] = tot;
	e[++tot] = (edge){x,h[y],0},h[y] = tot;
}
int bfs()
{
	for (int i = 0; i <= n + m + 2; i++) cur[i] = h[i];
	memset(dep,0,sizeof dep);
	int head = 0,tail = 0;
	q[++tail] = S,dep[S] = 1;
	while (head < tail)
	{
		int u = q[++head];
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].to;
			if (dep[v] || e[i].z <= 0) continue;
			dep[v] = dep[u] + 1,q[++tail] = v;
		}
	}
	if (dep[T]) return 1;
	return 0;
}
int dinic(int u,int mn,int fa)
{
	if (u == T || mn == 0) return mn;
	int sum = 0,flow = 0;
	for (int i = cur[u]; i; i = e[i].nxt)
	{
		int v = e[i].to; cur[u] = i;
		if (v == fa || dep[v] != dep[u] + 1 || e[i].z <= 0) continue;
		sum = dinic(v,min(mn,e[i].z),u);
		if (sum <= 0) continue;
		flow += sum,mn -= sum,e[i].z -= sum,e[i ^ 1].z += sum;
		if (mn <= 0) break;
	}
	return flow;
}
int main()
{
	scanf("%d%d%d",&n,&m,&G);
	S = n + m + 1,T = n + m + 2;
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for (int i = 1,q; i <= n; i++)
	{
		scanf("%d",&q);
		if (a[i]) add(S,i,q); else add(i,T,q);
	}
	int ans = 0;
	for (int i = 1,q,p,c,k; i <= m; i++)
	{
		scanf("%d%d%d",&q,&p,&k),ans += p;
		for (int j = 1,tt; j <= k; j++)
		{
			scanf("%d",&tt);
			if (q) add(i + n,tt,inf);
			else add(tt,i + n,inf);
		}
		scanf("%d",&c);
		if (c) p += G;
		if (q) add(S,i + n,p);
		else add(i + n,T,p);
	}
	while (bfs())
		ans -= dinic(S,inf,S);
	printf("%d\n",ans);
}