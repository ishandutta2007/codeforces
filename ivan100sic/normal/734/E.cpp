#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int b[200005];
vector<int> e[200005];

int dst, nod;

void dfs(int x, int p, int depth) {
	if (depth > dst) {
		dst = depth;
		nod = x;
	}
	for (int y : e[x]) {
		if (y != p) {
			int d = depth + (b[x] ^ b[y]);
			dfs(y, x, d);
		}
	}
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dst = -1;
	dfs(1, 1, 0);
	int x = nod;
	dst = -1;
	dfs(x, x, 0);

	cout << (dst+1)/2;
}