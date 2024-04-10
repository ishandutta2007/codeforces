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

vector<int> e[100005];
int clr[100005];
int n;

int cr = 0;
int xc[100005];

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			if (clr[x] != clr[y]) {
				cr++;
				xc[x]++;
				xc[y]++;
			}
			dfs(y, x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		cin >> clr[i];
	}

	dfs(1, 1);

	for (int i=1; i<=n; i++) {
		if (xc[i] == cr) {
			cout << "YES\n" << i;
			return 0;
		}
	}

	cout << "NO\n";


}