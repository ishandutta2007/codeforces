#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
int d[M],vis[M];
vector<pii>g[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>d[i];
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v,i);
		g[v].eb(u,i);
		d[u]--;
		d[v]--;
	}
	queue<int>q;
	for(int i=1;i<=n;++i){
		if(d[i]>=0)q.push(i);
	}
	vector<int>ans;
	int num=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=1;
		num++;
		for(auto o:g[u]){
			int v=o.fi,w=o.se;
			if(!vis[v])ans.eb(w);
			d[v]++;
			if(d[v]==0)q.push(v);
		}
	}
	if(num<n)cout<<"DEAD\n";
	else{
		cout<<"ALIVE\n";
		reverse(ans.begin(),ans.end());
		for(auto o:ans)cout<<o<<" ";
		cout<<"\n";
	}
	return 0;
}
/*
1
5 7

2 3

4 5

2 4

1 4

1 2

3 5

3 4


*/