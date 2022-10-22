/*********************************************************************
 * Sourceysy
 * ProblemCF793G
 * Authorhydd
 * Date2020/9/4
 * EncodingSimplified Chinese (GB2312)
*********************************************************************/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,q,s,t,rt[10005];
int cnt,ls[2000005],rs[2000005],tag[2000005];
vector<pii> vec[10005];
int cur[1000005],edgenum,vet[2000005],val[2000005],Next[2000005],Head[1000005];
void addedge(int u,int v,int cost){
    vet[++edgenum]=v; val[edgenum]=cost;
    Next[edgenum]=Head[u]; Head[u]=edgenum;
}
void Add(int u,int v,int f){
	addedge(u,v,f);
	addedge(v,u,0);
}
int head,tail,que[1100000];
int dis[1100000];
bool bfs(){
	memset(dis,-1,(cnt+1)<<2);
	head=1; tail=1; dis[que[1]=t]=0;
	int u,v;
	while (head<=tail){
		u=que[head++];
		for (int e=Head[u];e;e=Next[e]){
			v=vet[e];
			if (val[e^1]&&dis[v]==-1){
				que[++tail]=v;
				dis[v]=dis[u]+1;
			}
		}
	}
	return ~dis[s];
}
int dfs(int u,int flow){
	if (u==t) return flow;
	int used=0,tmp;
	for (int &e=cur[u];e;e=Next[e])
		if (val[e]&&dis[u]==dis[vet[e]]+1){
			tmp=dfs(vet[e],min(val[e],flow-used));
			val[e]-=tmp; val[e^1]+=tmp; used+=tmp;						
			if (used==flow) return flow;
		}
	return used;
}
int maxflow(){
	int flow=0;
	while (bfs()){
		memcpy(cur,Head,(cnt+1)<<2);
		flow+=dfs(s,INF);
	}
	return flow;
}
void update(int now){
	if (!tag[ls[now]]) Add(now,ls[now],INF);
	if (!tag[rs[now]]) Add(now,rs[now],INF);
}
void build(int &now,int l,int r){
	if (l==r){ now=l; return;}
	now=++cnt;
	int mid=(l+r)>>1;
	build(ls[now],l,mid); build(rs[now],mid+1,r);
	update(now);
}
void change(int &now,int l,int r,int x,int y){
	if (l==r){ tag[now]^=1; return;}
	cnt++; tag[cnt]=tag[now]; ls[cnt]=ls[now]; rs[cnt]=rs[now]; now=cnt;
	if (x<=l&&r<=y){ tag[now]^=1; update(now); return;}
	int mid=(l+r)>>1;
	if (x<=mid) change(ls[now],l,mid,x,y);
	if (y>mid) change(rs[now],mid+1,r,x,y);
	update(now);
}
int main(){
	edgenum=1; memset(Head,0,sizeof(Head));
	scanf("%d%d",&n,&q);
	int x1,y1,x2,y2;
	for (int i=1;i<=q;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//		x1=i; x2=i; y1=i; y2=10000;
		vec[x1].push_back(pii(y1,y2));
		vec[x2+1].push_back(pii(y1,y2));
	}
	s=0; t=2*n+1; cnt=2*n+1;
	for (int i=1;i<=n;i++) Add(i,t,1);
	for (int i=1;i<=n;i++) Add(s,n+i,1);
	build(rt[0],1,n);
	for (int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		for (pii x:vec[i]) change(rt[i],1,n,x.first,x.second);
		if (!tag[rt[i]]) Add(n+i,rt[i],1);
	}
	printf("%d\n",maxflow());
	return 0;
}