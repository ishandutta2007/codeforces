#include <bits/stdc++.h>

using namespace std;

bool vis[200001];
vector<int> adj[200001];
const long long int MOD = 998244353;

long long int fact(long long int n) {
	long long int r = 1;
	for(long long int a=1; a<=n; a++) {
		r*=a;
		r%=MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long int ans=(long long int)(n), curr=1, kay=0;
	for(int a=1; a<n; a++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> bfs;
	bfs.push(1);
	while(bfs.size()) {
		int v = bfs.front(); bfs.pop();
		vis[v]=true;
		curr--;
		for(int a=0; a<adj[v].size(); a++) {
			if(!vis[adj[v][a]]) {
				kay++;
				vis[adj[v][a]] = true;
				bfs.push(adj[v][a]);
			}
		}
		ans*=fact(kay);
		ans%=MOD;
		kay=1;
		if(curr==0) {
			curr=bfs.size();
		}
	}
	cout << ans << '\n';
	return 0;
}