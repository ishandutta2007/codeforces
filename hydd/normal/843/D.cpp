#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int bufsize=1<<20;
const ll INF=0x3f3f3f3f3f3f3f3f;
typedef pair<ll,int> pii;
int n,m,Q; ll dis[210000],f[210000]; bool vis[210000];
int edgenum,vet[410000],val[410000],Next[410000],Head[210000];
priority_queue<pii> que;
queue<int> q[210000];
void addedge(int u,int v,int cost){
	vet[++edgenum]=v; val[edgenum]=cost;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
char Getchar(){
	static char now[bufsize],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,bufsize,stdin);
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
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0; que.push(pii(0,1));
	int u,v,c;
	while (!que.empty()){
		u=que.top().second;
		que.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (int e=Head[u];e;e=Next[e]){
			v=vet[e]; c=val[e];
			if (dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				que.push(pii(-dis[v],v));
			}
		}
	}
}
void update(int k){
	memset(f,0x3f,sizeof(f));
	f[1]=0; q[0].push(1);
	int u,v; ll c;
	for (int i=0;i<=k;i++)
		while (!q[i].empty()){
			u=q[i].front(); q[i].pop();
			if (f[u]<i) continue;
			for (int e=Head[u];e;e=Next[e]){
				v=vet[e]; c=dis[u]+val[e]-dis[v];
				if (f[v]>f[u]+c){
					f[v]=f[u]+c;
					if (f[v]<=k) q[f[v]].push(v);
				}
			}
		}
	for (int i=1;i<=n;i++) dis[i]=min(dis[i]+f[i],INF);
}
int main(){
	n=read(); m=read(); Q=read();
	int u,v,c;
	for (int i=1;i<=m;i++){
		u=read(); v=read(); c=read();
		addedge(u,v,c);
	}
	dijkstra(); int op,k;
	while (Q--){
		op=read(); k=read();
		if (op==1) printf("%lld\n",dis[k]==INF?-1:dis[k]);
		else{
			for (int i=1;i<=k;i++) val[read()]++;
			update(min(k,n-1));
		}
	}
	return 0;
}