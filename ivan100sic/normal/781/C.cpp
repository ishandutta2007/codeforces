#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int vis[200005];
int n, m, k;

vector<int> e[200005];
int b[400005], bb;

void dfs(int x) {
	b[bb++] = x;
	vis[x] = 1;
	int c = 0;
	for (int y : e[x]) {
		if (!vis[y]) {
			dfs(y);
			b[bb++] = x;
			c++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1);

	for (int i=0; i<k; i++) {
		int start = 1ll*bb*i/k;
		int end = 1ll*bb*(i+1) / k;

		cout << end-start;
		for (int j=start; j<end; j++) {
			cout << ' ' << b[j];
		}
		cout << '\n';
	}
}