#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200001];
bool visited[200001];
int inc[200001];

int happy(int x, int l) {
	visited[x] = true;
	int children = 1;
	for(int a = 0; a < adj[x].size(); a++) {
		if(!visited[adj[x][a]]) {
			//cout << "Moving from " << x << " to " << adj[x][a] << '\n';
			children += happy(adj[x][a], l+1);
		}
	}
	inc[x-1] = l - children + 1;
	//cout << x << ": " << inc[x-1] << '\n';
	return children;
}

int main() {
	long long int v, k, x, y, ans=0;
	cin >> v >> k;
	for(int a = 1; a < v; a++) {
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	happy(1, 0);
	sort(inc, inc+v, greater<int>());
	for(int a = 0; a < k; a++) {
		ans += (long long int)(inc[a]);
		//cout << a << ":: " << ans << '\n';
	}
	cout << ans << '\n';
}