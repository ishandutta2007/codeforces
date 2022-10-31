//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 2e5+7;
vector<pair<int,int> > G[N];
pair<int,int> E[N];
vector<int> taken;
bool vis[N],et[N];
bool Check(pair<int,int> a,pair<int,int> b,pair<int,int> c){
	vector<pair<int,int> > V = {a,b,c};
	for(auto &to:V){
		if (to.first>to.second){
			swap(to.first,to.second);
		}
	}
	sort(V.begin(),V.end());
	if (V[0].first==V[1].first && V[0].second==V[2].first && V[1].second==V[2].second){
		return 1;
	}
	return 0;
}
void dfs(int v,int par,int ei){
	vis[v] = 1;
	for(auto [to,ind]:G[v]){
		if (to==par){
			continue;
		}
		if (vis[to] && !et[ind]){
			if (taken.size()<2){
				taken.push_back(ind);
				et[ind] = 1;
			}
			else if (Check(E[taken[0]],E[taken[1]],E[ind])){
				et[ei] = 1;
				taken.push_back(ei);
			}
			else{
				taken.push_back(ind);
				et[ind] = 1;
			}
		}
		else if (!vis[to]){
			dfs(to,v,ind);
		}
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i+=1){
		int u,v;
		cin>>u>>v;
		E[i] = {u,v};
		G[u].push_back({v,i});
		G[v].push_back({u,i});
	}
	dfs(1,1,-1);
	for(int i = 1;i<=m;i+=1){
		cout<<et[i];
		et[i] = 0;
	}
	cout<<endl;
	for(int i = 1;i<=n;i+=1){
		vis[i] = 0;
		G[i].clear();
	}
	taken.clear();
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}