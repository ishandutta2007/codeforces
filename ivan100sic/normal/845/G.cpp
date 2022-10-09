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

// Why is my previous submission (29903675) "skipped"?

vector<pair<int, int>> e[100005];
int n, m;

int path_xor[100005];
int cycles[100005], cc;
bool visited[100005];

void dfs(int x) {
	visited[x] = true;
	for (auto p : e[x]) {
		int y = p.first;
		int w = p.second;

		if (visited[y]) {
			cycles[++cc] = path_xor[y] ^ path_xor[x] ^ w;
		} else {
			path_xor[y] = path_xor[x] ^ w;
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u != v) {
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		} else {
			e[u].push_back({v, w});
		}
	}

	dfs(1);
	int val = path_xor[n];

	for (int i=29; i>=0; i--) {
		// uzimamo ovaj bit?
		bool take = true;
		if ((val & (1<<i)) == 0) {
			take = false;
		}

		// uzimamo.
		int pos = 0;
		for (int j=1; j<=cc; j++) {
			if ((cycles[j] >> i) == 1) {
				pos = j;
			}
		}

		if (pos) {
			int tmp = cycles[pos];
			if (take) val ^= tmp;
			for (int j=1; j<=cc; j++) {
				if (j != pos && ((cycles[j] >> i) == 1)) {
					cycles[j] ^= tmp;
				}
			}
		}
	}

	cout << val;

}