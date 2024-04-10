#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x){
	string s = to_string(x);
	return s.size();
}
const int mod = (int)1e9+7;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>adj(2000005);
	int cur = n+1;
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		if(true){
			int a = f(x);
			int b = f(y);
			string s = to_string(i+1);
			int pre = x;
			for(int j = 1; j<=s.size(); j++){
				if(j<s.size()){
					adj[pre].push_back({s[j-1]-'0',cur});
					pre = cur;
					cur++;
				}
				else{
					adj[pre].push_back({s[j-1]-'0',y});
				}
			}
		}
		if(true){
			swap(x,y);
			int a = f(x);
			int b = f(y);
			string s = to_string(i+1);
			int pre = x;
			for(int j = 1; j<=s.size(); j++){
				if(j<s.size()){
					adj[pre].push_back({s[j-1]-'0',cur});
					pre = cur;
					cur++;
				}
				else{
					adj[pre].push_back({s[j-1]-'0',y});
				}
			}
		}
	}
	for(int i = 1; i<=2000000; i++){
		sort(adj[i].begin(),adj[i].end());
	}
	queue<vector<int>>q;
	vector<bool>vis(2000005);
	vector<int>dis(2000005);
	vis[1] = true;
	if(true){
		vector<int>ret;
		ret.push_back(1);
		q.push(ret);
	}
	while(q.size()){
		vector<int>cur = q.front(); q.pop();
		vector<vector<int>>a(10);
		for(int nxt: cur){
			for(pair<int,int>p: adj[nxt]){
				a[p.first].push_back(p.second);
			}
		}
		for(int i = 0; i<10; i++){
			int j = i;
			vector<int>pp;
			for(int nxt: a[j]){
				if(vis[nxt])continue;
				vis[nxt] = true;
				pp.push_back(nxt);
				dis[nxt] = (dis[cur[0]]*10+j)%mod;
			}
			if(pp.size())q.push(pp);
		}
	}
	for(int i = 2; i<=n; i++){
		cout << dis[i] << "\n";
	}
	return 0;
}