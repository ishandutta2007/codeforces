#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=440;
int g[N][N];
int want=1;
int vis[N],dist[N];
int n,m;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u][v]=1;
		g[v][u]=1;
	}
	if(g[0][n-1]==1)want=0;
	queue<int>q;q.push(0);vis[0]=true;
	while(q.size()){
		int u=q.front();q.pop();
		if(u==n-1){
			cout<<dist[u]<<endl;return 0;
		}
		for(int i=0;i<n;++i)
			if(!vis[i]&&g[u][i]==want){
				vis[i]=true;
				dist[i]=dist[u]+1;
				q.push(i);
			}
	}
	cout<<-1<<endl;
}