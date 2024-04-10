#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int st,ed;
vector<int>g[200002];
int vis[200002];
queue<int>q;
void bfs(int now,int val){
	q.push(now);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<g[t].size();i++){
			if(g[t][i]!=st&&g[t][i]!=ed&&vis[g[t][i]]<val){
				vis[g[t][i]]+=val;
				q.push(g[t][i]);
			}
		}
			
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>st>>ed;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bfs(st,1);
		bfs(ed,2);
		long long cnt1=0;
		long long cnt2=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				cnt1++;
			}
			if(vis[i]==2){
				cnt2++;
			}
		}
		cout<<cnt1*cnt2<<'\n';
	}
	return 0;
}