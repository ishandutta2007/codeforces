/*********************************************************************
 * SourceHLSC
 * ProblemCF545E
 * Authorhydd
 * Date2020/10/29
*********************************************************************/
#include<cstdio>
#include<queue>
//#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
typedef long long ll;
const ll INF=1ll<<60;
int n,m,s,lst[310000],num[310000]; ll dis[310000]; bool vis[310000];
int edgenum=1,vet[610000],val[610000],Next[610000],Head[310000];
queue<int> q;
void addedge(int u,int v,int cost){
	vet[++edgenum]=v; val[edgenum]=cost;
	Next[edgenum]=Head[u]; Head[u]=edgenum;
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
void spfa(int s){
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[s]=0; vis[s]=true; q.push(s);
	int u,v,c;
	while (!q.empty()){
		u=q.front(); q.pop();
		vis[u]=false;
		for (int e=Head[u];e;e=Next[e]){
			v=vet[e]; c=val[e];
			if (dis[u]+c<dis[v]||(dis[u]+c==dis[v]&&c<num[v])){
				dis[v]=dis[u]+c;
				lst[v]=e>>1; num[v]=c;
				if (!vis[v]){ vis[v]=true; q.push(v);}
			}
		}
	}
}
int main(){
	n=read(); m=read();
	int u,v,c;
	for (int i=1;i<=m;i++){
		u=read(); v=read(); c=read();
		addedge(u,v,c); addedge(v,u,c);
	}
	s=read(); spfa(s);
	ll ans=0;
	for (int i=1;i<=n;i++)
		if (lst[i]) ans+=num[i];
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
		if (lst[i]) printf("%d ",lst[i]);
	return 0;
}