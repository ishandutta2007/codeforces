/*********************************************************************
 * Sourceysy
 * ProblemCF808F
 * Authorhydd
 * Date2020/9/2
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<cstring>
#include<queue>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int INF=0x3f3f3f3f;
const int lim=2333333;
int n,k,s,t,maxflow,ans,p[110],c[110],l[110];
int vis[110];// 
int dep[110]; bool np[210000]; int prime[210000];
int edgenum,F[51000],V[51000],Next[51000],Head[110];
//f:floww: 
void addedge(int u,int v,int f){
	V[++edgenum]=v; F[edgenum]=f;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
void Add(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
bool bfs(){
	memset(vis,false,sizeof(vis));
	memset(dep,0x3f,sizeof(dep));
	dep[s]=0;
	vis[s]=true;
	queue<int> que;
	que.push(s);
	while (!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			int d=V[e];
			if (dep[d]>dep[u]+1&&F[e]){
				dep[d]=dep[u]+1;
				if (!vis[d]){
					que.push(d);
					vis[d]=true;
				}
			}
		}
	}
	return dep[t]<INF;
}
int dfs(int u,int flow){
	if (u==t){ 
		vis[t]=true; maxflow+=flow;
		return flow;
	}
	int used=0;
	vis[u]=true;
	for (int e=Head[u];e;e=Next[e]){
		int d=V[e];
		if ((!vis[d]||d==t)&&F[e]&&dep[d]==dep[u]+1){
			int minflow=dfs(d,min(flow-used,F[e]));
			if (minflow!=0) F[e]-=minflow,F[e^1]+=minflow,used+=minflow;
			if (used==flow) break;
		}
	}
	return used;
}
int dinic(){
	maxflow=0;
	while (bfs()){
		vis[t]=1;
		while (vis[t]){
			memset(vis,false,sizeof(vis));
			dfs(s,INF); 
		}
	}
	return maxflow;
}
int cnt,num[110];
bool check(int mid){
	edgenum=1; memset(Head,0,sizeof(Head));
	s=0; t=n+1;
	int pos=0;
	for (int i=1;i<=n;i++)
		if ((c[i]==1&&p[i]>p[pos])&&(l[i]<=mid)) pos=i;
	cnt=0; int sum=0;
	for (int i=1;i<=n;i++)
		if ((c[i]!=1||i==pos)&&(l[i]<=mid)){
			num[++cnt]=i;
			if (c[i]&1) Add(s,cnt,p[i]);
			else Add(cnt,t,p[i]);
			sum+=p[i];
		}
	for (int i=1;i<=cnt;i++) if (c[num[i]]&1)
		for (int j=1;j<=cnt;j++) if (!(c[num[j]]&1))
			if (!np[c[num[i]]+c[num[j]]]) Add(i,j,INF);
	return sum-dinic()>=k;
}
void init(int n){
	int cnt=0;
	for (int i=2;i<=n;i++){
		if (!np[i]) prime[++cnt]=i;
		for (int j=1;j<=cnt&&i*prime[j]<=n;j++){
			np[i*prime[j]]=true;
			if (i%prime[j]==0) break;
		}
	}
}
int main(){
	init(200000);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&p[i],&c[i],&l[i]);
	int l=1,r=n+1,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	if (r==n+1) puts("-1");
	else printf("%d\n",r);
	return 0;
}