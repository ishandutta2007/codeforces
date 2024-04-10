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

int n;
vector<int> e[200005];
int c[200005], k;

void dfs(int x, int p, int banned, int dennab) {
	int cl = 1;

	// cerr << x << ' ' << p << ' ' << banned << ' ' << dennab << '\n';

	for (int y : e[x]) {
		if (y != p) {
			while (cl == banned || cl == dennab) {
				cl++;
			}
			c[y] = cl++;
			dfs(y, x, c[y], c[x]);
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

	int maxdeg = 1, x = 0;
	for (int i=1; i<=n; i++) {
		if (e[i].size() > maxdeg) {
			maxdeg = e[i].size();
			x = i;
		}
	}

	k = maxdeg + 1;

	c[x] = 1;
	dfs(x, x, 1, 0);

	cout << k << '\n';
	for (int i=1; i<=n; i++) {
		cout << c[i] << ' ';
	}
}