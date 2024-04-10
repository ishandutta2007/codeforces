#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
using namespace std;
int n,m;
const ll INF=1ll<<50;
const int N=20009;
const int M=100009;
int L[M],R[M];
struct P{int to,ne;ll flow,cap;}e[M];
struct Dinic{
	int head[N],dis[N],cur[N];
	int s,t,num=1;
	queue<int>q;
	bool vis[N];
	bool bfs(){
		memset(vis,0,sizeof(vis));
		q.push(t);dis[t]=0;vis[t]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=head[u];i;i=e[i].ne){
				int v=e[i].to;
				if(!vis[v]&&e[i^1].cap>e[i^1].flow){
					dis[v]=dis[u]+1;
					q.push(v),vis[v]=1;
				}
			}
		}
		return vis[s];
	}
	ll dfs(int u,ll a){
		if(u==t||a==0)return a;
		ll flow=0,f;
		for(int&i=cur[u];i;i=e[i].ne){
			int v=e[i].to;
			if(dis[v]==dis[u]-1){
				f=dfs(v,min(a,e[i].cap-e[i].flow));
				e[i].flow+=f; e[i^1].flow-=f;
				a-=f;         flow+=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	void add(int u,int v,ll w){
		e[++num]=(P){v,head[u],0,w};head[u]=num;
		e[++num]=(P){u,head[v],0,0};head[v]=num;
	}
	ll maxflow(){
		ll ans=0;
		while(bfs()){
			memcpy(cur,head,sizeof(head));
			ans+=dfs(s,INF);
		}
		return ans;
	}
}d;
int s[M],a[M],x[M],y[M];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		a[x[i]]++;
		a[y[i]]++;
	}
	d.s=n+m+1,d.t=n+m+2;
	int t=0;
	for(int i=1;i<=n;++i){
		if(s[i]&&(a[i]%2||a[i]<0)){
			puts("No");
			return 0;
		}
		else if(s[i]) {
			d.add(i,d.t,a[i]/2);
			t+=a[i]/2;
		}
	}
	int sum=0,ans=0;
	for(int i=1;i<=m;++i){
		if(s[x[i]]&&s[y[i]]){
			sum++;
			d.add(d.s,n+i,1);
			L[i]=d.num+1;
			d.add(n+i,x[i],1);
			R[i]=d.num+1;
			d.add(n+i,y[i],1);
		}
	}
	ans=d.maxflow();
	if(ans!=sum){
		puts("No");
		return 0;
	}
	for(int i=1;i<=m;++i){
		if(s[x[i]]*s[y[i]]==0&&s[x[i]]+s[y[i]]==1){
			if(s[x[i]])L[i]=d.num+1,d.add(d.s,x[i],1);
			else R[i]=d.num+1,d.add(d.s,y[i],1);
		}
	}
	ans+=d.maxflow();
	if(ans!=t){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=m;++i){
		if(s[x[i]]&&s[y[i]]){
			if(e[L[i]].flow)cout<<y[i]<<" "<<x[i]<<"\n";
			else cout<<x[i]<<" "<<y[i]<<"\n";
		}
		else if(s[x[i]]||s[y[i]]){
			if(s[x[i]]){
				if(e[L[i]].flow)cout<<y[i]<<" "<<x[i]<<"\n";
				else cout<<x[i]<<" "<<y[i]<<"\n";
			}
			else{
				if(e[R[i]].flow)cout<<x[i]<<" "<<y[i]<<"\n";
				else cout<<y[i]<<" "<<x[i]<<"\n";
			}
		}
		else cout<<x[i]<<" "<<y[i]<<"\n";
	}
	return 0;
}