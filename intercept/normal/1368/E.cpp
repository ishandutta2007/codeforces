#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m;
int d[M],vis[M],p[M];
vector<int>g[M];
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)d[i]=0,vis[i]=p[i]=0,g[i].clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		d[v]++;
	}
	queue<int>q;
	vector<int>ans;
	for(int i=1;i<=n;++i){
		if(d[i]){
			for(auto v:g[i]){
				p[v]++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(p[i]==0&&d[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(!vis[v]){
				vis[v]=1;
				ans.eb(v);
				for(auto w:g[v]){
					d[w]--;
					p[w]--;
					if(p[w]==0&&d[w])q.push(w);
					if(d[w]==0){
						for(auto o:g[w]){
							p[o]--;
							if(p[o]==0&&d[o])q.push(o);
						}
					}
				}
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto o:ans){
		cout<<o<<" ";
	}
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
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