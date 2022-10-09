#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> e[1005];
int n, m, k;
int c[1005];

int govs, edges, nodes;
bool v[1005];

int ungovs = 0, maxgov = 0;
int unedges = 0;

int gov_minedges;

void dfs(int x) {
	govs += c[x];
	edges += e[x].size();
	nodes += 1;
	v[x] = true;

	for (int y : e[x]) {
		if (!v[y]) {
			dfs(y);
		}
	}
}


int main() {
	cin >> n >> m >> k;
	for (int i=1; i<=k; i++) {
		int x;
		cin >> x;
		c[x] = 1;
	}
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			govs = 0;
			edges = 0;
			nodes = 0;
			dfs(i);

			if (govs == 0) {
				ungovs += nodes;
				unedges += edges/2;
			} else {
				maxgov = max(maxgov, nodes);
				gov_minedges += nodes*(nodes-1)/2 - edges/2;
			}
		}
	}

	cout << (maxgov * ungovs + (ungovs*(ungovs-1))/2 - unedges + gov_minedges) << '\n';

}