#include <bits/stdc++.h>

using namespace std;

bool flip[100001];

vector<vector<int>> adj;
vector<int> flips;

void bfs(int x, int p, int c, int d) {
	if((c-flip[x])%2) {
		flips.push_back(x);
		c++;
	}
	for(int i = 0; i < adj[x].size(); i++) {
		if(adj[x][i] == p) continue;
		bfs(adj[x][i], x, d, c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	adj.resize(n);
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		flip[i] ^= x;
	}
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		flip[i] ^= x;
	}
	bfs(0, -1, 0, 0);
	cout << flips.size() << '\n';
	for(int i = 0; i < flips.size(); i++) cout << flips[i]+1 << '\n';
}