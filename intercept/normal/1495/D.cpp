#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=609;
int n,m;
int val[M],dis[M][M];
vector<int>g[M];
void bfs(int s,int t){
	queue<int>q;
	q.push(s);
	for(int i=1;i<=n;++i)val[i]=0;
	val[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[s][v]==dis[s][u]+1&&dis[t][v]==dis[t][u]+1){
				if(!val[v])q.push(v);
				val[v]++;
			}
			if(dis[s][v]==dis[s][u]+1&&dis[t][v]==dis[t][u]-1&&dis[s][v]+dis[v][t]==dis[s][t]){
				if(!val[v])val[v]=1,q.push(v);
				else {val[v]=-1e9;break;}
			}
		}
	}
	int ans=1;
	for(int i=1;i<=n;++i){
		if(val[i]<0)ans=0;
		else ans=1ll*val[i]*ans%mod;
	}
	printf("%d ",ans);
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=1e9;
		}
	}
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)bfs(i,j);
		printf("\n");
	}
	return 0;
}