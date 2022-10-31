#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 507;
const int INF = 1e9+7;
struct edge{
	int u,v,w;
} E[N*N];
int dist[N][N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i+=1){
		for(int j = 1;j<=n;j+=1){
			dist[i][j] = INF;
		}
	}
	for(int i = 1;i<=m;i+=1){
		cin>>E[i].u>>E[i].v>>E[i].w;
		dist[E[i].u][E[i].v] = dist[E[i].v][E[i].u] = 1;
	}
	for(int i = 1;i<=n;i+=1){
		dist[i][i] = 0;
	}
	for(int k = 1;k<=n;k+=1){
		for(int i = 1;i<=n;i+=1){
			for(int j = 1;j<=n;j+=1){
				dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	ll res = ll(INF)*INF;
	for(int i = 1;i<=m;i+=1){
		res = min(res,
	ll(min(dist[E[i].u][1]+dist[E[i].v][n],dist[E[i].v][1]+dist[E[i].u][n])+dist[E[i].u][E[i].v])*E[i].w);
		for(int to:{E[i].u,E[i].v}){
			int oth = E[i].u+E[i].v-to;
			for(int v = 1;v<=n;v+=1){
				res = min(res,ll(dist[v][to]+dist[v][1]+dist[v][n]+2)*E[i].w);
			}
		}
	}
	for(int i = 1;i<=n;i+=1){
		for(int j = 1;j<=n;j+=1){
			dist[i][j] = INF;
		}
	}/*
	for(int i = 1;i<=m;i+=1){
		dist[E[i].u][E[i].v] = dist[E[i].v][E[i].u] = min(dist[E[i].u][E[i].v],E[i].w);
	}
	for(int i = 1;i<=n;i+=1){
		dist[i][i] = 0;
	}
	for(int k = 1;k<=n;k+=1){
		for(int i = 1;i<=n;i+=1){
			for(int j = 1;j<=n;j+=1){
				dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	res = min(res,ll(dist[1][n]));
	*/
	cout<<res<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}